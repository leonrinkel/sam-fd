/* SPDX-License-Identifier: MIT */
/**
 * \file      inc/reg/syst.h
 * \brief     Definitions regarding SYST registers structure
 * \copyright Copyright (c) 2023 Leon Rinkel
 */

#ifndef SAMFD_REG_SYST_H
#define SAMFD_REG_SYST_H

#include <stdint.h>

/** \brief SYST registers base address */
#define SYST_BASE_ADDR 0xE000E010u

/** \name SYST CSR register */
/**@{*/

/** \brief SYST CSR register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Enables the counter */
		uint32_t ENABLE:1;
		/** \brief Enables SysTick exception request */
		uint32_t TICKINT:1;
		/** \brief Selects the SysTick timer clock source */
		uint32_t CLKSOURCE:1;
		/** \brief Reserved */
		uint32_t :13;
		/** \brief Returns 1 if timer counted to 0 since the last read of this register */
		uint32_t COUNTFLAG:1;
		/** \brief Reserved */
		uint32_t :15;
	} B;
} syst_csr_t;

/** \brief SYST CSR register address offset */
#define SYST_CSR_OFF 0x00u

/** \brief SYST CSR register address */
#define SYST_CSR_ADDR (SYST_BASE_ADDR + SYST_CSR_OFF)

/** \brief SYST CSR register */
#define SYST_CSR (*((volatile syst_csr_t*) SYST_CSR_ADDR))

/** \brief SYST CSR.ENABLE bit offset */
#define SYST_CSR_ENABLE_OFF 0u
/** \brief SYST CSR.ENABLE bit mask */
#define SYST_CSR_ENABLE_MSK (0x1u << SYST_CSR_ENABLE_OFF)

/** \brief SYST CSR.TICKINT bit offset */
#define SYST_CSR_TICKINT_OFF 1u
/** \brief SYST CSR.TICKINT bit mask */
#define SYST_CSR_TICKINT_MSK (0x1u << SYST_CSR_TICKINT_OFF)

/** \brief SYST CSR.CLKSOURCE bit offset */
#define SYST_CSR_CLKSOURCE_OFF 2u
/** \brief SYST CSR.CLKSOURCE bit mask */
#define SYST_CSR_CLKSOURCE_MSK (0x1u << SYST_CSR_CLKSOURCE_OFF)

/** \brief SYST CSR.COUNTFLAG bit offset */
#define SYST_CSR_COUNTFLAG_OFF 16u
/** \brief SYST CSR.COUNTFLAG bit mask */
#define SYST_CSR_COUNTFLAG_MSK (0x1u << SYST_CSR_COUNTFLAG_OFF)

/**@}*/

/** \name SYST RVR register */
/**@{*/

/** \brief SYST RVR register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Value to load into the SYST_CVR when the counter is enabled and when it reaches 0 */
		uint32_t RELOAD:24;
		/** \brief Reserved */
		uint32_t :8;
	} B;
} syst_rvr_t;

/** \brief SYST RVR register address offset */
#define SYST_RVR_OFF 0x04u

/** \brief SYST RVR register address */
#define SYST_RVR_ADDR (SYST_BASE_ADDR + SYST_RVR_OFF)

/** \brief SYST RVR register */
#define SYST_RVR (*((volatile syst_rvr_t*) SYST_RVR_ADDR))

/** \brief SYST RVR.RELOAD bit offset */
#define SYST_RVR_RELOAD_OFF 0u
/** \brief SYST RVR.RELOAD bit mask */
#define SYST_RVR_RELOAD_MSK (0xFFFFFFu << SYST_RVR_RELOAD_OFF)

/**@}*/

#endif /* SAMFD_REG_SYST_H */
