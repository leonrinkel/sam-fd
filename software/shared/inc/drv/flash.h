/* SPDX-License-Identifier: MIT */
/**
 * \file      inc/drv/flash.h
 * \brief     Declaration related to the FLASH driver
 * \copyright Copyright (c) 2023 Leon Rinkel
 */

#ifndef SAMFD_DRV_FLASH_H
#define SAMFD_DRV_FLASH_H

#include <stdbool.h>
#include <stdint.h>

#define FLASH_PAGE_SIZE 64u
#define FLASH_NUM_PAGES 1024u
#define FLASH_PAGES_PER_ROW 4u

bool flash_erase_row(uint32_t row_addr);

bool flash_write_page(uint32_t page_addr, const uint8_t* buffer);

bool flash_write_row(uint32_t row_addr, const uint8_t* buffer);

#endif /* SAMFD_DRV_FLASH_H */
