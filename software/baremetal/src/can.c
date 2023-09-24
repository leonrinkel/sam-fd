/* SPDX-License-Identifier: MIT */
/**
 * \file      src/drv/can.c
 * \brief     Implementation of the CAN driver
 * \copyright Copyright (c) 2023 Leon Rinkel
 */

#include <stdint.h>

#include <drv/can.h>

#include <reg/can.h>
#include <reg/port.h>

__attribute__((__aligned__(4)))
can_std_filter_t can_std_filter[NUM_STD_FILTER] =
{
	/* Match ID 123 and store in RX buffer 0 */
	{
		.B.SFID2 = 0x0u,
		.B.SFID1 = 0x123u,
		.B.SFEC  = 0x7u,
		.B.SFT   = 0x0u,
	},
};

__attribute__((__aligned__(4)))
can_rx_buffer_t can_rx_buffer[NUM_RX_BUFFER];

__attribute__((__aligned__(4)))
can_tx_buffer_t can_tx_buffer[NUM_TX_BUFFER];

void setup_can(void)
{
	/* Set initialization */
	CAN0_CCCR.U |= CAN_CCCR_INIT_MSK;
	while (!CAN0_CCCR.B.INIT);
	/* Set configuration change enable */
	CAN0_CCCR.U |= CAN_CCCR_CCE_MSK;
	while (!CAN0_CCCR.B.CCE);

	/* Configure nominal timing for 500kbit/s @ 32MHz core clock */
	CAN0_NBTP.U =
		(0x0Fu << CAN_NBTP_NTSEG2_OFF) |
		(0x2Eu << CAN_NBTP_NTSEG1_OFF) |
		(0x00u << CAN_NBTP_NBRP_OFF  ) |
		(0x0Fu << CAN_NBTP_NSJW_OFF  );

	/* Configure standard ID filter */
	CAN0_SIDFC.U =
		((uint32_t) can_std_filter << CAN_SIDFC_FLSSA_OFF) |
		(NUM_STD_FILTER            << CAN_SIDFC_LSS_OFF  );

	/* Configure RX buffer */
	CAN0_RXESC.U =
		(0x7u << CAN_RXESC_F0DS_OFF) |
		(0x7u << CAN_RXESC_F1DS_OFF) |
		(0x7u << CAN_RXESC_RBDS_OFF);
	CAN0_RXBC.U =
		((uint32_t) can_rx_buffer << CAN_RXBC_RBSA_OFF);

	/* Configure TX buffer */
	CAN0_TXESC.U = (0x7u << CAN_TXESC_TBDS_OFF);
	CAN0_TXBC.U =
		((uint32_t) can_tx_buffer << CAN_TXBC_TBSA_OFF) |
		(NUM_TX_BUFFER            << CAN_TXBC_NDTB_OFF) |
		(0x0u                     << CAN_TXBC_TFQS_OFF) |
		(0x0u                     << CAN_TXBC_TFQM_OFF);

	/* Clear configuration change enable */
	CAN0_CCCR.U &= ~CAN_CCCR_CCE_MSK;
	while (CAN0_CCCR.B.CCE);
	/* Clear initialization */
	CAN0_CCCR.U &= ~CAN_CCCR_INIT_MSK;
	while (CAN0_CCCR.B.INIT);

	/* Make CAN RX/TX pins use port multiplexer */
	PORT_PINCFG24.U |= PORT_PINCFG_PMUXEN_MSK;
	PORT_PINCFG25.U |= PORT_PINCFG_PMUXEN_MSK;

	/* CAN0/TX using peripheral function G */
	PORT_PMUX12.B.PMUXO = 0x6u;
	/* CAN0/RX using peripheral function G */
	PORT_PMUX12.B.PMUXE = 0x6u;

	/* Configure transceiver EN/STB pins as output */
	PORT_DIR.U |=
		PORT_DIR_DIR18_MSK |
		PORT_DIR_DIR27_MSK;

	/* Turn transceiver on */
	PORT_OUT.B.OUT18 = 1; /* EN */
	PORT_OUT.B.OUT27 = 1; /* STB */
}
