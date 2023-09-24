/* SPDX-License-Identifier: MIT */
/**
 * \file      inc/reg/scb.h
 * \brief     Definitions regarding SCB registers structure
 * \copyright Copyright (c) 2023 Leon Rinkel
 */

#ifndef SAMFD_REG_SCB_H
#define SAMFD_REG_SCB_H

#include <stdint.h>

/** \brief SCB registers base address */
#define SCB_ADDR 0xE000ED00u

/** \name SCB VTOR register */
/**@{*/

/** \brief SCB VTOR register address offset */
#define SCB_VTOR_OFF 0x08u

/** \brief SCB VTOR register address */
#define SCB_VTOR_ADDR (SCB_ADDR + SCB_VTOR_OFF)

/** \brief SCB VTOR register */
#define SCB_VTOR (*((volatile uint32_t*) SCB_VTOR_ADDR))

/**@}*/

#endif /* SAMFD_REG_SCB_H */
