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

bool flash_erase_row(uint32_t addr);

#endif /* SAMFD_DRV_FLASH_H */
