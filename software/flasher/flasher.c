#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "crc.h"
#include "protocol.h"
#include "serial.h"

int main(int argc, char* argv[])
{
	int ret = EXIT_SUCCESS; /** Exit code to return */

	char* arg_port; /** Serial port to open */
	char* arg_file; /** Path to flash file */
	char* arg_version; /** Verion number */

	int portfd = 0; /** File descriptor of serial port */
	FILE* file = NULL; /** File descriptor of bin file to flash */
	struct flasher_cmd cmd; /** Command to transmit */
	size_t file_nread; /** Number of bytes read from flash file */
	uint8_t cmd_resp; /** Response read from serial port */
	uint16_t version_no = 0; /** Version number */
	long length_to_flash; /** Number of bytes to flash */

	/* Parse CLI args */
	if (argc < 3 || argc > 4)
	{
		fprintf(stderr,
			"usage: flasher port file <version>\n"
			"e.g.: ./flasher /dev/ttyUSB0 application.bin\n"
			"or: flasher.exe COM1 application.bin\n"
		);
		ret = EXIT_FAILURE;
		goto cleanup;
	}
	arg_port = argv[1];
	arg_file = argv[2];

	/* Parse version number */
	if (argc == 4)
	{
		arg_version = argv[3];
		version_no = atoi(arg_version);
	}

	if (!serial_open(arg_port))
	{
		ret = EXIT_FAILURE;
		goto cleanup;
	}

	/* Open file to flash */
	file = fopen(arg_file, "rb");
	if (file == NULL)
	{
		perror("fopen()");
		ret = EXIT_FAILURE;
		goto cleanup;
	}

	/* Determine file size */
	fseek(file, 0, SEEK_END);
	length_to_flash = ftell(file);
	rewind(file);
	/* Plus page padding */
	if (length_to_flash % PAGE_SIZE > 0)
	{
		length_to_flash +=
			PAGE_SIZE - (length_to_flash % PAGE_SIZE);
	}

	/* Send start command */
	cmd.type = start_cmd_type;
	cmd.typed.start.length = length_to_flash;
	cmd.typed.start.version = version_no;
	if (!serial_write((uint8_t*) &cmd, sizeof(struct flasher_cmd)))
	{
		ret = EXIT_FAILURE;
		goto cleanup;
	}

	/* Check response to start command */
	if (!serial_read((uint8_t*) &cmd_resp, sizeof(uint8_t)))
	{
		ret = EXIT_FAILURE;
		goto cleanup;
	}

	printf("flashing...");
	fflush(stdout);

	/* Iterate pages to write */
	for (int page = START_PAGE; page < NUM_PAGES; page++)
	{
		/* Read page from file */
		cmd.typed.write.page = page;
		file_nread = fread(cmd.typed.write.data, 1, PAGE_SIZE, file);

		/* Pad partial page */
		if (file_nread < PAGE_SIZE)
		{
			memset(cmd.typed.write.data + file_nread,
				0, PAGE_SIZE - file_nread);
		}

		/* Fill command args */
		cmd.type = write_cmd_type;
		cmd.typed.write.page = page;
		cmd.typed.write.crc = 0;
		cmd.typed.write.crc =
			crc32((void*) &cmd.typed.write, sizeof(struct write_cmd));

		if (!serial_write((uint8_t*) &cmd, sizeof(struct flasher_cmd)))
		{
			ret = EXIT_FAILURE;
			goto cleanup;
		}

		if (!serial_read((uint8_t*) &cmd_resp, sizeof(uint8_t)))
		{
			ret = EXIT_FAILURE;
			goto cleanup;
		}

		/* Check response */
		if (cmd_resp != 0x42)
		{
			fprintf(stderr, "invalid response 0x%02x\n", cmd_resp);
			ret = EXIT_FAILURE;
			goto cleanup;
		}

		printf(".");
		fflush(stdout);

		if (file_nread < PAGE_SIZE)
		{
			/* End of file */
			break;
		}
	}

	/* Send stop command */
	cmd.type = stop_cmd_type;
	if (!serial_write((uint8_t*) &cmd, sizeof(struct flasher_cmd)))
	{
		ret = EXIT_FAILURE;
		goto cleanup;
	}

	/* Check response to stop command */
	if (!serial_read((uint8_t*) &cmd_resp, sizeof(uint8_t)))
	{
		ret = EXIT_FAILURE;
		goto cleanup;
	}

	printf("done\nbooting...");
	fflush(stdout);

	cmd.type = boot_cmd_type;
	cmd.typed.boot.mode = 0x42; /* Does not matter yet */
	if (!serial_write((uint8_t*) &cmd, sizeof(struct flasher_cmd)))
	{
		ret = EXIT_FAILURE;
		goto cleanup;
	}

	if (!serial_read((uint8_t*) &cmd_resp, sizeof(uint8_t)))
	{
		ret = EXIT_FAILURE;
		goto cleanup;
	}

	/* Check response */
	if (cmd_resp != 0x42)
	{
		fprintf(stderr, "invalid response 0x%02x\n", cmd_resp);
		ret = EXIT_FAILURE;
		goto cleanup;
	}

	printf("done\n");

cleanup:

	serial_close();

	/* Close flash file */
	if (file != NULL)
	{
		fclose(file);
	}

	return ret;
}
