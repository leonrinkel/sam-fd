/* SPDX-License-Identifier: MIT */
/**
 * \file      src/drv/flash.c
 * \brief     Implementation of the FLASH driver
 * \copyright Copyright (c) 2023 Leon Rinkel
 */

#include <stdbool.h>
#include <stdint.h>

#include <drv/flash.h>

#include <reg/nvmctrl.h>

bool flash_erase_row(uint32_t row_addr)
{
	/* Wait while not ready */
	while (!NVMCTRL_INTFLAG.B.READY);

	/* Clear status flags */
	NVMCTRL_STATUS.U =
		NVMCTRL_STATUS_LOAD_MSK |
		NVMCTRL_STATUS_PROGE_MSK |
		NVMCTRL_STATUS_LOCKE_MSK |
		NVMCTRL_STATUS_NVME_MSK;

	/* Write address of row to erase */
	NVMCTRL_ADDR.U =
		(row_addr / 2) << NVMCTRL_ADDR_ADDR_OFF;

	/* Execute erase row command */
	NVMCTRL_CTRLA.U =
		(0x02u << NVMCTRL_CTRLA_CMD_OFF) |
		(0xA5u << NVMCTRL_CTRLA_CMDEX_OFF);

	/* Wait while not ready */
	while (!NVMCTRL_INTFLAG.B.READY);

	/* Check for errors */
	return (
		!NVMCTRL_STATUS.B.PROGE &&
		!NVMCTRL_STATUS.B.LOCKE &&
		!NVMCTRL_STATUS.B.NVME
	);
}

bool flash_write_page(uint32_t page_addr, const uint8_t* buffer)
{
	uint32_t temp_addr = page_addr / 2;

	/* Wait while not ready */
	while (!NVMCTRL_INTFLAG.B.READY);

	/* Execute page buffer clear command */
	NVMCTRL_CTRLA.U =
		(0x44u << NVMCTRL_CTRLA_CMD_OFF) |
		(0xA5u << NVMCTRL_CTRLA_CMDEX_OFF);

	/* Wait while not ready */
	while (!NVMCTRL_INTFLAG.B.READY);

	/* Clear status flags */
	NVMCTRL_STATUS.U =
		NVMCTRL_STATUS_LOAD_MSK |
		NVMCTRL_STATUS_PROGE_MSK |
		NVMCTRL_STATUS_LOCKE_MSK |
		NVMCTRL_STATUS_NVME_MSK;

	/* Write page buffer */
	for (uint8_t i = 0; i < FLASH_PAGE_SIZE; i += 2) {
		*((volatile uint16_t*) (temp_addr++ * 2)) =
			(buffer[i + 0] << 0u) |
			(buffer[i + 1] << 8u);
	}

	/* Wait while not ready */
	while (!NVMCTRL_INTFLAG.B.READY);

	/* Write address of page to write */
	NVMCTRL_ADDR.U =
		(page_addr / 2) << NVMCTRL_ADDR_ADDR_OFF;

	/* Execute page write command */
	NVMCTRL_CTRLA.U =
		(0x04u << NVMCTRL_CTRLA_CMD_OFF) |
		(0xA5u << NVMCTRL_CTRLA_CMDEX_OFF);

	/* Wait while not ready */
	while (!NVMCTRL_INTFLAG.B.READY);

	/* Check for errors */
	return (
		!NVMCTRL_STATUS.B.PROGE &&
		!NVMCTRL_STATUS.B.LOCKE &&
		!NVMCTRL_STATUS.B.NVME
	);
}

bool flash_write_row(uint32_t row_addr, const uint8_t* buffer)
{
	bool ret;

	for (uint8_t page = 0; page < FLASH_PAGES_PER_ROW; page++)
	{
		ret = flash_write_page(
			row_addr + page * FLASH_PAGE_SIZE,
			buffer + page * FLASH_PAGE_SIZE
		);
		if (!ret)
		{
			return false;
		}
	}

	return true;
}
