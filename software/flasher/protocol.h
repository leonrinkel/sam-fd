#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <stdint.h>

#define APP_OFFSET 0x1000 /* Where the application is in flash */
#define PAGE_SIZE 256 /* Flash is organized in rows of 1024 bytes */
#define NUM_PAGES 256 /* There are 256 pages */
#define START_PAGE (APP_OFFSET / PAGE_SIZE) /* Only allow writing from here */

/** Structure of a start command */
struct start_cmd
{
	uint32_t length; /** Number of bytes to flash */
	uint16_t version; /** Application version number */
};

/** Structure of a write command */
struct write_cmd
{
	uint32_t page; /** Page number to write */
	uint8_t data[PAGE_SIZE]; /** Data to write */
	uint32_t crc; /** CRC32 of command */
};

/** Structure of a stop command */
struct stop_cmd
{
	uint8_t idk;
	uint8_t whatever;
};

/** Structure of a boot command */
struct boot_cmd
{
	uint8_t mode; /** Requested bootmode */
};

enum cmd_type
{
	start_cmd_type = 0x13,
	write_cmd_type = 0x42,
	stop_cmd_type = 0x37,
	boot_cmd_type = 0x69,
};

struct flasher_cmd
{
	enum cmd_type type;
	union
	{
		struct start_cmd start;
		struct write_cmd write;
		struct stop_cmd stop;
		struct boot_cmd boot;
	} typed;
};

#endif /* PROTOCOL_H */
