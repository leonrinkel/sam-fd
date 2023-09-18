#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <stdint.h>

#define APP_OFFSET 0x1000 /* Where the application is in flash */
#define PAGE_SIZE 256 /* Flash is organized in rows of 1024 bytes */
#define NUM_PAGES 256 /* There are 256 pages */
#define START_PAGE (APP_OFFSET / PAGE_SIZE) /* Only allow writing from here */

/** Structure of a write command */
struct write_cmd
{
	uint32_t page; /** Page number to write */
	uint8_t data[PAGE_SIZE]; /** Data to write */
	uint32_t crc; /** CRC32 of command */
};

/** Structure of a boot command */
struct boot_cmd
{
	uint8_t mode; /** Requested bootmode */
};

enum cmd_type
{
	write_cmd_type = 0x42,
	boot_cmd_type = 0x69,
};

struct flasher_cmd
{
	enum cmd_type type;
	union
	{
		struct write_cmd write;
		struct boot_cmd boot;
	} typed;
};

#endif /* PROTOCOL_H */
