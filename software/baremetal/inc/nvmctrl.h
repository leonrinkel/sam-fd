#ifndef SAMFD_NVMCTRL_H
#define SAMFD_NVMCTRL_H

#include <stdint.h>

/** \brief NVMCTRL registers base address */
#define NVMCTRL_ADDR 0x41004000u

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
#define NVMCTRL_CTRLB_ADDR (NVMCTRL_ADDR + NVMCTRL_CTRLB_OFF)

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

#endif /* SAMFD_NVMCTRL_H */
