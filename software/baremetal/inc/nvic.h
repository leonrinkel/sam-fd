/* SPDX-License-Identifier: MIT */
/**
 * \file      inc/nvic.h
 * \brief     Definitions regarding NVIC registers structure
 * \copyright Copyright (c) 2023 Leon Rinkel
 */

#ifndef SAMFD_NVIC_H
#define SAMFD_NVIC_H

#include <stdint.h>

/** \brief NVIC registers base address */
#define NVIC_ADDR 0xE000E100u

/** \name NVIC ISER register */
/**@{*/

/** \brief NVIC ISER register address offset */
#define NVIC_ISER_OFF 0x000u

/** \brief NVIC ISER register address */
#define NVIC_ISER_ADDR (NVIC_ADDR + NVIC_ISER_OFF)

/** \brief NVIC ISER register */
#define NVIC_ISER (*((volatile uint32_t*) NVIC_ISER_ADDR))

/**@}*/

#endif /* SAMFD_NVIC_H */
