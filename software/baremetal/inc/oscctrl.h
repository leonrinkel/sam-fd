/* SPDX-License-Identifier: MIT */
/**
 * \file      inc/oscctrl.h
 * \brief     Definitions regarding OSCCTRL registers structure
 * \copyright Copyright (c) 2023 Leon Rinkel
 */

#ifndef SAMFD_OSCCTRL_H
#define SAMFD_OSCCTRL_H

#include <stdint.h>

/** \brief OSCCTRL registers base address */
#define OSCCTRL_ADDR 0x40001000u

/** \name OSCCTRL INTENSET register */
/**@{*/

/** \brief OSCCTRL INTENSET register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief XOSC ready interrupt enable */
		uint32_t XOSCRDY:1;
		/** \brief XOSC clock failure interrupt enable */
		uint32_t CLKFAIL:1;
		/** \brief Reserved */
		uint32_t :2;
		/** \brief OSC48M ready interrupt enable */
		uint32_t OSC48MRDY:1;
		/** \brief Reserved */
		uint32_t :3;
		/** \brief DPLL lock rise interrupt enable */
		uint32_t DPLLLCKR:1;
		/** \brief DPLL lock fall interrupt enable */
		uint32_t DPLLLCKF:1;
		/** \brief DPLL lock timeout interrupt enable */
		uint32_t DPLLLTO:1;
		/** \brief DPLL loop divider ratio update complete interrupt enable */
		uint32_t DPLLLDRTO:1;
		/** \brief Reserved */
		uint32_t :4;
		/** \brief Reserved */
		uint32_t :16;
	} B;
} oscctrl_intenset_t;

/** \brief OSCCTRL INTENSET register address offset */
#define OSCCTRL_INTENSET_OFF 0x04u

/** \brief OSCCTRL INTENSET register address */
#define OSCCTRL_INTENSET_ADDR (OSCCTRL_ADDR + OSCCTRL_INTENSET_OFF)

/** \brief OSCCTRL INTENSET register */
#define OSCCTRL_INTENSET (*((volatile oscctrl_intenset_t*) OSCCTRL_INTENSET_ADDR))

/** \brief OSCCTRL INTENSET.XOSCRDY bit offset */
#define OSCCTRL_INTENSET_XOSCRDY_OFF 0u
/** \brief OSCCTRL INTENSET.XOSCRDY bit mask */
#define OSCCTRL_INTENSET_XOSCRDY_MSK (0x1u << OSCCTRL_INTENSET_XOSCRDY_OFF)

/** \brief OSCCTRL INTENSET.CLKFAIL bit offset */
#define OSCCTRL_INTENSET_CLKFAIL_OFF 1u
/** \brief OSCCTRL INTENSET.CLKFAIL bit mask */
#define OSCCTRL_INTENSET_CLKFAIL_MSK (0x1u << OSCCTRL_INTENSET_CLKFAIL_OFF)

/** \brief OSCCTRL INTENSET.OSC48MRDY bit offset */
#define OSCCTRL_INTENSET_OSC48MRDY_OFF 4u
/** \brief OSCCTRL INTENSET.OSC48MRDY bit mask */
#define OSCCTRL_INTENSET_OSC48MRDY_MSK (0x1u << OSCCTRL_INTENSET_OSC48MRDY_OFF)

/** \brief OSCCTRL INTENSET.DPLLLCKR bit offset */
#define OSCCTRL_INTENSET_DPLLLCKR_OFF 8
/** \brief OSCCTRL INTENSET.DPLLLCKR bit mask */
#define OSCCTRL_INTENSET_DPLLLCKR_MSK (0x1u << OSCCTRL_INTENSET_DPLLLCKR_OFF)

/** \brief OSCCTRL INTENSET.DPLLLCKF bit offset */
#define OSCCTRL_INTENSET_DPLLLCKF_OFF 9u
/** \brief OSCCTRL INTENSET.DPLLLCKF bit mask */
#define OSCCTRL_INTENSET_DPLLLCKF_MSK (0x1u << OSCCTRL_INTENSET_DPLLLCKF_OFF)

/** \brief OSCCTRL INTENSET.DPLLLTO bit offset */
#define OSCCTRL_INTENSET_DPLLLTO_OFF 10u
/** \brief OSCCTRL INTENSET.DPLLLTO bit mask */
#define OSCCTRL_INTENSET_DPLLLTO_MSK (0x1u << OSCCTRL_INTENSET_DPLLLTO_OFF)

/** \brief OSCCTRL INTENSET.DPLLLDRTO bit offset */
#define OSCCTRL_INTENSET_DPLLLDRTO_OFF 11u
/** \brief OSCCTRL INTENSET.DPLLLDRTO bit mask */
#define OSCCTRL_INTENSET_DPLLLDRTO_MSK (0x1u << OSCCTRL_INTENSET_DPLLLDRTO_OFF)

/**@}*/

/** \name OSCCTRL INTFLAG register */
/**@{*/

/** \brief OSCCTRL INTFLAG register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief XOSC ready */
		uint32_t XOSCRDY:1;
		/** \brief XOSC failure detection */
		uint32_t CLKFAIL:1;
		/** \brief Reserved */
		uint32_t :2;
		/** \brief OSC48M ready */
		uint32_t OSC48MRDY:1;
		/** \brief Reserved */
		uint32_t :3;
		/** \brief DPLL lock rise */
		uint32_t DPLLLCKR:1;
		/** \brief DPLL lock fall */
		uint32_t DPLLLCKF:1;
		/** \brief DPLL lock timeout */
		uint32_t DPLLLTO:1;
		/** \brief DPLL loop divider ratio update complete */
		uint32_t DPLLLDRTO:1;
		/** \brief Reserved */
		uint32_t :4;
		/** \brief Reserved */
		uint32_t :16;
	} B;
} oscctrl_intflag_t;

/** \brief OSCCTRL INTFLAG register address offset */
#define OSCCTRL_INTFLAG_OFF 0x08u

/** \brief OSCCTRL INTFLAG register address */
#define OSCCTRL_INTFLAG_ADDR (OSCCTRL_ADDR + OSCCTRL_INTFLAG_OFF)

/** \brief OSCCTRL INTFLAG register */
#define OSCCTRL_INTFLAG (*((volatile oscctrl_intflag_t*) OSCCTRL_INTFLAG_ADDR))

/**@}*/

/** \name OSCCTRL STATUS register */
/**@{*/

/** \brief OSCCTRL STATUS register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief XOSC ready */
		uint32_t XOSCRDY:1;
		/** \brief XOSC clock failure */
		uint32_t CLKFAIL:1;
		/** \brief XOSC clock switch */
		uint32_t CLKSW:1;
		/** \brief Reserved */
		uint32_t :1;
		/** \brief OSC48M ready */
		uint32_t OSC48MRDY:1;
		/** \brief Reserved */
		uint32_t :3;
		/** \brief DPLL lock rise */
		uint32_t DPLLLCKR:1;
		/** \brief DPLL lock fall */
		uint32_t DPLLLCKF:1;
		/** \brief DPLL lock timeout */
		uint32_t DPLLLTO:1;
		/** \brief DPLL loop divider ratio update complete */
		uint32_t DPLLLDRTO:1;
		/** \brief Reserved */
		uint32_t :4;
		/** \brief Reserved */
		uint32_t :16;
	} B;
} oscctrl_status_t;

/** \brief OSCCTRL STATUS register address offset */
#define OSCCTRL_STATUS_OFF 0x0Cu

/** \brief OSCCTRL STATUS register address */
#define OSCCTRL_STATUS_ADDR (OSCCTRL_ADDR + OSCCTRL_STATUS_OFF)

/** \brief OSCCTRL STATUS register */
#define OSCCTRL_STATUS (*((volatile oscctrl_status_t*) OSCCTRL_STATUS_ADDR))

/** \brief OSCCTRL STATUS.XOSCRDY bit offset */
#define OSCCTRL_STATUS_XOSCRDY_OFF 0u
/** \brief OSCCTRL STATUS.XOSCRDY bit mask */
#define OSCCTRL_STATUS_XOSCRDY_MSK (0x1u << OSCCTRL_STATUS_XOSCRDY_OFF)

/** \brief OSCCTRL STATUS.CLKFAIL bit offset */
#define OSCCTRL_STATUS_CLKFAIL_OFF 1u
/** \brief OSCCTRL STATUS.CLKFAIL bit mask */
#define OSCCTRL_STATUS_CLKFAIL_MSK (0x1u << OSCCTRL_STATUS_CLKFAIL_OFF)

/** \brief OSCCTRL STATUS.CLKSW bit offset */
#define OSCCTRL_STATUS_CLKSW_OFF 2u
/** \brief OSCCTRL STATUS.CLKSW bit mask */
#define OSCCTRL_STATUS_CLKSW_MSK (0x1u << OSCCTRL_STATUS_CLKSW_OFF)

/** \brief OSCCTRL STATUS.OSC48MRDY bit offset */
#define OSCCTRL_STATUS_OSC48MRDY_OFF 4u
/** \brief OSCCTRL STATUS.OSC48MRDY bit mask */
#define OSCCTRL_STATUS_OSC48MRDY_MSK (0x1u << OSCCTRL_STATUS_OSC48MRDY_OFF)

/** \brief OSCCTRL STATUS.DPLLLCKR bit offset */
#define OSCCTRL_STATUS_DPLLLCKR_OFF 8u
/** \brief OSCCTRL STATUS.DPLLLCKR bit mask */
#define OSCCTRL_STATUS_DPLLLCKR_MSK (0x1u << OSCCTRL_STATUS_DPLLLCKR_OFF)

/** \brief OSCCTRL STATUS.DPLLLCKF bit offset */
#define OSCCTRL_STATUS_DPLLLCKF_OFF 9u
/** \brief OSCCTRL STATUS.DPLLLCKF bit mask */
#define OSCCTRL_STATUS_DPLLLCKF_MSK (0x1u << OSCCTRL_STATUS_DPLLLCKF_OFF)

/** \brief OSCCTRL STATUS.DPLLLTO bit offset */
#define OSCCTRL_STATUS_DPLLLTO_OFF 10u
/** \brief OSCCTRL STATUS.DPLLLTO bit mask */
#define OSCCTRL_STATUS_DPLLLTO_MSK (0x1u << OSCCTRL_STATUS_DPLLLTO_OFF)

/** \brief OSCCTRL STATUS.DPLLLDRTO bit offset */
#define OSCCTRL_STATUS_DPLLLDRTO_OFF 11u
/** \brief OSCCTRL STATUS.DPLLLDRTO bit mask */
#define OSCCTRL_STATUS_DPLLLDRTO_MSK (0x1u << OSCCTRL_STATUS_DPLLLDRTO_OFF)

/**@}*/

/** \name OSCCTRL XOSCCTRL register */
/**@{*/

/** \brief OSCCTRL XOSCCTRL register structure */
typedef union
{
	/** \brief Unsigned access */
	uint16_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Reserved */
		uint16_t :1;
		/** \brief Oscillator enable */
		uint16_t ENABLE:1;
		/** \brief Crystal oscillator enable */
		uint16_t XTALEN:1;
		/** \brief Clock failure detector enable */
		uint16_t CFDEN:1;
		/** \brief Clock switch back */
		uint16_t SWBEN:1;
		/** \brief Reserved */
		uint16_t :1;
		/** \brief Run in standby */
		uint16_t RUNSTDBY:1;
		/** \brief On demand control */
		uint16_t ONDEMAND:1;
		/** \brief Oscillator gain */
		uint16_t GAIN:3;
		/** \brief Automatic amplitude gain control */
		uint16_t AMPGC:1;
		/** \brief Start-up time */
		uint16_t STARTUP:4;
	} B;
} oscctrl_xoscctrl_t;

/** \brief OSCCTRL XOSCCTRL register address offset */
#define OSCCTRL_XOSCCTRL_OFF 0x10u

/** \brief OSCCTRL XOSCCTRL register address */
#define OSCCTRL_XOSCCTRL_ADDR (OSCCTRL_ADDR + OSCCTRL_XOSCCTRL_OFF)

/** \brief OSCCTRL XOSCCTRL register */
#define OSCCTRL_XOSCCTRL (*((volatile oscctrl_xoscctrl_t*) OSCCTRL_XOSCCTRL_ADDR))

/** \brief OSCCTRL XOSCCTRL.ENABLE bit offset */
#define OSCCTRL_XOSCCTRL_ENABLE_OFF 1u
/** \brief OSCCTRL XOSCCTRL.ENABLE bit mask */
#define OSCCTRL_XOSCCTRL_ENABLE_MSK (0x1u << OSCCTRL_XOSCCTRL_ENABLE_OFF)

/** \brief OSCCTRL XOSCCTRL.XTALEN bit offset */
#define OSCCTRL_XOSCCTRL_XTALEN_OFF 2u
/** \brief OSCCTRL XOSCCTRL.XTALEN bit mask */
#define OSCCTRL_XOSCCTRL_XTALEN_MSK (0x1u << OSCCTRL_XOSCCTRL_XTALEN_OFF)

/** \brief OSCCTRL XOSCCTRL.CFDEN bit offset */
#define OSCCTRL_XOSCCTRL_CFDEN_OFF 3u
/** \brief OSCCTRL XOSCCTRL.CFDEN bit mask */
#define OSCCTRL_XOSCCTRL_CFDEN_MSK (0x1u << OSCCTRL_XOSCCTRL_CFDEN_OFF)

/** \brief OSCCTRL XOSCCTRL.SWBEN bit offset */
#define OSCCTRL_XOSCCTRL_SWBEN_OFF 4u
/** \brief OSCCTRL XOSCCTRL.SWBEN bit mask */
#define OSCCTRL_XOSCCTRL_SWBEN_MSK (0x1u << OSCCTRL_XOSCCTRL_SWBEN_OFF)

/** \brief OSCCTRL XOSCCTRL.RUNSTDBY bit offset */
#define OSCCTRL_XOSCCTRL_RUNSTDBY_OFF 6u
/** \brief OSCCTRL XOSCCTRL.RUNSTDBY bit mask */
#define OSCCTRL_XOSCCTRL_RUNSTDBY_MSK (0x1u << OSCCTRL_XOSCCTRL_RUNSTDBY_OFF)

/** \brief OSCCTRL XOSCCTRL.ONDEMAND bit offset */
#define OSCCTRL_XOSCCTRL_ONDEMAND_OFF 7u
/** \brief OSCCTRL XOSCCTRL.ONDEMAND bit mask */
#define OSCCTRL_XOSCCTRL_ONDEMAND_MSK (0x1u << OSCCTRL_XOSCCTRL_ONDEMAND_OFF)

/** \brief OSCCTRL XOSCCTRL.GAIN bit offset */
#define OSCCTRL_XOSCCTRL_GAIN_OFF 8u
/** \brief OSCCTRL XOSCCTRL.GAIN bit mask */
#define OSCCTRL_XOSCCTRL_GAIN_MSK (0x7u << OSCCTRL_XOSCCTRL_GAIN_OFF)

/** \brief OSCCTRL XOSCCTRL.AMPGC bit offset */
#define OSCCTRL_XOSCCTRL_AMPGC_OFF 11u
/** \brief OSCCTRL XOSCCTRL.AMPGC bit mask */
#define OSCCTRL_XOSCCTRL_AMPGC_MSK (0x1u << OSCCTRL_XOSCCTRL_AMPGC_OFF)

/** \brief OSCCTRL XOSCCTRL.STARTUP bit offset */
#define OSCCTRL_XOSCCTRL_STARTUP_OFF 12u
/** \brief OSCCTRL XOSCCTRL.STARTUP bit mask */
#define OSCCTRL_XOSCCTRL_STARTUP_MSK (0xFu << OSCCTRL_XOSCCTRL_STARTUP_OFF)

/**@}*/

/** \name OSCCTRL CFDPRESC register */
/**@{*/

/** \brief OSCCTRL CFDPRESC register structure */
typedef union
{
	/** \brief Unsigned access */
	uint8_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Clock failure detector prescaler */
		uint8_t CFDPRESC:3;
		/** \brief Reserved */
		uint8_t :5;
	} B;
} oscctrl_cfdpresc_t;

/** \brief OSCCTRL CFDPRESC register address offset */
#define OSCCTRL_CFDPRESC_OFF 0x12u

/** \brief OSCCTRL CFDPRESC register address */
#define OSCCTRL_CFDPRESC_ADDR (OSCCTRL_ADDR + OSCCTRL_CFDPRESC_OFF)

/** \brief OSCCTRL CFDPRESC register */
#define OSCCTRL_CFDPRESC (*((volatile oscctrl_cfdpresc_t*) OSCCTRL_CFDPRESC_ADDR))

/** \brief OSCCTRL CFDPRESC.CFDPRESC bit offset */
#define OSCCTRL_CFDPRESC_CFDPRESC_OFF 0u
/** \brief OSCCTRL CFDPRESC.CFDPRESC bit mask */
#define OSCCTRL_CFDPRESC_CFDPRESC_MSK (0x7u << OSCCTRL_CFDPRESC_CFDPRESC_OFF)

/**@}*/

/** \name OSCCTRL EVCTRL register */
/**@{*/

/** \brief OSCCTRL EVCTRL register structure */
typedef union
{
	/** \brief Unsigned access */
	uint8_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Clock failure detector event output enable */
		uint8_t CFDEO:1;
		/** \brief Reserved */
		uint8_t :7;
	} B;
} oscctrl_evctrl_t;

/** \brief OSCCTRL EVCTRL register address offset */
#define OSCCTRL_EVCTRL_OFF 0x13u

/** \brief OSCCTRL EVCTRL register address */
#define OSCCTRL_EVCTRL_ADDR (OSCCTRL_ADDR + OSCCTRL_EVCTRL_OFF)

/** \brief OSCCTRL EVCTRL register */
#define OSCCTRL_EVCTRL (*((volatile oscctrl_evctrl_t*) OSCCTRL_EVCTRL_ADDR))

/** \brief OSCCTRL EVCTRL.CFDEO bit offset */
#define OSCCTRL_EVCTRL_CFDEO_OFF 0u
/** \brief OSCCTRL EVCTRL.CFDEO bit mask */
#define OSCCTRL_EVCTRL_CFDEO_MSK (0x1u << OSCCTRL_EVCTRL_CFDEO_OFF)

/**@}*/

/** \name OSCCTRL OSC48MCTRL register */
/**@{*/

/** \brief OSCCTRL OSC48MCTRL register structure */
typedef union
{
	/** \brief Unsigned access */
	uint8_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Reserved */
		uint8_t :1;
		/** \brief Oscillator enable */
		uint8_t ENABLE:1;
		/** \brief Reserved */
		uint8_t :4;
		/** \brief Run in standby */
		uint8_t RUNSTDBY:1;
		/** \brief On demand control */
		uint8_t ONDEMAND:1;
	} B;
} oscctrl_osc48mctrl_t;

/** \brief OSCCTRL OSC48MCTRL register address offset */
#define OSCCTRL_OSC48MCTRL_OFF 0x14u

/** \brief OSCCTRL OSC48MCTRL register address */
#define OSCCTRL_OSC48MCTRL_ADDR (OSCCTRL_ADDR + OSCCTRL_OSC48MCTRL_OFF)

/** \brief OSCCTRL OSC48MCTRL register */
#define OSCCTRL_OSC48MCTRL (*((volatile oscctrl_osc48mctrl_t*) OSCCTRL_OSC48MCTRL_ADDR))

/** \brief OSCCTRL OSC48MCTRL.ENABLE bit offset */
#define OSCCTRL_OSC48MCTRL_ENABLE_OFF 1u
/** \brief OSCCTRL OSC48MCTRL.ENABLE bit mask */
#define OSCCTRL_OSC48MCTRL_ENABLE_MSK (0x1u << OSCCTRL_OSC48MCTRL_ENABLE_OFF)

/** \brief OSCCTRL OSC48MCTRL.RUNSTDBY bit offset */
#define OSCCTRL_OSC48MCTRL_RUNSTDBY_OFF 6u
/** \brief OSCCTRL OSC48MCTRL.RUNSTDBY bit mask */
#define OSCCTRL_OSC48MCTRL_RUNSTDBY_MSK (0x1u << OSCCTRL_OSC48MCTRL_RUNSTDBY_OFF)

/** \brief OSCCTRL OSC48MCTRL.ONDEMAND bit offset */
#define OSCCTRL_OSC48MCTRL_ONDEMAND_OFF 7u
/** \brief OSCCTRL OSC48MCTRL.ONDEMAND bit mask */
#define OSCCTRL_OSC48MCTRL_ONDEMAND_MSK (0x1u << OSCCTRL_OSC48MCTRL_ONDEMAND_OFF)

/**@}*/

/** \name OSCCTRL OSC48MDIV register */
/**@{*/

/** \brief OSCCTRL OSC48MDIV register structure */
typedef union
{
	/** \brief Unsigned access */
	uint8_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Oscillator divider selection */
		uint8_t DIV:4;
		/** \brief Reserved */
		uint8_t :4;
	} B;
} oscctrl_osc48mdiv_t;

/** \brief OSCCTRL OSC48MDIV register address offset */
#define OSCCTRL_OSC48MDIV_OFF 0x15u

/** \brief OSCCTRL OSC48MDIV register address */
#define OSCCTRL_OSC48MDIV_ADDR (OSCCTRL_ADDR + OSCCTRL_OSC48MDIV_OFF)

/** \brief OSCCTRL OSC48MDIV register */
#define OSCCTRL_OSC48MDIV (*((volatile oscctrl_osc48mdiv_t*) OSCCTRL_OSC48MDIV_ADDR))

/** \brief OSCCTRL OSC48MDIV.DIV bit offset */
#define OSCCTRL_OSC48MDIV_DIV_OFF 0u
/** \brief OSCCTRL OSC48MDIV.DIV bit mask */
#define OSCCTRL_OSC48MDIV_DIV_MSK (0xFu << OSCCTRL_OSC48MDIV_DIV_OFF)

/**@}*/

/** \name OSCCTRL OSC48MSYNCBUSY register */
/**@{*/

/** \brief OSCCTRL OSC48MSYNCBUSY register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Reserved */
		uint32_t :2;
		/** \brief Oscillator divider synchronization status */
		uint32_t OSC48MDIV:1;
		/** \brief Reserved */
		uint32_t :5;
		/** \brief Reserved */
		uint32_t :8;
		/** \brief Reserved */
		uint32_t :16;
	} B;
} oscctrl_osc48msyncbusy_t;

/** \brief OSCCTRL OSC48MSYNCBUSY register address offset */
#define OSCCTRL_OSC48MSYNCBUSY_OFF 0x18u

/** \brief OSCCTRL OSC48MSYNCBUSY register address */
#define OSCCTRL_OSC48MSYNCBUSY_ADDR (OSCCTRL_ADDR + OSCCTRL_OSC48MSYNCBUSY_OFF)

/** \brief OSCCTRL OSC48MSYNCBUSY register */
#define OSCCTRL_OSC48MSYNCBUSY (*((volatile oscctrl_osc48msyncbusy_t*) OSCCTRL_OSC48MSYNCBUSY_ADDR))

/** \brief OSCCTRL OSC48MSYNCBUSY.OSC48MDIV bit offset */
#define OSCCTRL_OSC48MSYNCBUSY_OSC48MDIV_OFF 2u
/** \brief OSCCTRL OSC48MSYNCBUSY.OSC48MDIV bit mask */
#define OSCCTRL_OSC48MSYNCBUSY_OSC48MDIV_MSK (0x1u << OSCCTRL_OSC48MSYNCBUSY_OSC48MDIV_OFF)

/**@}*/

#endif /* SAMFD_OSCCTRL_H */
