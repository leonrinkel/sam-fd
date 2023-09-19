#include <stdint.h>
#include <stdbool.h>

#include <atmel_start.h>

#include "protocol.h"

#define HEADER_OFFSET 0x0F00u /* Where the application header is in flash */
#define HEADER_MAGIC 0x13374269u /* Magic number to mark valid header */

static struct io_descriptor* serial;

void try_booting(void);
void run_flasher(void);
void run_application(void);

/** Structure of the application header */
union app_header
{
	uint8_t bytes[PAGE_SIZE];
	struct
	{
		uint32_t magic; /** Magic number to mark valid header */
		uint8_t valid; /** Whether application is valid or not */
		uint32_t crc; /** Application CRC */
		uint32_t length; /** Application length */
		uint16_t version; /** Application version */
	} data;
};

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	/* Setup UART and CRC */
	usart_sync_get_io_descriptor(&USART_0, &serial);
	usart_sync_enable(&USART_0);
	crc_sync_enable(&CRC_0);

	/* Letzzzz goooooo */
	try_booting();
}

void try_booting(void)
{
	volatile union app_header* current_header =
		(union app_header*) HEADER_OFFSET;
	union app_header header_to_write;

	/* Check if application header initialized */
	if (current_header->data.magic != HEADER_MAGIC)
	{
		/* Initialize with default values */
		header_to_write.data.magic = HEADER_MAGIC;
		header_to_write.data.valid = 0;
		header_to_write.data.crc = 0;
		header_to_write.data.length = 0;
		header_to_write.data.version = 0;
		flash_write(&FLASH_0, HEADER_OFFSET,
			header_to_write.bytes, PAGE_SIZE);
	}

	// TODO Check application integrity

	/* Determine boot mode */
	if (
		/* Bootmode set via pin or */
		gpio_get_pin_level(BOOTMODE) == false ||
		/* Application is invalid */
		!(current_header->data.valid)
	)
	{
		/* Continue with flasher */
		run_flasher();
	}
	else
	{
		/* Continue with application */
		run_application();
	}
}

void run_flasher(void)
{
	int32_t nread; /** Number of bytes read from serial */
	struct flasher_cmd cmd; /** Command read from serial */
	uint32_t crc_from_cmd; /** CRC read from serial */
	uint32_t calculated_crc; /** CRC calculated from command */
	bool flashing = false; /** Whether we are flashing right now */
	union app_header header_to_write; /** Header prepared to write */
	uint32_t bytes_flashed; /** Number of bytes already flashed */
	/** Pointer to actual current app header */
	volatile union app_header* current_header =
		(union app_header*) HEADER_OFFSET;

	while (true)
	{
		/* Read command */
		nread = io_read(serial, (uint8_t*) &cmd, sizeof(struct flasher_cmd));
		if (nread != sizeof(struct flasher_cmd))
		{
			continue;
		}

		switch (cmd.type)
		{
		/* Handle start command */
		case start_cmd_type:
		{
			if (flashing)
			{
				/* Already started */
				goto failure;
			}

			/* Intentionally invalidate application */
			header_to_write.data.magic = HEADER_MAGIC;
			header_to_write.data.valid = 0;
			header_to_write.data.crc = 0;
			header_to_write.data.length = cmd.typed.start.length;
			header_to_write.data.version = cmd.typed.start.version;
			flash_write(&FLASH_0, HEADER_OFFSET,
				header_to_write.bytes, PAGE_SIZE);

			/* Can start flashing now */
			bytes_flashed = 0;
			flashing = true;

			/* Successful response */
			io_write(serial, (uint8_t[]) { 0x42 }, 1);
		}
			break;

		/* Handle write command */
		case write_cmd_type:
		{
			if (!flashing)
			{
				/* Not yet started */
				goto failure;
			}

			/* Check page parameter */
			if (
				cmd.typed.write.page < START_PAGE ||
				cmd.typed.write.page >= NUM_PAGES
			)
			{
				goto failure;
			}

			/* Calculate CRC */

			crc_from_cmd = cmd.typed.write.crc;
			cmd.typed.write.crc = 0;

			calculated_crc = 0xFFFFFFFF;
				crc_sync_crc32(&CRC_0, (uint32_t*) &cmd.typed.write,
				sizeof(struct write_cmd) / sizeof(uint32_t), &calculated_crc);
			calculated_crc ^= 0xFFFFFFFF;

			if (calculated_crc != crc_from_cmd)
			{
				/* Incorrect CRC */
				goto failure;
			}

			/* Write flash */
			flash_write(&FLASH_0, cmd.typed.write.page * PAGE_SIZE,
				cmd.typed.write.data, PAGE_SIZE);
			bytes_flashed += PAGE_SIZE;

			/* Successful response */
			io_write(serial, (uint8_t[]) { 0x42 }, 1);
		}
			break;

		/* Handle stop command */
		case stop_cmd_type:
		{
			if (!flashing)
			{
				/* Not yet started */
				goto failure;
			}

			if (bytes_flashed != current_header->data.length)
			{
				/* Flashed less than expected */
				goto failure;
			}

			/* Mark application valid */
			header_to_write.data.magic = HEADER_MAGIC;
			header_to_write.data.valid = 1;
			header_to_write.data.crc = 0; // TODO Fill app CRC
			header_to_write.data.length = current_header->data.length;
			header_to_write.data.version = current_header->data.version;
			flash_write(&FLASH_0, HEADER_OFFSET,
				header_to_write.bytes, PAGE_SIZE);

			/* Dont allow flashing anymore */
			flashing = false;

			/* Successful response */
			io_write(serial, (uint8_t[]) { 0x42 }, 1);
		}
			break;

		/* Handle boot command */
		case boot_cmd_type:
		{
			if (flashing)
			{
				/* Can't boot while still flashing */
				goto failure;
			}

			/* Successful response */
			io_write(serial, (uint8_t[]) { 0x42 }, 1);

			/* Bootmode is not actually used yet */
			try_booting();
		}
			break;

		default:
			/* Unknown command type */
			goto failure;
		}
	}

failure:

	/* Error response */
	io_write(serial, (uint8_t[]) { 0xff }, 1);

	/* Hang */
	while (true)
	{
	}
}

void run_application(void)
{
	/* Determine addresses */
	uint32_t app_address = APP_OFFSET;
	uint32_t app_stack = *((uint32_t*) (app_address + 0x0));
	uint32_t app_reset = *((uint32_t*) (app_address + 0x4));

	/* Jump to application */
	__set_MSP(app_stack);
	((int(*)(void)) app_reset)();

	/* This should never run */
	while (true)
	{
	}
}
