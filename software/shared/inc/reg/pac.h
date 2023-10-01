/* SPDX-License-Identifier: MIT */
/**
 * \file      inc/reg/pac.h
 * \brief     Definitions regarding PAC registers structure
 * \copyright Copyright (c) 2023 Leon Rinkel
 */

#ifndef SAMFD_REG_PAC_H
#define SAMFD_REG_PAC_H

#include <stdint.h>

/** \brief PAC registers base address */
#define PAC_BASE_ADDR 0x40000000u

/** \name PAC WRCTRL register */
/**@{*/

/** \brief PAC WRCTRL register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Peripheral identifier */
		uint32_t PERID:16;
		/** \brief Peripheral access control key */
		uint32_t KEY:8;
		/** \brief Reserved */
		uint32_t :8;
	} B;
} pac_wrctrl_t;

/** \brief PAC WRCTRL register address offset */
#define PAC_WRCTRL_OFF 0x00u

/** \brief PAC WRCTRL register address */
#define PAC_WRCTRL_ADDR (PAC_BASE_ADDR + PAC_WRCTRL_OFF)

/** \brief PAC WRCTRL register */
#define PAC_WRCTRL (*((volatile pac_wrctrl_t*) PAC_WRCTRL_ADDR))

/** \brief PAC WRCTRL.PERID bit offset */
#define PAC_WRCTRL_PERID_OFF 0u
/** \brief PAC WRCTRL.PERID bit mask */
#define PAC_WRCTRL_PERID_MSK (0xFFFFu << PAC_WRCTRL_PERID_OFF)

/** \brief PAC WRCTRL.KEY bit offset */
#define PAC_WRCTRL_KEY_OFF 16u
/** \brief PAC WRCTRL.KEY bit mask */
#define PAC_WRCTRL_KEY_MSK (0xFFu << PAC_WRCTRL_KEY_OFF)

/**@}*/

#endif /* SAMFD_REG_PAC_H */
