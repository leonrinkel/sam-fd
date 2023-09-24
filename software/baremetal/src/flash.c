/* SPDX-License-Identifier: MIT */
/**
 * \file      src/flash.c
 * \brief     Implementation of the FLASH driver
 * \copyright Copyright (c) 2023 Leon Rinkel
 */

#include <stdbool.h>
#include <stdint.h>

#include <drv/flash.h>

#include <reg/nvmctrl.h>

bool flash_erase_row(uint32_t addr)
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
		(addr / 2) << NVMCTRL_ADDR_ADDR_OFF;

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
