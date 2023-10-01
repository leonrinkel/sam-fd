/* SPDX-License-Identifier: MIT */
/**
 * \file      inc/reg/dsu.h
 * \brief     Definitions regarding DSU registers structure
 * \copyright Copyright (c) 2023 Leon Rinkel
 */

#ifndef SAMFD_REG_DSU_H
#define SAMFD_REG_DSU_H

#include <stdint.h>

/** \brief DSU registers base address */
#define DSU_BASE_ADDR 0x41002000u

/** \name DSU CTRL register */
/**@{*/

/** \brief DSU CTRL register structure */
typedef union
{
	/** \brief Unsigned access */
	uint8_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Software reset */
		uint8_t SWRST:1;
		/** \brief Reserved */
		uint8_t :1;
		/** \brief 32-bit cyclic redundancy check */
		uint8_t CRC:1;
		/** \brief Memory built-in self-test */
		uint8_t MBIST:1;
		/** \brief Chip erase */
		uint8_t CE:1;
		/** \brief Reserved */
		uint8_t :3;
	} B;
} dsu_ctrl_t;

/** \brief DSU CTRL register address offset */
#define DSU_CTRL_OFF 0x00u

/** \brief DSU CTRL register address */
#define DSU_CTRL_ADDR (DSU_BASE_ADDR + DSU_CTRL_OFF)

/** \brief DSU CTRL register */
#define DSU_CTRL (*((volatile dsu_ctrl_t*) DSU_CTRL_ADDR))

/** \brief DSU CTRL.SWRST bit offset */
#define DSU_CTRL_SWRST_OFF 0u
/** \brief DSU CTRL.SWRST bit mask */
#define DSU_CTRL_SWRST_MSK (0x1u << DSU_CTRL_SWRST_OFF)

/** \brief DSU CTRL.CRC bit offset */
#define DSU_CTRL_CRC_OFF 2u
/** \brief DSU CTRL.CRC bit mask */
#define DSU_CTRL_CRC_MSK (0x1u << DSU_CTRL_CRC_OFF)

/** \brief DSU CTRL.MBIST bit offset */
#define DSU_CTRL_MBIST_OFF 3u
/** \brief DSU CTRL.MBIST bit mask */
#define DSU_CTRL_MBIST_MSK (0x1u << DSU_CTRL_MBIST_OFF)

/** \brief DSU CTRL.CE bit offset */
#define DSU_CTRL_CE_OFF 4u
/** \brief DSU CTRL.CE bit mask */
#define DSU_CTRL_CE_MSK (0x1u << DSU_CTRL_CE_OFF)

/**@}*/

/** \name DSU STATUSA register */
/**@{*/

/** \brief DSU STATUSA register structure */
typedef union
{
	/** \brief Unsigned access */
	uint8_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Done */
		uint8_t DONE:1;
		/** \brief CPU reset phase extension */
		uint8_t CRSTEXT:1;
		/** \brief Bus error */
		uint8_t BERR:1;
		/** \brief Failure */
		uint8_t FAIL:1;
		/** \brief Protection error */
		uint8_t PERR:1;
		/** \brief Reserved */
		uint8_t :3;
	} B;
} dsu_statusa_t;

/** \brief DSU STATUSA register address offset */
#define DSU_STATUSA_OFF 0x01u

/** \brief DSU STATUSA register address */
#define DSU_STATUSA_ADDR (DSU_BASE_ADDR + DSU_STATUSA_OFF)

/** \brief DSU STATUSA register */
#define DSU_STATUSA (*((volatile dsu_statusa_t*) DSU_STATUSA_ADDR))

/** \brief DSU STATUSA.DONE bit offset */
#define DSU_STATUSA_DONE_OFF 0u
/** \brief DSU STATUS.DONE bit mask */
#define DSU_STATUSA_DONE_MSK (0x1u << DSU_STATUSA_DONE_OFF)

/** \brief DSU STATUSA.CRSTEXT bit offset */
#define DSU_STATUSA_CRSTEXT_OFF 1u
/** \brief DSU STATUS.CRSTEXT bit mask */
#define DSU_STATUSA_CRSTEXT_MSK (0x1u << DSU_STATUSA_CRSTEXT_OFF)

/** \brief DSU STATUSA.BERR bit offset */
#define DSU_STATUSA_BERR_OFF 2u
/** \brief DSU STATUS.BERR bit mask */
#define DSU_STATUSA_BERR_MSK (0x1u << DSU_STATUSA_BERR_OFF)

/** \brief DSU STATUSA.FAIL bit offset */
#define DSU_STATUSA_FAIL_OFF 3u
/** \brief DSU STATUS.FAIL bit mask */
#define DSU_STATUSA_FAIL_MSK (0x1u << DSU_STATUSA_FAIL_OFF)

/** \brief DSU STATUSA.PERR bit offset */
#define DSU_STATUSA_PERR_OFF 4u
/** \brief DSU STATUS.PERR bit mask */
#define DSU_STATUSA_PERR_MSK (0x1u << DSU_STATUSA_PERR_OFF)

/**@}*/

/** \name DSU ADDR register */
/**@{*/

/** \brief DSU ADDR register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Access mode */
		uint32_t AMOD:2;
		/** \brief Address */
		uint32_t ADDR:30;
	} B;
} dsu_addr_t;

/** \brief DSU ADDR register address offset */
#define DSU_ADDR_OFF 0x04u

/** \brief DSU ADDR register address */
#define DSU_ADDR_ADDR (DSU_BASE_ADDR + DSU_ADDR_OFF)

/** \brief DSU ADDR register */
#define DSU_ADDR (*((volatile dsu_addr_t*) DSU_ADDR_ADDR))

/** \brief DSU ADDR.AMOD bit offset */
#define DSU_ADDR_AMOD_OFF 0u
/** \brief DSU ADDR.AMOD bit mask */
#define DSU_ADDR_AMOD_MSK (0x3u << DSU_ADDR_AMOD_OFF)

/** \brief DSU ADDR.ADDR bit offset */
#define DSU_ADDR_ADDR_OFF 2u
/** \brief DSU ADDR.ADDR bit mask */
#define DSU_ADDR_ADDR_MSK (0x3FFFFFFFu << DSU_ADDR_ADDR_OFF)

/**@}*/

/** \name DSU LENGTH register */
/**@{*/

/** \brief DSU LENGTH register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Reserved */
		uint32_t :2;
		/** \brief Length */
		uint32_t LENGTH:30;
	} B;
} dsu_length_t;

/** \brief DSU LENGTH register address offset */
#define DSU_LENGTH_OFF 0x08u

/** \brief DSU LENGTH register address */
#define DSU_LENGTH_ADDR (DSU_BASE_ADDR + DSU_LENGTH_OFF)

/** \brief DSU LENGTH register */
#define DSU_LENGTH (*((volatile dsu_length_t*) DSU_LENGTH_ADDR))

/** \brief DSU LENGTH.LENGTH bit offset */
#define DSU_LENGTH_LENGTH_OFF 2u
/** \brief DSU LENGTH.LENGTH bit mask */
#define DSU_LENGTH_LENGTH_MSK (0x3FFFFFFFu << DSU_LENGTH_LENGTH_OFF)

/**@}*/

/** \name DSU DATA register */
/**@{*/

/** \brief DSU DATA register address offset */
#define DSU_DATA_OFF 0x0Cu

/** \brief DSU DATA register address */
#define DSU_DATA_ADDR (DSU_BASE_ADDR + DSU_DATA_OFF)

/** \brief DSU DATA register */
#define DSU_DATA (*((volatile uint32_t*) DSU_DATA_ADDR))

/**@}*/

#endif /* SAMFD_REG_DSU_H */
