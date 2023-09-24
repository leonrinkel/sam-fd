/* SPDX-License-Identifier: MIT */
/**
 * \file      src/uart.c
 * \brief     Implementation of the UART driver
 * \copyright Copyright (c) 2023 Leon Rinkel
 */

#include <stdint.h>

#include <drv/uart.h>

#include <reg/nvic.h>
#include <reg/port.h>
#include <reg/sercom.h>

#define BUFLEN 128

static uint8_t write_buf[BUFLEN];
static uint16_t write_buf_read_idx = 0;
static uint16_t write_buf_write_idx = 0;

void setup_uart(void)
{
	/* Make UART RX/TX pins use port multiplexer */
	PORT_PINCFG5.U |= PORT_PINCFG_PMUXEN_MSK;
	PORT_PINCFG6.U |= PORT_PINCFG_PMUXEN_MSK;

	/* SERCOM0/PAD[1] (UART RX) using peripheral function D */
	PORT_PMUX2.B.PMUXO = 0x3u;
	/* SERCOM0/PAD[2] (UART TX) using peripheral function D */
	PORT_PMUX3.B.PMUXE = 0x3u;

	/* Disable SERCOM0 */
	SERCOM0_CTRLA.B.ENABLE = 0x0u;
	while (SERCOM0_SYNCBUSY.U & SERCOM_SYNCBUSY_ENABLE_MSK);

	/* Configure SERCOM0 for simple 8N1 UART */
	SERCOM0_CTRLA.U =
		(0x0u << SERCOM_CTRLA_SWRST_OFF   ) |
		(0x0u << SERCOM_CTRLA_ENABLE_OFF  ) |
		(0x1u << SERCOM_CTRLA_MODE_OFF    ) |
		(0x0u << SERCOM_CTRLA_RUNSTDBY_OFF) |
		(0x0u << SERCOM_CTRLA_IBON_OFF    ) |
		(0x0u << SERCOM_CTRLA_SAMPR_OFF   ) |
		(0x1u << SERCOM_CTRLA_TXPO_OFF    ) |
		(0x1u << SERCOM_CTRLA_RXPO_OFF    ) |
		(0x0u << SERCOM_CTRLA_SAMPA_OFF   ) |
		(0x0u << SERCOM_CTRLA_FORM_OFF    ) |
		(0x0u << SERCOM_CTRLA_CMODE_OFF   ) |
		(0x0u << SERCOM_CTRLA_CPOL_OFF    ) |
		(0x1u << SERCOM_CTRLA_DORD_OFF    );
	SERCOM0_CTRLB.U =
		(0x0u << SERCOM_CTRLB_CHSIZE_OFF) |
		(0x0u << SERCOM_CTRLB_SBMODE_OFF) |
		(0x0u << SERCOM_CTRLB_COLDEN_OFF) |
		(0x0u << SERCOM_CTRLB_SFDE_OFF  ) |
		(0x0u << SERCOM_CTRLB_ENC_OFF   ) |
		(0x0u << SERCOM_CTRLB_PMODE_OFF ) |
		(0x1u << SERCOM_CTRLB_TXEN_OFF  ) |
		(0x1u << SERCOM_CTRLB_RXEN_OFF  ) |
		(0x0u << SERCOM_CTRLB_LINCMD_OFF);

	/* Baudrate 115200 @ 32MHz core clock */
	SERCOM0_BAUD = 61761;

	/* Enable SERCOM0 interrupts */
	SERCOM0_INTENSET.U =
		SERCOM_INTENSET_TXC_MSK | /* Transmit complete */
		SERCOM_INTENSET_RXC_MSK;  /* Receive complete */
	NVIC_ISER = 0x1u << 9;

	/* Enable SERCOM0 */
	SERCOM0_CTRLA.B.ENABLE = 0x1u;
	while (SERCOM0_SYNCBUSY.U & SERCOM_SYNCBUSY_ENABLE_MSK);
}

uint8_t uart_write_char(uint8_t c)
{
	/* Disable interrupts */
	__asm__ volatile ("cpsid i");

	if (
		/* Write buffer empty */
		(write_buf_write_idx == write_buf_read_idx) &&
		/* Data register empty */
		SERCOM0_INTFLAG.B.DRE
	)
	{
		/* Transmit immediately */
		SERCOM0_DATA.U = (c << SERCOM_DATA_DATA_OFF);

		/* Enable interrupts */
		__asm__ volatile ("cpsie i");

		return 1;
	}
	else if (
		/* Write buffer full */
		(write_buf_write_idx + 1) % BUFLEN ==
			write_buf_read_idx
	)
	{
		/* Enable interrupts */
		__asm__ volatile ("cpsie i");

		/* Discard char */
		return 0;
	}
	else
	{
		/* Put char in buffer */
		write_buf[write_buf_write_idx] = c;
		write_buf_write_idx =
			(write_buf_write_idx + 1) % BUFLEN;

		/* Enable interrupts */
		__asm__ volatile ("cpsie i");

		return 1;
	}
}

void __attribute__((interrupt)) sercom0_handler(void)
{
	if (
		/* Transmit complete */
		SERCOM0_INTFLAG.B.TXC
	)
	{
		if (
			/* Write buffer not empty */
			write_buf_write_idx != write_buf_read_idx
		)
		{
			/* Transmit next char */
			SERCOM0_DATA.U =
				(write_buf[write_buf_read_idx] << SERCOM_DATA_DATA_OFF);
			write_buf_read_idx =
				(write_buf_read_idx + 1) % BUFLEN;
		}
		else /* Write buffer empty */
		{
			/* Only acknowledge interrupt */
			SERCOM0_INTFLAG.U = SERCOM_INTFLAG_TXC_MSK;
		}
	}
}
