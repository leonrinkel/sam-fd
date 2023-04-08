#include <atmel_start.h>

#define APP_OFFSET 0x1000 /* Where the application is in flash */
#define PAGE_SIZE 256 /* Flash is organized in rows of 1024 bytes */
#define NUM_PAGES 256 /* There are 256 pages */
#define START_PAGE (APP_OFFSET / PAGE_SIZE) /* Only allow writing from here */

static struct io_descriptor* serial;

void run_flasher(void);
void run_application(void);

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	/* Setup UART and CRC */
	usart_sync_get_io_descriptor(&USART_0, &serial);
	usart_sync_enable(&USART_0);
	crc_sync_enable(&CRC_0);

	/* Determine boot mode */
	if (gpio_get_pin_level(BOOTMODE) == false)
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

/** Structure of a write command */
struct write_cmd
{
	uint32_t page; /** Page number to write */
	uint8_t data[PAGE_SIZE]; /** Data to write */
	uint32_t crc; /** CRC32 of command */
};

void run_flasher(void)
{
	int32_t nread; /** Number of bytes read from serial */
	struct write_cmd cmd; /** Write command read from serial */
	uint32_t crc_from_cmd; /** CRC read from serial */
	uint32_t calculated_crc; /** CRC calculated from command */

	while (true)
	{
		/* Read command */
		nread = io_read(serial, (uint8_t*) &cmd, sizeof(struct write_cmd));
		if (nread != sizeof(struct write_cmd))
		{
			continue;
		}

		/* Check page parameter */
		if (
			cmd.page < START_PAGE ||
			cmd.page >= NUM_PAGES
		)
		{
			goto failure;
		}

		/* Calculate CRC */

		crc_from_cmd = cmd.crc;
		cmd.crc = 0;

		calculated_crc = 0xFFFFFFFF;
		crc_sync_crc32(&CRC_0, (uint32_t*) &cmd,
			sizeof(struct write_cmd) / sizeof(uint32_t), &calculated_crc);
		calculated_crc ^= 0xFFFFFFFF;

		if (calculated_crc != crc_from_cmd)
		{
			/* Incorrect CRC */
			goto failure;
		}

		/* Write flash */
		flash_write(&FLASH_0, cmd.page * PAGE_SIZE, cmd.data, PAGE_SIZE);

		/* Successful response */
		io_write(serial, (uint8_t[]) { 0x42 }, 1);
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
