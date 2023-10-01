/* SPDX-License-Identifier: MIT */
/**
 * \file      inc/reg/nvmctrl.h
 * \brief     Definitions regarding NVMCTRL registers structure
 * \copyright Copyright (c) 2023 Leon Rinkel
 */

#ifndef SAMFD_REG_NVMCTRL_H
#define SAMFD_REG_NVMCTRL_H

#include <stdint.h>

/** \brief NVMCTRL registers base address */
#define NVMCTRL_BASE_ADDR 0x41004000u

/** \name NVMCTRL CTRLA register */
/**@{*/

/** \brief NVMCTRL CTRLA register structure */
typedef union
{
	/** \brief Unsigned access */
	uint16_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Command */
		uint16_t CMD:7;
		/** \brief Command execution */
		uint16_t CMDEX:8;
	} B;
} nvmctrl_ctrla_t;

/** \brief NVMCTRL CTRLA register address offset */
#define NVMCTRL_CTRLA_OFF 0x00u

/** \brief NVMCTRL CTRLA register address */
#define NVMCTRL_CTRLA_ADDR (NVMCTRL_BASE_ADDR + NVMCTRL_CTRLA_OFF)

/** \brief NVMCTRL CTRLA register */
#define NVMCTRL_CTRLA (*((volatile nvmctrl_ctrla_t*) NVMCTRL_CTRLA_ADDR))

/** \brief NVMCTRL CTRLA.CMD bit offset */
#define NVMCTRL_CTRLA_CMD_OFF 0u
/** \brief NVMCTRL CTRLA.CMD bit mask */
#define NVMCTRL_CTRLA_CMD_MSK (0x7Fu << NVMCTRL_CTRLA_OFF)

/** \brief NVMCTRL CTRLA.CMDEX bit offset */
#define NVMCTRL_CTRLA_CMDEX_OFF 8u
/** \brief NVMCTRL CTRLA.CMDEX bit mask */
#define NVMCTRL_CTRLA_CMDEX_MSK (0xFu << NVMCTRL_CTRLA_OFF)

/**@}*/

/** \name NVMCTRL CTRLB register */
/**@{*/

/** \brief NVMCTRL CTRLB register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Reserved */
		uint32_t :1;
		/** \brief NVM read wait states */
		uint32_t RWS:4;
		/** \brief Reserved */
		uint32_t :2;
		/** \brief Manual write */
		uint32_t MANW:1;
		/** \brief Power reduction mode during sleep */
		uint32_t SLEEPPRM:2;
		/** \brief Reserved */
		uint32_t :6;
		/** \brief NVMCTRL read mode */
		uint32_t READMODE:2;
		/** \brief Cache disable */
		uint32_t CACHEDIS:1;
		/** \brief Reserved */
		uint32_t :5;
		/** \brief Reserved */
		uint32_t :8;
	} B;
} nvmctrl_ctrlb_t;

/** \brief NVMCTRL CTRLB register address offset */
#define NVMCTRL_CTRLB_OFF 0x04u

/** \brief NVMCTRL CTRLB register address */
#define NVMCTRL_CTRLB_ADDR (NVMCTRL_BASE_ADDR + NVMCTRL_CTRLB_OFF)

/** \brief NVMCTRL CTRLB register */
#define NVMCTRL_CTRLB (*((volatile nvmctrl_ctrlb_t*) NVMCTRL_CTRLB_ADDR))

/** \brief NVMCTRL CTRLB.RWS bit offset */
#define NVMCTRL_CTRLB_RWS_OFF 1u
/** \brief NVMCTRL CTRLB.RWS bit mask */
#define NVMCTRL_CTRLB_RWS_MSK (0xFu << NVMCTRL_CTRLB_RWS_OFF)

/** \brief NVMCTRL CTRLB.MANW bit offset */
#define NVMCTRL_CTRLB_MANW_OFF 7u
/** \brief NVMCTRL CTRLB.MANW bit mask */
#define NVMCTRL_CTRLB_MANW_MSK (0x1u << NVMCTRL_CTRLB_MANW_OFF)

/** \brief NVMCTRL CTRLB.SLEEPPRM bit offset */
#define NVMCTRL_CTRLB_SLEEPPRM_OFF 8u
/** \brief NVMCTRL CTRLB.SLEEPPRM bit mask */
#define NVMCTRL_CTRLB_SLEEPPRM_MSK (0x3u << NVMCTRL_CTRLB_SLEEPPRM_OFF)

/** \brief NVMCTRL CTRLB.READMODE bit offset */
#define NVMCTRL_CTRLB_READMODE_OFF 16u
/** \brief NVMCTRL CTRLB.READMODE bit mask */
#define NVMCTRL_CTRLB_READMODE_MSK (0x3u << NVMCTRL_CTRLB_READMODE_OFF)

/** \brief NVMCTRL CTRLB.CACHEDIS bit offset */
#define NVMCTRL_CTRLB_CACHEDIS_OFF 18u
/** \brief NVMCTRL CTRLB.CACHEDIS bit mask */
#define NVMCTRL_CTRLB_CACHEDIS_MSK (0x1u << NVMCTRL_CTRLB_CACHEDIS_OFF)

/**@}*/

/** \name NVMCTRL INTFLAG register */
/**@{*/

/** \brief NVMCTRL INTFLAG register structure */
typedef union
{
	/** \brief Unsigned access */
	uint8_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief NVM ready */
		uint8_t READY:1;
		/** \brief Error */
		uint8_t ERROR:1;
	} B;
} nvmctrl_intflag_t;

/** \brief NVMCTRL INTFLAG register address offset */
#define NVMCTRL_INTFLAG_OFF 0x14u

/** \brief NVMCTRL INTFLAG register address */
#define NVMCTRL_INTFLAG_ADDR (NVMCTRL_BASE_ADDR + NVMCTRL_INTFLAG_OFF)

/** \brief NVMCTRL INTFLAG register */
#define NVMCTRL_INTFLAG (*((volatile nvmctrl_intflag_t*) NVMCTRL_INTFLAG_ADDR))

/** \brief NVMCTRL INTFLAG.READY bit offset */
#define NVMCTRL_INTFLAG_READY_OFF 0u
/** \brief NVMCTRL INTFLAG.READY bit mask */
#define NVMCTRL_INTFLAG_READY_MSK (0x1u << NVMCTRL_INTFLAG_READY_OFF)

/** \brief NVMCTRL INTFLAG.ERROR bit offset */
#define NVMCTRL_INTFLAG_ERROR_OFF 1u
/** \brief NVMCTRL INTFLAG.ERROR bit mask */
#define NVMCTRL_INTFLAG_ERROR_MSK (0x1u << NVMCTRL_INTFLAG_READY_OFF)

/**@}*/

/** \name NVMCTRL STATUS register */
/**@{*/

/** \brief NVMCTRL STATUS register structure */
typedef union
{
	/** \brief Unsigned access */
	uint16_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Power reduction mode */
		uint16_t PRM:1;
		/** \brief NVM page buffer active loading */
		uint16_t LOAD:1;
		/** \brief Programming error status */
		uint16_t PROGE:1;
		/** \brief Lock error status */
		uint16_t LOCKE:1;
		/** \brief NVM error */
		uint16_t NVME:1;
		/** \brief Reserved */
		uint16_t :3;
		/** \brief Security bit status */
		uint16_t SB:1;
		/** \brief Reserved */
		uint16_t :7;
	} B;
} nvmctrl_status_t;

/** \brief NVMCTRL STATUS register address offset */
#define NVMCTRL_STATUS_OFF 0x18u

/** \brief NVMCTRL STATUS register address */
#define NVMCTRL_STATUS_ADDR (NVMCTRL_BASE_ADDR + NVMCTRL_STATUS_OFF)

/** \brief NVMCTRL STATUS register */
#define NVMCTRL_STATUS (*((volatile nvmctrl_status_t*) NVMCTRL_STATUS_ADDR))

/** \brief NVMCTRL STATUS.PRM bit offset */
#define NVMCTRL_STATUS_PRM_OFF 0u
/** \brief NVMCTRL STATUS.PRM bit mask */
#define NVMCTRL_STATUS_PRM_MSK (0x1u << NVMCTRL_STATUS_PRM_OFF)

/** \brief NVMCTRL STATUS.LOAD bit offset */
#define NVMCTRL_STATUS_LOAD_OFF 1u
/** \brief NVMCTRL STATUS.LOAD bit mask */
#define NVMCTRL_STATUS_LOAD_MSK (0x1u << NVMCTRL_STATUS_LOAD_OFF)

/** \brief NVMCTRL STATUS.PROGE bit offset */
#define NVMCTRL_STATUS_PROGE_OFF 2u
/** \brief NVMCTRL STATUS.PROGE bit mask */
#define NVMCTRL_STATUS_PROGE_MSK (0x1u << NVMCTRL_STATUS_PROGE_OFF)

/** \brief NVMCTRL STATUS.LOCKE bit offset */
#define NVMCTRL_STATUS_LOCKE_OFF 3u
/** \brief NVMCTRL STATUS.LOCKE bit mask */
#define NVMCTRL_STATUS_LOCKE_MSK (0x1u << NVMCTRL_STATUS_LOCKE_OFF)

/** \brief NVMCTRL STATUS.NVME bit offset */
#define NVMCTRL_STATUS_NVME_OFF 4u
/** \brief NVMCTRL STATUS.NVME bit mask */
#define NVMCTRL_STATUS_NVME_MSK (0x1u << NVMCTRL_STATUS_NVME_OFF)

/** \brief NVMCTRL STATUS.SB bit offset */
#define NVMCTRL_STATUS_SB_OFF 8u
/** \brief NVMCTRL STATUS.SB bit mask */
#define NVMCTRL_STATUS_SB_MSK (0x1u << NVMCTRL_STATUS_SB_OFF)

/**@}*/

/** \name NVMCTRL ADDR register */
/**@{*/

/** \brief NVMCTRL ADDR register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief NVM address */
		uint32_t ADDR:22;
		/** \brief Reserved */
		uint32_t :10;
	} B;
} nvmctrl_addr_t;

/** \brief NVMCTRL ADDR register address offset */
#define NVMCTRL_ADDR_OFF 0x1Cu

/** \brief NVMCTRL ADDR register address */
#define NVMCTRL_ADDR_ADDR (NVMCTRL_BASE_ADDR + NVMCTRL_ADDR_OFF)

/** \brief NVMCTRL ADDR register */
#define NVMCTRL_ADDR (*((volatile nvmctrl_addr_t*) NVMCTRL_ADDR_ADDR))

/** \brief NVMCTRL ADDR.ADDR bit offset*/
#define NVMCTRL_ADDR_ADDR_OFF 0u
/** \brief NVMCTRL ADDR.ADDR bit mask */
#define NVMCTRL_ADDR_ADDR_MSK (0x7FFFFFu << NVMCTRL_ADDR_ADDR_OFF)

/**@}*/

#endif /* SAMFD_REG_NVMCTRL_H */
