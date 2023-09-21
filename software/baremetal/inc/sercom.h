#ifndef SAMFD_SERCOM_H
#define SAMFD_SERCOM_H

#include <stdint.h>

/** \brief SERCOM0 registers base address */
#define SERCOM0_ADDR 0x42000400u
/** \brief SERCOM1 registers base address */
#define SERCOM1_ADDR 0x42000800u
/** \brief SERCOM2 registers base address */
#define SERCOM2_ADDR 0x42000C00u
/** \brief SERCOM3 registers base address */
#define SERCOM3_ADDR 0x42001000u
/** \brief SERCOM4 registers base address */
#define SERCOM4_ADDR 0x42001400u
/** \brief SERCOM5 registers base address */
#define SERCOM5_ADDR 0x42001800u

/** \name SERCOM CTRLA register */
/**@{*/

/** \brief SERCOM CTRLA register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Software reset */
		uint32_t SWRST:1;
		/** \brief Enable */
		uint32_t ENABLE:1;
		/** \brief Operating mode */
		uint32_t MODE:3;
		/** \brief Reserved */
		uint32_t :2;
		/** \brief Run In Standby */
		uint32_t RUNSTDBY:1;
		/** \brief Immediate buffer overflow notification */
		uint32_t IBON:1;
		/** \brief Reserved */
		uint32_t :4;
		/** \brief Sample rate */
		uint32_t SAMPR:3;
		/** \brief Transmit data pinout */
		uint32_t TXPO:2;
		/** \brief Reserved */
		uint32_t :2;
		/** \brief Receive data pinout */
		uint32_t RXPO:2;
		/** \brief Sample adjustment */
		uint32_t SAMPA:2;
		/** \brief Frame format */
		uint32_t FORM:4;
		/** \brief Communication mode */
		uint32_t CMODE:1;
		/** \brief Clock polarity */
		uint32_t CPOL:1;
		/** \brief Data order */
		uint32_t DORD:1;
		/** \brief Reserved */
		uint32_t :1;
	} B;
} sercom_ctrla_t;

/** \brief SERCOM CTRLA register address offset */
#define SERCOM_CTRLA_OFF 0x00u

/** \brief SERCOM0 CTRLA register address */
#define SERCOM0_CTRLA_ADDR (SERCOM0_ADDR + SERCOM_CTRLA_OFF)
/** \brief SERCOM1 CTRLA register address */
#define SERCOM1_CTRLA_ADDR (SERCOM1_ADDR + SERCOM_CTRLA_OFF)
/** \brief SERCOM2 CTRLA register address */
#define SERCOM2_CTRLA_ADDR (SERCOM2_ADDR + SERCOM_CTRLA_OFF)
/** \brief SERCOM3 CTRLA register address */
#define SERCOM3_CTRLA_ADDR (SERCOM3_ADDR + SERCOM_CTRLA_OFF)
/** \brief SERCOM4 CTRLA register address */
#define SERCOM4_CTRLA_ADDR (SERCOM4_ADDR + SERCOM_CTRLA_OFF)
/** \brief SERCOM5 CTRLA register address */
#define SERCOM5_CTRLA_ADDR (SERCOM5_ADDR + SERCOM_CTRLA_OFF)

/** \brief SERCOM0 CTRLA register */
#define SERCOM0_CTRLA (*((volatile sercom_ctrla_t*) SERCOM0_CTRLA_ADDR))
/** \brief SERCOM1 CTRLA register */
#define SERCOM1_CTRLA (*((volatile sercom_ctrla_t*) SERCOM1_CTRLA_ADDR))
/** \brief SERCOM2 CTRLA register */
#define SERCOM2_CTRLA (*((volatile sercom_ctrla_t*) SERCOM2_CTRLA_ADDR))
/** \brief SERCOM3 CTRLA register */
#define SERCOM3_CTRLA (*((volatile sercom_ctrla_t*) SERCOM3_CTRLA_ADDR))
/** \brief SERCOM4 CTRLA register */
#define SERCOM4_CTRLA (*((volatile sercom_ctrla_t*) SERCOM4_CTRLA_ADDR))
/** \brief SERCOM5 CTRLA register */
#define SERCOM5_CTRLA (*((volatile sercom_ctrla_t*) SERCOM5_CTRLA_ADDR))

/** \brief SERCOM CTRLA.SWRST bit offset */
#define SERCOM_CTRLA_SWRST_OFF 0u
/** \brief SERCOM CTRLA.SWRST bit mask */
#define SERCOM_CTRLA_SWRST_MSK (0x1u << SERCOM_CTRLA_SWRST_OFF)

/** \brief SERCOM CTRLA.ENABLE bit offset */
#define SERCOM_CTRLA_ENABLE_OFF 1u
/** \brief SERCOM CTRLA.ENABLE bit mask */
#define SERCOM_CTRLA_ENABLE_MSK (0x1u << SERCOM_CTRLA_ENABLE_OFF)

/** \brief SERCOM CTRLA.MODE bit offset */
#define SERCOM_CTRLA_MODE_OFF 2u
/** \brief SERCOM CTRLA.MODE bit mask */
#define SERCOM_CTRLA_MODE_MSK (0x1u << SERCOM_CTRLA_MODE_OFF)

/** \brief SERCOM CTRLA.RUNSTDBY bit offset */
#define SERCOM_CTRLA_RUNSTDBY_OFF 7u
/** \brief SERCOM CTRLA.RUNSTDBY bit mask */
#define SERCOM_CTRLA_RUNSTDBY_MSK (0x1u << SERCOM_CTRLA_RUNSTDBY_OFF)

/** \brief SERCOM CTRLA.IBON bit offset */
#define SERCOM_CTRLA_IBON_OFF 8u
/** \brief SERCOM CTRLA.IBON bit mask */
#define SERCOM_CTRLA_IBON_MSK (0x1u << SERCOM_CTRLA_IBON_OFF)

/** \brief SERCOM CTRLA.SAMPR bit offset */
#define SERCOM_CTRLA_SAMPR_OFF 13u
/** \brief SERCOM CTRLA.SAMPR bit mask */
#define SERCOM_CTRLA_SAMPR_MSK (0x1u << SERCOM_CTRLA_SAMPR_OFF)

/** \brief SERCOM CTRLA.TXPO bit offset */
#define SERCOM_CTRLA_TXPO_OFF 16u
/** \brief SERCOM CTRLA.TXPO bit mask */
#define SERCOM_CTRLA_TXPO_MSK (0x1u << SERCOM_CTRLA_TXPO_OFF)

/** \brief SERCOM CTRLA.RXPO bit offset */
#define SERCOM_CTRLA_RXPO_OFF 20u
/** \brief SERCOM CTRLA.RXPO bit mask */
#define SERCOM_CTRLA_RXPO_MSK (0x1u << SERCOM_CTRLA_RXPO_OFF)

/** \brief SERCOM CTRLA.SAMPA bit offset */
#define SERCOM_CTRLA_SAMPA_OFF 22u
/** \brief SERCOM CTRLA.SAMPA bit mask */
#define SERCOM_CTRLA_SAMPA_MSK (0x1u << SERCOM_CTRLA_SAMPA_OFF)

/** \brief SERCOM CTRLA.FORM bit offset */
#define SERCOM_CTRLA_FORM_OFF 24u
/** \brief SERCOM CTRLA.FORM bit mask */
#define SERCOM_CTRLA_FORM_MSK (0x1u << SERCOM_CTRLA_FORM_OFF)

/** \brief SERCOM CTRLA.CMODE bit offset */
#define SERCOM_CTRLA_CMODE_OFF 28u
/** \brief SERCOM CTRLA.CMODE bit mask */
#define SERCOM_CTRLA_CMODE_MSK (0x1u << SERCOM_CTRLA_CMODE_OFF)

/** \brief SERCOM CTRLA.CPOL bit offset */
#define SERCOM_CTRLA_CPOL_OFF 29u
/** \brief SERCOM CTRLA.CPOL bit mask */
#define SERCOM_CTRLA_CPOL_MSK (0x1u << SERCOM_CTRLA_CPOL_OFF)

/** \brief SERCOM CTRLA.DORD bit offset */
#define SERCOM_CTRLA_DORD_OFF 30u
/** \brief SERCOM CTRLA.DORD bit mask */
#define SERCOM_CTRLA_DORD_MSK (0x1u << SERCOM_CTRLA_DORD_OFF)

/**@}*/

/** \name SERCOM CTRLB register */
/**@{*/

/** \brief SERCOM CTRLB register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Character size */
		uint32_t CHSIZE:3;
		/** \brief Reserved */
		uint32_t :3;
		/** \brief Stop bit mode */
		uint32_t SBMODE:1;
		/** \brief Reserved */
		uint32_t :1;
		/** \brief Collision detection enable */
		uint32_t COLDEN:1;
		/** \brief Start of frame detection enable */
		uint32_t SFDE:1;
		/** \brief Encoding format */
		uint32_t ENC:1;
		/** \brief Reserved */
		uint32_t :2;
		/** \brief Parity mode */
		uint32_t PMODE:1;
		/** \brief Reserved */
		uint32_t :2;
		/** \brief Transmitter enable */
		uint32_t TXEN:1;
		/** \brief Receiver enable */
		uint32_t RXEN:1;
		/** \brief Reserved */
		uint32_t :6;
		/** \brief LIN command */
		uint32_t LINCMD:2;
		/** \brief Reserved */
		uint32_t :6;
	} B;
} sercom_ctrlb_t;

/** \brief SERCOM CTRLB register address offset */
#define SERCOM_CTRLB_OFF 0x04u

/** \brief SERCOM0 CTRLB register address */
#define SERCOM0_CTRLB_ADDR (SERCOM0_ADDR + SERCOM_CTRLB_OFF)
/** \brief SERCOM1 CTRLB register address */
#define SERCOM1_CTRLB_ADDR (SERCOM1_ADDR + SERCOM_CTRLB_OFF)
/** \brief SERCOM2 CTRLB register address */
#define SERCOM2_CTRLB_ADDR (SERCOM2_ADDR + SERCOM_CTRLB_OFF)
/** \brief SERCOM3 CTRLB register address */
#define SERCOM3_CTRLB_ADDR (SERCOM3_ADDR + SERCOM_CTRLB_OFF)
/** \brief SERCOM4 CTRLB register address */
#define SERCOM4_CTRLB_ADDR (SERCOM4_ADDR + SERCOM_CTRLB_OFF)
/** \brief SERCOM5 CTRLB register address */
#define SERCOM5_CTRLB_ADDR (SERCOM5_ADDR + SERCOM_CTRLB_OFF)

/** \brief SERCOM0 CTRLB register */
#define SERCOM0_CTRLB (*((volatile sercom_ctrlb_t*) SERCOM0_CTRLB_ADDR))
/** \brief SERCOM1 CTRLB register */
#define SERCOM1_CTRLB (*((volatile sercom_ctrlb_t*) SERCOM1_CTRLB_ADDR))
/** \brief SERCOM2 CTRLB register */
#define SERCOM2_CTRLB (*((volatile sercom_ctrlb_t*) SERCOM2_CTRLB_ADDR))
/** \brief SERCOM3 CTRLB register */
#define SERCOM3_CTRLB (*((volatile sercom_ctrlb_t*) SERCOM3_CTRLB_ADDR))
/** \brief SERCOM4 CTRLB register */
#define SERCOM4_CTRLB (*((volatile sercom_ctrlb_t*) SERCOM4_CTRLB_ADDR))
/** \brief SERCOM5 CTRLB register */
#define SERCOM5_CTRLB (*((volatile sercom_ctrlb_t*) SERCOM5_CTRLB_ADDR))

/** \brief SERCOM CTRLB.CHSIZE bit offset */
#define SERCOM_CTRLB_CHSIZE_OFF 0u
/** \brief SERCOM CTRLB.CHSIZE bit mask */
#define SERCOM_CTRLB_CHSIZE_MSK (0x7u << SERCOM_CTRLB_CHSIZE_OFF)

/** \brief SERCOM CTRLB.SBMODE bit offset */
#define SERCOM_CTRLB_SBMODE_OFF 6u
/** \brief SERCOM CTRLB.SBMODE bit mask */
#define SERCOM_CTRLB_SBMODE_MSK (0x1u << SERCOM_CTRLB_SBMODE_OFF)

/** \brief SERCOM CTRLB.COLDEN bit offset */
#define SERCOM_CTRLB_COLDEN_OFF 8u
/** \brief SERCOM CTRLB.COLDEN bit mask */
#define SERCOM_CTRLB_COLDEN_MSK (0x1u << SERCOM_CTRLB_COLDEN_OFF)

/** \brief SERCOM CTRLB.SFDE bit offset */
#define SERCOM_CTRLB_SFDE_OFF 9u
/** \brief SERCOM CTRLB.SFDE bit mask */
#define SERCOM_CTRLB_SFDE_MSK (0x1u << SERCOM_CTRLB_SFDE_OFF)

/** \brief SERCOM CTRLB.ENC bit offset */
#define SERCOM_CTRLB_ENC_OFF 10u
/** \brief SERCOM CTRLB.ENC bit mask */
#define SERCOM_CTRLB_ENC_MSK (0x1u << SERCOM_CTRLB_ENC_OFF)

/** \brief SERCOM CTRLB.PMODE bit offset */
#define SERCOM_CTRLB_PMODE_OFF 13u
/** \brief SERCOM CTRLB.PMODE bit mask */
#define SERCOM_CTRLB_PMODE_MSK (0x1u << SERCOM_CTRLB_PMODE_OFF)

/** \brief SERCOM CTRLB.TXEN bit offset */
#define SERCOM_CTRLB_TXEN_OFF 16u
/** \brief SERCOM CTRLB.TXEN bit mask */
#define SERCOM_CTRLB_TXEN_MSK (0x1u << SERCOM_CTRLB_TXEN_OFF)

/** \brief SERCOM CTRLB.RXEN bit offset */
#define SERCOM_CTRLB_RXEN_OFF 17u
/** \brief SERCOM CTRLB.RXEN bit mask */
#define SERCOM_CTRLB_RXEN_MSK (0x1u << SERCOM_CTRLB_RXEN_OFF)

/** \brief SERCOM CTRLB.LINCMD bit offset */
#define SERCOM_CTRLB_LINCMD_OFF 24u
/** \brief SERCOM CTRLB.LINCMD bit mask */
#define SERCOM_CTRLB_LINCMD_MSK (0x3u << SERCOM_CTRLB_LINCMD_OFF)

/**@}*/


/** \name SERCOM BAUD register */
/**@{*/

/** \brief SERCOM BAUD register address offset */
#define SERCOM_BAUD_OFF 0x0Cu

/** \brief SERCOM0 BAUD register address */
#define SERCOM0_BAUD_ADDR (SERCOM0_ADDR + SERCOM_BAUD_OFF)
/** \brief SERCOM1 BAUD register address */
#define SERCOM1_BAUD_ADDR (SERCOM1_ADDR + SERCOM_BAUD_OFF)
/** \brief SERCOM2 BAUD register address */
#define SERCOM2_BAUD_ADDR (SERCOM2_ADDR + SERCOM_BAUD_OFF)
/** \brief SERCOM3 BAUD register address */
#define SERCOM3_BAUD_ADDR (SERCOM3_ADDR + SERCOM_BAUD_OFF)
/** \brief SERCOM4 BAUD register address */
#define SERCOM4_BAUD_ADDR (SERCOM4_ADDR + SERCOM_BAUD_OFF)
/** \brief SERCOM5 BAUD register address */
#define SERCOM5_BAUD_ADDR (SERCOM5_ADDR + SERCOM_BAUD_OFF)

/** \brief SERCOM0 BAUD register */
#define SERCOM0_BAUD (*((volatile uint16_t*) SERCOM0_BAUD_ADDR))
/** \brief SERCOM1 BAUD register */
#define SERCOM1_BAUD (*((volatile uint16_t*) SERCOM1_BAUD_ADDR))
/** \brief SERCOM2 BAUD register */
#define SERCOM2_BAUD (*((volatile uint16_t*) SERCOM2_BAUD_ADDR))
/** \brief SERCOM3 BAUD register */
#define SERCOM3_BAUD (*((volatile uint16_t*) SERCOM3_BAUD_ADDR))
/** \brief SERCOM4 BAUD register */
#define SERCOM4_BAUD (*((volatile uint16_t*) SERCOM4_BAUD_ADDR))
/** \brief SERCOM5 BAUD register */
#define SERCOM5_BAUD (*((volatile uint16_t*) SERCOM5_BAUD_ADDR))

/**@}*/

/** \name SERCOM SYNCBUSY register */
/**@{*/

/** \brief SERCOM SYNCBUSY register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Software reset synchronization busy */
		uint32_t SWRST:1;
		/** \brief SERCOM enable synchronization busy */
		uint32_t ENABLE:1;
		/** \brief CTRLB synchronization busy */
		uint32_t CTRLB:1;
	} B;
} sercom_syncbusy_t;

/** \brief SERCOM SYNCBUSY register address offset */
#define SERCOM_SYNCBUSY_OFF 0x1Cu

/** \brief SERCOM0 SYNCBUSY register address */
#define SERCOM0_SYNCBUSY_ADDR (SERCOM0_ADDR + SERCOM_SYNCBUSY_OFF)
/** \brief SERCOM1 SYNCBUSY register address */
#define SERCOM1_SYNCBUSY_ADDR (SERCOM1_ADDR + SERCOM_SYNCBUSY_OFF)
/** \brief SERCOM2 SYNCBUSY register address */
#define SERCOM2_SYNCBUSY_ADDR (SERCOM2_ADDR + SERCOM_SYNCBUSY_OFF)
/** \brief SERCOM3 SYNCBUSY register address */
#define SERCOM3_SYNCBUSY_ADDR (SERCOM3_ADDR + SERCOM_SYNCBUSY_OFF)
/** \brief SERCOM4 SYNCBUSY register address */
#define SERCOM4_SYNCBUSY_ADDR (SERCOM4_ADDR + SERCOM_SYNCBUSY_OFF)
/** \brief SERCOM5 SYNCBUSY register address */
#define SERCOM5_SYNCBUSY_ADDR (SERCOM5_ADDR + SERCOM_SYNCBUSY_OFF)

/** \brief SERCOM0 SYNCBUSY register */
#define SERCOM0_SYNCBUSY (*((volatile sercom_syncbusy_t*) SERCOM0_SYNCBUSY_ADDR))
/** \brief SERCOM1 SYNCBUSY register */
#define SERCOM1_SYNCBUSY (*((volatile sercom_syncbusy_t*) SERCOM1_SYNCBUSY_ADDR))
/** \brief SERCOM2 SYNCBUSY register */
#define SERCOM2_SYNCBUSY (*((volatile sercom_syncbusy_t*) SERCOM2_SYNCBUSY_ADDR))
/** \brief SERCOM3 SYNCBUSY register */
#define SERCOM3_SYNCBUSY (*((volatile sercom_syncbusy_t*) SERCOM3_SYNCBUSY_ADDR))
/** \brief SERCOM4 SYNCBUSY register */
#define SERCOM4_SYNCBUSY (*((volatile sercom_syncbusy_t*) SERCOM4_SYNCBUSY_ADDR))
/** \brief SERCOM5 SYNCBUSY register */
#define SERCOM5_SYNCBUSY (*((volatile sercom_syncbusy_t*) SERCOM5_SYNCBUSY_ADDR))

/** \brief SERCOM SYNCBUSY.SWRST bit offset */
#define SERCOM_SYNCBUSY_SWRST_OFF 0u
/** \brief SERCOM SYNCBUSY.SWRST bit mask */
#define SERCOM_SYNCBUSY_SWRST_MSK (0x1u << SERCOM_SYNCBUSY_SWRST_OFF)

/** \brief SERCOM SYNCBUSY.ENABLE bit offset */
#define SERCOM_SYNCBUSY_ENABLE_OFF 1u
/** \brief SERCOM SYNCBUSY.ENABLE bit mask */
#define SERCOM_SYNCBUSY_ENABLE_MSK (0x1u << SERCOM_SYNCBUSY_ENABLE_OFF)

/** \brief SERCOM SYNCBUSY.CTRLB bit offset */
#define SERCOM_SYNCBUSY_CTRLB_OFF 2u
/** \brief SERCOM SYNCBUSY.CTRLB bit mask */
#define SERCOM_SYNCBUSY_CTRLB_MSK (0x1u << SERCOM_SYNCBUSY_CTRLB_OFF)

/**@}*/

#endif /* SAMFD_SERCOM_H */
