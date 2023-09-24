/* SPDX-License-Identifier: MIT */
/**
 * \file      inc/drv/can.h
 * \brief     Declaration related to the CAN driver
 * \copyright Copyright (c) 2023 Leon Rinkel
 */

#ifndef SAMFD_DRV_CAN_H
#define SAMFD_DRV_CAN_H

#include <stdint.h>

#define NUM_STD_FILTER 1
#define NUM_RX_BUFFER  1
#define NUM_TX_BUFFER  1

/** \name CAN RX buffer element */
/**@{*/

/** \brief CAN RX buffer element structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U[18];
	/** \brief Bitfield access */
	struct
	{
		/** \brief Identifier */
		uint32_t ID:29;
		/** \brief Remote transmission request */
		uint32_t RTR:1;
		/** \brief Extended identifier */
		uint32_t XTD:1;
		/** \brief Error state indicator */
		uint32_t ESI:1;
		/** \brief RX timestamp */
		uint32_t RXTS:16;
		/** \brief Data length code */
		uint32_t DLC:4;
		/** \brief Bit rate switching */
		uint32_t BRS:1;
		/** \brief FD format */
		uint32_t FDF:1;
		/** \brief Reserved */
		uint32_t :2;
		/** \brief Filter index */
		uint32_t FIDX:7;
		/** \brief Accepted non-matching frame */
		uint32_t ANMF:1;
		/** \brief Data bytes */
		uint8_t DB[64];
	} B;
} can_rx_buffer_t;

/** \brief CAN RX buffer standard ID bit offset */
#define CAN_RX_BUFFER_STD_ID_OFF 18u
/** \brief CAN RX buffer standard ID bit mask */
#define CAN_RX_BUFFER_STD_ID_MSK (0x7FFu << CAN_RX_BUFFER_STD_ID_OFF)

/** \brief CAN RX buffer extended ID bit offset */
#define CAN_RX_BUFFER_XTD_ID_OFF 0u
/** \brief CAN RX buffer extended ID bit mask */
#define CAN_RX_BUFFER_XTD_ID_MSK (0x3FFFFFFFu << CAN_RX_BUFFER_XTD_ID_OFF)

/** \brief CAN RX buffer RTR bit offset */
#define CAN_RX_BUFFER_RTR_OFF 29u
/** \brief CAN RX buffer RTR bit mask */
#define CAN_RX_BUFFER_RTR_MSK (0x1u << CAN_RX_BUFFER_RTR_OFF)

/** \brief CAN RX buffer XTD bit offset */
#define CAN_RX_BUFFER_XTD_OFF 30u
/** \brief CAN RX buffer XTD bit mask */
#define CAN_RX_BUFFER_XTD_MSK (0x1u << CAN_RX_BUFFER_XTD_OFF)

/** \brief CAN RX buffer ESI bit offset */
#define CAN_RX_BUFFER_ESI_OFF 31u
/** \brief CAN RX buffer ESI bit mask */
#define CAN_RX_BUFFER_ESI_MSK (0x1u << CAN_RX_BUFFER_ESI_OFF)

/** \brief CAN RX buffer RXTS bit offset */
#define CAN_RX_BUFFER_RXTS_OFF 0u
/** \brief CAN RX buffer RXTS bit mask */
#define CAN_RX_BUFFER_RXTS_MSK (0xFFFFu << CAN_RX_BUFFER_RXTS_OFF)

/** \brief CAN RX buffer DLC bit offset */
#define CAN_RX_BUFFER_DLC_OFF 16u
/** \brief CAN RX buffer DLC bit mask */
#define CAN_RX_BUFFER_DLC_MSK (0xFu << CAN_RX_BUFFER_DLC_OFF)

/** \brief CAN RX buffer BRS bit offset */
#define CAN_RX_BUFFER_BRS_OFF 20u
/** \brief CAN RX buffer BRS bit mask */
#define CAN_RX_BUFFER_BRS_MSK (0x1u << CAN_RX_BUFFER_BRS_OFF)

/** \brief CAN RX buffer FDF bit offset */
#define CAN_RX_BUFFER_FDF_OFF 21u
/** \brief CAN RX buffer FDF bit mask */
#define CAN_RX_BUFFER_FDF_MSK (0x1u << CAN_RX_BUFFER_FDF_OFF)

/** \brief CAN RX buffer FIDX bit offset */
#define CAN_RX_BUFFER_FIDX_OFF 24u
/** \brief CAN RX buffer FIDX bit mask */
#define CAN_RX_BUFFER_FIDX_MSK (0x7Fu << CAN_RX_BUFFER_FIDX_OFF)

/** \brief CAN RX buffer ANMF bit offset */
#define CAN_RX_BUFFER_ANMF_OFF 31u
/** \brief CAN RX buffer ANMF bit mask */
#define CAN_RX_BUFFER_ANMF_MSK (0x1u << CAN_RX_BUFFER_ANMF_OFF)

/**@}*/

/** \name CAN TX buffer element */
/**@{*/

/** \brief CAN TX buffer element structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U[18];
	/** \brief Bitfield access */
	struct
	{
		/** \brief Identifier */
		uint32_t ID:29;
		/** \brief Remote transmission request */
		uint32_t RTR:1;
		/** \brief Extended identifier */
		uint32_t XTD:1;
		/** \brief Error state indicator */
		uint32_t ESI:1;
		/** \brief Reserved */
		uint32_t :16;
		/** \brief Data length code */
		uint32_t DLC:4;
		/** \brief Bit rate search */
		uint32_t BRS:1;
		/** \brief FD format */
		uint32_t FDF:1;
		/** \brief Reserved */
		uint32_t :1;
		/** \brief Event fifo control */
		uint32_t EFC:1;
		/** \brief Message marker */
		uint32_t MM:8;
		/** \brief Data bytes */
		uint8_t DB[64];
	} B;
} can_tx_buffer_t;

/** \brief CAN TX buffer standard ID bit offset */
#define CAN_TX_BUFFER_STD_ID_OFF 18u
/** \brief CAN TX buffer standard ID bit mask */
#define CAN_TX_BUFFER_STD_ID_MSK (0x7FFu << CAN_TX_BUFFER_STD_ID_OFF)

/** \brief CAN TX buffer extended ID bit offset */
#define CAN_TX_BUFFER_XTD_ID_OFF 0u
/** \brief CAN TX buffer extended ID bit mask */
#define CAN_TX_BUFFER_XTD_ID_MSK (0x3FFFFFFFu << CAN_TX_BUFFER_XTD_ID_OFF)

/** \brief CAN TX buffer RTR bit offset */
#define CAN_TX_BUFFER_RTR_OFF 29u
/** \brief CAN TX buffer RTR bit mask */
#define CAN_TX_BUFFER_RTR_MSK (0x1u << CAN_TX_BUFFER_RTR_OFF)

/** \brief CAN TX buffer XTD bit offset */
#define CAN_TX_BUFFER_XTD_OFF 30u
/** \brief CAN TX buffer XTD bit mask */
#define CAN_TX_BUFFER_XTD_MSK (0x1u << CAN_TX_BUFFER_XTD_OFF)

/** \brief CAN TX buffer ESI bit offset */
#define CAN_TX_BUFFER_ESI_OFF 31u
/** \brief CAN TX buffer ESI bit mask */
#define CAN_TX_BUFFER_ESI_MSK (0x1u << CAN_TX_BUFFER_ESI_OFF)

/** \brief CAN TX buffer DLC bit offset */
#define CAN_TX_BUFFER_DLC_OFF 16u
/** \brief CAN TX buffer DLC bit mask */
#define CAN_TX_BUFFER_DLC_MSK (0xFu << CAN_TX_BUFFER_DLC_OFF)

/** \brief CAN TX buffer BRS bit offset */
#define CAN_TX_BUFFER_BRS_OFF 20u
/** \brief CAN TX buffer BRS bit mask */
#define CAN_TX_BUFFER_BRS_MSK (0x1u << CAN_TX_BUFFER_BRS_OFF)

/** \brief CAN TX buffer FDF bit offset */
#define CAN_TX_BUFFER_FDF_OFF 21u
/** \brief CAN TX buffer FDF bit mask */
#define CAN_TX_BUFFER_FDF_MSK (0x1u << CAN_TX_BUFFER_FDF_OFF)

/** \brief CAN TX buffer EFC bit offset */
#define CAN_TX_BUFFER_EFC_OFF 23u
/** \brief CAN TX buffer EFC bit mask */
#define CAN_TX_BUFFER_EFC_MSK (0x1u << CAN_TX_BUFFER_EFC_OFF)

/** \brief CAN TX buffer MM bit offset */
#define CAN_TX_BUFFER_MM_OFF 24u
/** \brief CAN TX buffer MM bit mask */
#define CAN_TX_BUFFER_MM_MSK (0xFFu << CAN_TX_BUFFER_MM_OFF)

/**@}*/

/** \name CAN standard filter element */
/**@{*/

/** \brief CAN standard filter element structure */
typedef union
{
	/** \brief Unsigned access */
	uint32_t U;
	/** \brief Bitfield access */
	struct
	{
		/** \brief Standard filter id 2 */
		uint32_t SFID2:11;
		/** \brief Reserved */
		uint32_t :5;
		/** \brief Standard filter id 1 */
		uint32_t SFID1:11;
		/** \brief Standard filter element configuration */
		uint32_t SFEC:3;
		/** \brief Standard filter type */
		uint32_t SFT:2;
	} B;
} can_std_filter_t;

/** \brief CAN standard filter SFID2 bit offset */
#define CAN_STD_FILTER_SFID2_OFF 0u
/** \brief CAN standard filter SFID2 bit mask */
#define CAN_STD_FILTER_SFID2_MSK (0x7FFu << CAN_STD_FILTER_SFID2_OFF)

/** \brief CAN standard filter SFID1 bit offset */
#define CAN_STD_FILTER_SFID1_OFF 16u
/** \brief CAN standard filter SFID1 bit mask */
#define CAN_STD_FILTER_SFID1_MSK (0x7FFu << CAN_STD_FILTER_SFID1_OFF)

/** \brief CAN standard filter SFEC bit offset */
#define CAN_STD_FILTER_SFEC_OFF 27u
/** \brief CAN standard filter SFEC bit mask */
#define CAN_STD_FILTER_SFEC_MSK (0x7u << CAN_STD_FILTER_SFEC_OFF)

/** \brief CAN standard filter SFT bit offset */
#define CAN_STD_FILTER_SFT_OFF 30u
/** \brief CAN standard filter SFT bit mask */
#define CAN_STD_FILTER_SFT_MSK (0x3u << CAN_STD_FILTER_SFT_OFF)

/**@}*/

extern can_std_filter_t can_std_filter[NUM_STD_FILTER];
extern can_rx_buffer_t can_rx_buffer[NUM_RX_BUFFER];
extern can_tx_buffer_t can_tx_buffer[NUM_TX_BUFFER];

void setup_can(void);

#endif /* SAMFD_DRV_CAN_H */
