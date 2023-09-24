/* SPDX-License-Identifier: MIT */
/**
 * \file      inc/reg/can.h
 * \brief     Definitions regarding CAN registers structure
 * \copyright Copyright (c) 2023 Leon Rinkel
 */

#ifndef SAMFD_REG_CAN_H
#define SAMFD_REG_CAN_H

#include <stdint.h>

/** \brief CAN0 registers base address */
#define CAN0_ADDR 0x42001C00u
/** \brief CAN1 registers base address */
#define CAN1_ADDR 0x42002000u

/** \name CAN DBTP register */
/**@{*/

/** \brief CAN DBTP register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Data (re)syncronization jump width */
		uint32_t DSJW:4;
		/** \brief Data time segment after sample point */
		uint32_t DTSEG2:4;
		/** \brief Fast time segment before sample point */
		uint32_t DTSEG1:5;
		/** \brief Reserved */
		uint32_t :3;
		/** \brief Data baud rate prescaler */
		uint32_t DBRP:5;
		/** \brief Reserved */
		uint32_t :2;
		/** \brief Transceiver delay compensation */
		uint32_t TDC:1;
		/** \brief Reserved */
		uint32_t :8;
	} B;
} can_dbtp_t;

/** \brief CAN DBTP register address offset */
#define CAN_DBTP_OFF 0x0Cu

/** \brief CAN0 DBTP register address */
#define CAN0_DBTP_ADDR (CAN0_ADDR + CAN_DBTP_OFF)
/** \brief CAN1 DBTP register address */
#define CAN1_DBTP_ADDR (CAN1_ADDR + CAN_DBTP_OFF)

/** \brief CAN0 DBTP register */
#define CAN0_DBTP (*((volatile can_dbtp_t*) CAN0_DBTP_ADDR))
/** \brief CAN1 DBTP register */
#define CAN1_DBTP (*((volatile can_dbtp_t*) CAN1_DBTP_ADDR))

/** \brief CAN DBTP.DSJW bit offset */
#define CAN_DBTP_DSJW_OFF 0u
/** \brief CAN DBTP.DSJW bit mask */
#define CAN_DBTP_DSJW_MSK (0xFu << CAN_DBTP_DSJW_OFF)

/** \brief CAN DBTP.DTSEG2 bit offset */
#define CAN_DBTP_DTSEG2_OFF 4u
/** \brief CAN DBTP.DTSEG2 bit mask */
#define CAN_DBTP_DTSEG2_MSK (0xFu << CAN_DBTP_DTSEG2_OFF)

/** \brief CAN DBTP.DTSEG1 bit offset */
#define CAN_DBTP_DTSEG1_OFF 8u
/** \brief CAN DBTP.DTSEG1 bit mask */
#define CAN_DBTP_DTSEG1_MSK (0x1Fu << CAN_DBTP_DTSEG1_OFF)

/** \brief CAN DBTP.DBRP bit offset */
#define CAN_DBTP_DBRP_OFF 16u
/** \brief CAN DBTP.DBRP bit mask */
#define CAN_DBTP_DBRP_MSK (0x1Fu << CAN_DBTP_DBRP_OFF)

/** \brief CAN DBTP.TDC bit offset */
#define CAN_DBTP_TDC_OFF 23u
/** \brief CAN DBTP.TDC bit mask */
#define CAN_DBTP_TDC_MSK (0x1u << CAN_DBTP_TDC_OFF)

/**@}*/

/** \name CAN TEST register */
/**@{*/

/** \brief CAN TEST register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Reserved */
		uint32_t :4;
		/** \brief Loop back mode */
		uint32_t LBCK:1;
		/** \brief Control of transmit pin */
		uint32_t TX:2;
		/** \brief Receive pin */
		uint32_t RX:1;
		/** \brief Reserved */
		uint32_t :8;
		/** \brief Reserved */
		uint32_t :16;
	} B;
} can_test_t;

/** \brief CAN TEST register address offset */
#define CAN_TEST_OFF 0x10u

/** \brief CAN0 TEST register address */
#define CAN0_TEST_ADDR (CAN0_ADDR + CAN_TEST_OFF)
/** \brief CAN1 TEST register address */
#define CAN1_TEST_ADDR (CAN1_ADDR + CAN_TEST_OFF)

/** \brief CAN0 TEST register */
#define CAN0_TEST (*((volatile can_test_t*) CAN0_TEST_ADDR))
/** \brief CAN1 TEST register */
#define CAN1_TEST (*((volatile can_test_t*) CAN1_TEST_ADDR))

/** \brief CAN TEST.LBCK bit offset */
#define CAN_TEST_LBCK_OFF 4u
/** \brief CAN TEST.LBCK bit mask */
#define CAN_TEST_LBCK_MSK (0x1u << CAN_TEST_LBCK_OFF)

/** \brief CAN TEST.TX bit offset */
#define CAN_TEST_TX_OFF 5u
/** \brief CAN TEST.TX bit mask */
#define CAN_TEST_TX_MSK (0x3u << CAN_TEST_TX_OFF)

/** \brief CAN TEST.RX bit offset */
#define CAN_TEST_RX_OFF 7u
/** \brief CAN TEST.RX bit mask */
#define CAN_TEST_RX_MSK (0x1u << CAN_TEST_RX_OFF)

/**@}*/

/** \name CAN CCCR register */
/**@{*/

/** \brief CAN CCCR register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Initialization */
		uint32_t INIT:1;
		/** \brief Configuration change enable */
		uint32_t CCE:1;
		/** \brief Restricted operation mode */
		uint32_t ASM:1;
		/** \brief Clock stop acknowledge */
		uint32_t CSA:1;
		/** \brief Clock stop request */
		uint32_t CSR:1;
		/** \brief Bus monitoring mode */
		uint32_t MON:1;
		/** \brief Disable automatic retransmission */
		uint32_t DAR:1;
		/** \brief Test mode enable */
		uint32_t TEST:1;
		/** \brief FD operation enable */
		uint32_t FDOE:1;
		/** \brief Bit rate switch enable */
		uint32_t BRSE:1;
		/** \brief Reserved */
		uint32_t :2;
		/** \brief Protocol exception handling disable */
		uint32_t PXHD:1;
		/** \brief Edge filtering during bus integration */
		uint32_t EFBI:1;
		/** \brief Transmit pause */
		uint32_t TXP:1;
		/** \brief Non ISO operation */
		uint32_t NISO:1;
		/** \brief Reserved */
		uint32_t :16;
	} B;
} can_cccr_t;

/** \brief CAN CCCR register address offset */
#define CAN_CCCR_OFF 0x18u

/** \brief CAN0 CCCR register address */
#define CAN0_CCCR_ADDR (CAN0_ADDR + CAN_CCCR_OFF)
/** \brief CAN1 CCCR register address */
#define CAN1_CCCR_ADDR (CAN1_ADDR + CAN_CCCR_OFF)

/** \brief CAN0 CCCR register */
#define CAN0_CCCR (*((volatile can_cccr_t*) CAN0_CCCR_ADDR))
/** \brief CAN1 CCCR register */
#define CAN1_CCCR (*((volatile can_cccr_t*) CAN1_CCCR_ADDR))

/** \brief CAN CCCR.INIT bit offset */
#define CAN_CCCR_INIT_OFF 0u
/** \brief CAN CCCR.INIT bit mask */
#define CAN_CCCR_INIT_MSK (0x1u << CAN_CCCR_INIT_OFF)

/** \brief CAN CCCR.CCE bit offset */
#define CAN_CCCR_CCE_OFF 1u
/** \brief CAN CCCR.CCE bit mask */
#define CAN_CCCR_CCE_MSK (0x1u << CAN_CCCR_CCE_OFF)

/** \brief CAN CCCR.ASM bit offset */
#define CAN_CCCR_ASM_OFF 2u
/** \brief CAN CCCR.ASM bit mask */
#define CAN_CCCR_ASM_MSK (0x1u << CAN_CCCR_ASM_OFF)

/** \brief CAN CCCR.CSA bit offset */
#define CAN_CCCR_CSA_OFF 3u
/** \brief CAN CCCR.CSA bit mask */
#define CAN_CCCR_CSA_MSK (0x1u << CAN_CCCR_CSA_OFF)

/** \brief CAN CCCR.CSR bit offset */
#define CAN_CCCR_CSR_OFF 4u
/** \brief CAN CCCR.CSR bit mask */
#define CAN_CCCR_CSR_MSK (0x1u << CAN_CCCR_CSR_OFF)

/** \brief CAN CCCR.MON bit offset */
#define CAN_CCCR_MON_OFF 5u
/** \brief CAN CCCR.MON bit mask */
#define CAN_CCCR_MON_MSK (0x1u << CAN_CCCR_MON_OFF)

/** \brief CAN CCCR.DAR bit offset */
#define CAN_CCCR_DAR_OFF 6u
/** \brief CAN CCCR.DAR bit mask */
#define CAN_CCCR_DAR_MSK (0x1u << CAN_CCCR_DAR_OFF)

/** \brief CAN CCCR.TEST bit offset */
#define CAN_CCCR_TEST_OFF 7u
/** \brief CAN CCCR.TEST bit mask */
#define CAN_CCCR_TEST_MSK (0x1u << CAN_CCCR_TEST_OFF)

/** \brief CAN CCCR.FDOE bit offset */
#define CAN_CCCR_FDOE_OFF 8u
/** \brief CAN CCCR.FDOE bit mask */
#define CAN_CCCR_FDOE_MSK (0x1u << CAN_CCCR_FDOE_OFF)

/** \brief CAN CCCR.BRSE bit offset */
#define CAN_CCCR_BRSE_OFF 9u
/** \brief CAN CCCR.BRSE bit mask */
#define CAN_CCCR_BRSE_MSK (0x1u << CAN_CCCR_BRSE_OFF)

/** \brief CAN CCCR.PXHD bit offset */
#define CAN_CCCR_PXHD_OFF 12u
/** \brief CAN CCCR.PXHD bit mask */
#define CAN_CCCR_PXHD_MSK (0x1u << CAN_CCCR_PXHD_OFF)

/** \brief CAN CCCR.EFBI bit offset */
#define CAN_CCCR_EFBI_OFF 13u
/** \brief CAN CCCR.EFBI bit mask */
#define CAN_CCCR_EFBI_MSK (0x1u << CAN_CCCR_EFBI_OFF)

/** \brief CAN CCCR.TXP bit offset */
#define CAN_CCCR_TXP_OFF 14u
/** \brief CAN CCCR.TXP bit mask */
#define CAN_CCCR_TXP_MSK (0x1u << CAN_CCCR_TXP_OFF)

/** \brief CAN CCCR.NISO bit offset */
#define CAN_CCCR_NISO_OFF 15u
/** \brief CAN CCCR.NISO bit mask */
#define CAN_CCCR_NISO_MSK (0x1u << CAN_CCCR_NISO_OFF)

/**@}*/

/** \name CAN NBTP register */
/**@{*/

/** \brief CAN NBTP register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Time segment after sample point */
		uint32_t NTSEG2:7;
		/** \brief Reserved */
		uint32_t :1;
		/** \brief Nominal time segment before sample point */
		uint32_t NTSEG1:8;
		/** \brief Nominal baud rate prescaler */
		uint32_t NBRP:9;
		/** \brief Nominal (re)syncronization jump width */
		uint32_t NSJW:7;
	} B;
} can_nbtp_t;

/** \brief CAN NBTP register address offset */
#define CAN_NBTP_OFF 0x1Cu

/** \brief CAN0 NBTP register address */
#define CAN0_NBTP_ADDR (CAN0_ADDR + CAN_NBTP_OFF)
/** \brief CAN1 NBTP register address */
#define CAN1_NBTP_ADDR (CAN1_ADDR + CAN_NBTPOFF)

/** \brief CAN0 NBTP register */
#define CAN0_NBTP (*((volatile can_nbtp_t*) CAN0_NBTP_ADDR))
/** \brief CAN1 NBTP register */
#define CAN1_NBTP (*((volatile can_nbtp_t*) CAN1_NBTP_ADDR))

/** \brief CAN NBTP.NTSEG2 bit offset */
#define CAN_NBTP_NTSEG2_OFF 0u
/** \brief CAN NBTP.NTSEG2 bit mask */
#define CAN_NBTP_NTSEG2_MSK (0x7Fu << CAN_NBTP_NTSEG2_OFF)

/** \brief CAN NBTP.NTSEG1 bit offset */
#define CAN_NBTP_NTSEG1_OFF 8u
/** \brief CAN NBTP.NTSEG1 bit mask */
#define CAN_NBTP_NTSEG1_MSK (0xFu << CAN_NBTP_NTSEG1_OFF)

/** \brief CAN NBTP.NBRP bit offset */
#define CAN_NBTP_NBRP_OFF 16u
/** \brief CAN NBTP.NBRP bit mask */
#define CAN_NBTP_NBRP_MSK (0x1FFu << CAN_NBTP_NBRP_OFF)

/** \brief CAN NBTP.NSJW bit offset */
#define CAN_NBTP_NSJW_OFF 25u
/** \brief CAN NBTP.NSJW bit mask */
#define CAN_NBTP_NSJW_MSK (0x7Fu << CAN_NBTP_NSJW_OFF)

/**@}*/

/** \name CAN SIDFC register */
/**@{*/

/** \brief CAN SIDFC register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Filter list standard start address */
		uint32_t FLSSA:16;
		/** \brief List size standard */
		uint32_t LSS:8;
		/** \brief Reserved */
		uint32_t :8;
	} B;
} can_sidfc_t;

/** \brief CAN SIDFC register address offset */
#define CAN_SIDFC_OFF 0x84u

/** \brief CAN0 SIDFC register address */
#define CAN0_SIDFC_ADDR (CAN0_ADDR + CAN_SIDFC_OFF)
/** \brief CAN1 SIDFC register address */
#define CAN1_SIDFC_ADDR (CAN1_ADDR + CAN_SIDFC_OFF)

/** \brief CAN0 SIDFC register */
#define CAN0_SIDFC (*((volatile can_sidfc_t*) CAN0_SIDFC_ADDR))
/** \brief CAN1 SIDFC register */
#define CAN1_SIDFC (*((volatile can_sidfc_t*) CAN1_SIDFC_ADDR))

/** \brief CAN SIDFC.FLSSA bit offset */
#define CAN_SIDFC_FLSSA_OFF 0u
/** \brief CAN SIDFC.FLSSA bit mask */
#define CAN_SIDFC_FLSSA_MSK (0xFFFFu << CAN_SIDFC_FLSSA_OFF)

/** \brief CAN SIDFC.LSS bit offset */
#define CAN_SIDFC_LSS_OFF 16u
/** \brief CAN SIDFC.LSS bit mask */
#define CAN_SIDFC_LSS_MSK (0xFu << CAN_SIDFC_LSS_OFF)

/**@}*/

/** \name CAN RXBC register */
/**@{*/

/** \brief CAN RXBC register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief RX buffer start address */
		uint32_t RBSA:16;
		/** \brief Reserved */
		uint32_t :16;
	} B;
} can_rxbc_t;

/** \brief CAN RXBC register address offset */
#define CAN_RXBC_OFF 0xACu

/** \brief CAN0 RXBC register address */
#define CAN0_RXBC_ADDR (CAN0_ADDR + CAN_RXBC_OFF)
/** \brief CAN1 RXBC register address */
#define CAN1_RXBC_ADDR (CAN1_ADDR + CAN_RXBC_OFF)

/** \brief CAN0 RXBC register */
#define CAN0_RXBC (*((volatile can_rxbc_t*) CAN0_RXBC_ADDR))
/** \brief CAN1 RXBC register */
#define CAN1_RXBC (*((volatile can_rxbc_t*) CAN1_RXBC_ADDR))

/** \brief CAN RXBC.RBSA bit offset */
#define CAN_RXBC_RBSA_OFF 0u
/** \brief CAN RXBC.RBSA bit mask */
#define CAN_RXBC_RBSA_MSK (0xFFFFu << CAN_RXBC_RBSA_OFF)

/**@}*/

/** \name CAN RXESC register */
/**@{*/

/** \brief CAN RXESC register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Rx FIFO 0 Data Field Size */
		uint32_t F0DS:3;
		/** \brief Reserved */
		uint32_t :1;
		/** \brief Rx FIFO 1 Data Field Size */
		uint32_t F1DS:3;
		/** \brief Reserved */
		uint32_t :1;
		/** \brief Rx Buffer Data Field Size */
		uint32_t RBDS:3;
		/** \brief Reserved */
		uint32_t :5;
		/** \brief Reserved */
		uint32_t :16;
	} B;
} can_rxesc_t;

/** \brief CAN RXESC register address offset */
#define CAN_RXESC_OFF 0xBCu

/** \brief CAN0 RXESC register address */
#define CAN0_RXESC_ADDR (CAN0_ADDR + CAN_RXESC_OFF)
/** \brief CAN1 RXESC register address */
#define CAN1_RXESC_ADDR (CAN1_ADDR + CAN_RXESC_OFF)

/** \brief CAN0 RXESC register */
#define CAN0_RXESC (*((volatile can_rxesc_t*) CAN0_RXESC_ADDR))
/** \brief CAN1 RXESC register */
#define CAN1_RXESC (*((volatile can_rxesc_t*) CAN1_RXESC_ADDR))

/** \brief CAN RXESC.F0DS bit offset */
#define CAN_RXESC_F0DS_OFF 0u
/** \brief CAN RXESC.F0DS bit mask */
#define CAN_RXESC_F0DS_MSK (0x7u << CAN_RXESC_F0DS_OFF)

/** \brief CAN RXESC.F1DS bit offset */
#define CAN_RXESC_F1DS_OFF 4u
/** \brief CAN RXESC.F1DS bit mask */
#define CAN_RXESC_F1DS_MSK (0x7u << CAN_RXESC_F1DS_OFF)

/** \brief CAN RXESC.RBDS bit offset */
#define CAN_RXESC_RBDS_OFF 8u
/** \brief CAN RXESC.RBDS bit mask */
#define CAN_RXESC_RBDS_MSK (0x7u << CAN_RXESC_RBDS_OFF)

/**@}*/

/** \name CAN TXBC register */
/**@{*/

/** \brief CAN TXBC register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief TX buffers start address */
		uint32_t TBSA:16;
		/** \brief Number of dedicated transmit buffers */
		uint32_t NDTB:6;
		/** \brief Reserved */
		uint32_t :2;
		/** \brief Transmit FIFO/queue size */
		uint32_t TFQS:6;
		/** \brief TX FIFO/queue mode */
		uint32_t TFQM:1;
		/** \brief Reserved */
		uint32_t :1;
	} B;
} can_txbc_t;

/** \brief CAN TXBC register address offset */
#define CAN_TXBC_OFF 0xC0u

/** \brief CAN0 TXBC register address */
#define CAN0_TXBC_ADDR (CAN0_ADDR + CAN_TXBC_OFF)
/** \brief CAN1 RXESC register address */
#define CAN1_TXBC_ADDR (CAN1_ADDR + CAN_TXBC_OFF)

/** \brief CAN0 TXBC register */
#define CAN0_TXBC (*((volatile can_txbc_t*) CAN0_TXBC_ADDR))
/** \brief CAN1 TXBC register */
#define CAN1_TXBC (*((volatile can_txbc_t*) CAN1_TXBC_ADDR))

/** \brief CAN TXBC.TBSA bit offset */
#define CAN_TXBC_TBSA_OFF 0u
/** \brief CAN TXBC.TBSA bit mask */
#define CAN_TXBC_TBSA_MSK (0xFFFFu << CAN_TXBC_TBSA_OFF)

/** \brief CAN TXBC.NDTB bit offset */
#define CAN_TXBC_NDTB_OFF 16u
/** \brief CAN TXBC.NDTB bit mask */
#define CAN_TXBC_NDTB_MSK (0x3Fu << CAN_TXBC_NDTB_OFF)

/** \brief CAN TXBC.TFQS bit offset */
#define CAN_TXBC_TFQS_OFF 24u
/** \brief CAN TXBC.TFQS bit mask */
#define CAN_TXBC_TFQS_MSK (0x3Fu << CAN_TXBC_TFQS_OFF)

/** \brief CAN TXBC.TFQM bit offset */
#define CAN_TXBC_TFQM_OFF 30u
/** \brief CAN TXBC.TFQM bit mask */
#define CAN_TXBC_TFQM_MSK (0x1u << CAN_TXBC_TFQM_OFF)

/**@}*/

/** \name CAN TXESC register */
/**@{*/

/** \brief CAN TXESC register structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief TX buffer data field size */
		uint32_t TBDS:3;
		/** \brief Reserved */
		uint32_t :5;
		/** \brief Reserved */
		uint32_t :8;
		/** \brief Reserved */
		uint32_t :16;
	} B;
} can_txesc_t;

/** \brief CAN TXESC register address offset */
#define CAN_TXESC_OFF 0xC8u

/** \brief CAN0 TXESC register address */
#define CAN0_TXESC_ADDR (CAN0_ADDR + CAN_TXESC_OFF)
/** \brief CAN1 TXESC register address */
#define CAN1_TXESC_ADDR (CAN1_ADDR + CAN_TXESC_OFF)

/** \brief CAN0 TXESC register */
#define CAN0_TXESC (*((volatile can_txesc_t*) CAN0_TXESC_ADDR))
/** \brief CAN1 TXESC register */
#define CAN1_TXESC (*((volatile can_txesc_t*) CAN1_TXESC_ADDR))

/** \brief CAN TXESC.TBDS bit offset */
#define CAN_TXESC_TBDS_OFF 0u
/** \brief CAN TXESC.TBDS bit mask */
#define CAN_TXESC_TBDS_MSK (0x3u << CAN_TXESC_TBDS_OFF)

/**@}*/

/** \name CAN TXBAR register */
/**@{*/

/** \brief CAN TXBAR register address offset */
#define CAN_TXBAR_OFF 0xD0u

/** \brief CAN0 TXBAR register address */
#define CAN0_TXBAR_ADDR (CAN0_ADDR + CAN_TXBAR_OFF)
/** \brief CAN1 TXBAR register address */
#define CAN1_TXBAR_ADDR (CAN1_ADDR + CAN_TXBAR_OFF)

/** \brief CAN0 TXBAR register */
#define CAN0_TXBAR (*((volatile uint32_t*) CAN0_TXBAR_ADDR))
/** \brief CAN1 TXBAR register */
#define CAN1_TXBAR (*((volatile uint32_t*) CAN1_TXBAR_ADDR))

/**@}*/

#endif /* SAMFD_REG_CAN_H */
