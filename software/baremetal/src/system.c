/* SPDX-License-Identifier: MIT */
/**
 * \file      src/system.c
 * \brief     Implementation of low-level processor stuff such as the vector table
 * \copyright Copyright (c) 2023 Leon Rinkel
 */

#include <stdint.h>
#include <stdbool.h>

#include <drv/uart.h>
#include <drv/flash.h>
#include <drv/can.h>

#include <reg/can.h>
#include <reg/dsu.h>
#include <reg/gclk.h>
#include <reg/mclk.h>
#include <reg/nvic.h>
#include <reg/nvmctrl.h>
#include <reg/oscctrl.h>
#include <reg/pac.h>
#include <reg/port.h>
#include <reg/scb.h>
#include <reg/sercom.h>
#include <reg/syst.h>

#include <linked.h>
#include <system.h>

void setup_clocks(void);
void setup_systick(void);
void setup_leds(void);

void task_1ms(void);
void task_10ms(void);
void task_100ms(void);
void task_1000ms(void);

static const uint8_t some_data[256] =
{
	0xABu, 0x14u, 0xF8u, 0xC8u, 0x04u, 0x8Eu, 0xF1u, 0xEFu, 0xD2u, 0x05u, 0xD3u, 0x49u, 0x81u, 0x5Bu, 0xDEu, 0x75u,
	0x97u, 0x17u, 0x9Bu, 0xAEu, 0x33u, 0x2Bu, 0x0Bu, 0x5Eu, 0xFCu, 0x37u, 0x68u, 0x8Cu, 0x06u, 0x4Cu, 0xE6u, 0x04u,
	0x14u, 0x76u, 0x63u, 0x5Cu, 0x40u, 0x8Du, 0xA7u, 0x9Au, 0xC0u, 0xB7u, 0xB0u, 0xDFu, 0xE4u, 0x50u, 0xE8u, 0x01u,
	0x4Du, 0x2Bu, 0xE9u, 0x7Cu, 0xFEu, 0x3Bu, 0xCEu, 0x68u, 0xAAu, 0xB5u, 0x53u, 0x67u, 0x26u, 0x59u, 0x3Bu, 0x39u,
	0x8Cu, 0xACu, 0x42u, 0x5Eu, 0x97u, 0x51u, 0x9Du, 0x50u, 0xFCu, 0x77u, 0xDEu, 0x0Cu, 0x0Au, 0x4Bu, 0x68u, 0x63u,
	0xCFu, 0x58u, 0x59u, 0x75u, 0xEEu, 0x17u, 0x31u, 0x78u, 0xBAu, 0x22u, 0xFCu, 0xA1u, 0xE0u, 0xC9u, 0x6Du, 0x47u,
	0x8Bu, 0x14u, 0x7Au, 0xD5u, 0x05u, 0xA4u, 0x9Bu, 0xCEu, 0xCBu, 0x95u, 0x78u, 0x76u, 0xC7u, 0x97u, 0x6Bu, 0x5Fu,
	0x77u, 0x21u, 0x1Au, 0xEDu, 0x6Eu, 0xEFu, 0xCDu, 0xDAu, 0x36u, 0x72u, 0x3Cu, 0xCAu, 0x6Cu, 0xBFu, 0x4Cu, 0xA5u,
	0x93u, 0x82u, 0xFCu, 0x61u, 0x21u, 0x16u, 0xA7u, 0x30u, 0x86u, 0x86u, 0xBBu, 0x57u, 0xF7u, 0x00u, 0x0Bu, 0xB1u,
	0x91u, 0xA6u, 0xBAu, 0x8Fu, 0x6Au, 0xFFu, 0xFDu, 0xD9u, 0x88u, 0x93u, 0x97u, 0x13u, 0x1Fu, 0x28u, 0x2Bu, 0xC6u,
	0x05u, 0xB3u, 0x3Fu, 0x4Du, 0x44u, 0xDBu, 0xABu, 0x8Du, 0xDFu, 0xDDu, 0x71u, 0x6Du, 0x81u, 0x1Cu, 0x04u, 0x00u,
	0x0Cu, 0x58u, 0x60u, 0x7Cu, 0xBEu, 0x51u, 0x9Du, 0x7Cu, 0x7Cu, 0xC7u, 0x3Au, 0x7Cu, 0xDEu, 0x15u, 0x88u, 0x3Du,
	0xC1u, 0x74u, 0x5Au, 0xE5u, 0x3Eu, 0x25u, 0xD7u, 0x30u, 0xC5u, 0xEFu, 0xD1u, 0x96u, 0x14u, 0xB6u, 0x23u, 0x8Cu,
	0xE5u, 0x68u, 0xB9u, 0x81u, 0xB3u, 0x67u, 0x76u, 0x65u, 0xB8u, 0x31u, 0xDFu, 0x84u, 0x5Fu, 0x30u, 0x85u, 0x37u,
	0xB6u, 0xD6u, 0x56u, 0x31u, 0x62u, 0xFAu, 0x73u, 0x20u, 0x4Fu, 0x39u, 0x22u, 0xC5u, 0xCEu, 0xE7u, 0x84u, 0x7Bu,
	0x82u, 0x27u, 0xA9u, 0xC4u, 0x5Cu, 0x06u, 0x44u, 0xA1u, 0x59u, 0x2Au, 0x70u, 0xE5u, 0x25u, 0xB9u, 0x6Fu, 0x40u,
};

/** \brief Main function */
int main(void)
{
	setup_clocks();
	setup_systick();
	setup_uart();
	setup_leds();
	setup_can();

	while (true)
	{
		__asm__("nop");
	}

	return 0;
}

void setup_clocks(void)
{
	/* Enable DSU, NVMCTRL and CAN0 AHB clocks */
	MCLK_AHBMASK.U |=
		MCLK_AHBMASK_DSU_MSK |
		MCLK_AHBMASK_NVMCTRL_MSK |
		MCLK_AHBMASK_CAN0_MSK;
	/* Enable PAC, MCLK, OSCCTRL and GCLK APB clocks */
	MCLK_APBAMASK.U |=
		MCLK_APBAMASK_PAC_MSK |
		MCLK_APBAMASK_MCLK_MSK |
		MCLK_APBAMASK_OSCCTRL_MSK |
		MCLK_APBAMASK_GCLK_MSK;
	/* Enable DSU, PORT and NVMCTRL APB clocks */
	MCLK_APBBMASK.U |=
		MCLK_APBBMASK_DSU_MSK |
		MCLK_APBBMASK_PORT_MSK |
		MCLK_APBBMASK_NVMCTRL_MSK;
	/* Enable SERCOM0 APB clock */
	MCLK_APBCMASK.U |=
		MCLK_APBCMASK_SERCOM0_MSK;

	/* Configure NVM wait states */
	NVMCTRL_CTRLB.U = (0x2u << NVMCTRL_CTRLB_RWS_OFF);

	/* Configure and enable external 32MHz oscillator */
	OSCCTRL_XOSCCTRL.U =
		(0x1u << OSCCTRL_XOSCCTRL_ENABLE_OFF  ) |
		(0x1u << OSCCTRL_XOSCCTRL_XTALEN_OFF  ) |
		(0x1u << OSCCTRL_XOSCCTRL_CFDEN_OFF   ) |
		(0x0u << OSCCTRL_XOSCCTRL_SWBEN_OFF   ) |
		(0x0u << OSCCTRL_XOSCCTRL_RUNSTDBY_OFF) |
		(0x0u << OSCCTRL_XOSCCTRL_ONDEMAND_OFF) |
		(0x2u << OSCCTRL_XOSCCTRL_GAIN_OFF    ) |
		(0x1u << OSCCTRL_XOSCCTRL_AMPGC_OFF   ) |
		(0x6u << OSCCTRL_XOSCCTRL_STARTUP_OFF );

	/* Enable OSCCTRL clock fail interrupt */
	OSCCTRL_INTENSET.U = OSCCTRL_INTENSET_CLKFAIL_MSK;
	/* Enable OSCCTRL interrupts */
	NVIC_ISER = 0x1u << 0;

	/* Wait till external oscillator ready */
	while (!OSCCTRL_STATUS.B.XOSCRDY);

	/* Clock generator 0 at 32MHz using external oscillator */
	GCLK_GENCTRL0.U =
		(0x0u << GCLK_GENCTRL_SRC_OFF     ) |
		(0x1u << GCLK_GENCTRL_GENEN_OFF   ) |
		(0x0u << GCLK_GENCTRL_IDC_OFF     ) |
		(0x0u << GCLK_GENCTRL_OOV_OFF     ) |
		(0x0u << GCLK_GENCTRL_OE_OFF      ) |
		(0x0u << GCLK_GENCTRL_DIVSEL_OFF  ) |
		(0x0u << GCLK_GENCTRL_RUNSTDBY_OFF) |
		(0x0u << GCLK_GENCTRL_DIV_OFF     );

	/* Clock SERCOM01234_SLOW using generator 0 (32MHz XOSC) */
	GCLK_PCHCTRL18.U =
		(0x0u << GCLK_PCHCTRL_GEN_OFF    ) |
		(0x1u << GCLK_PCHCTRL_CHEN_OFF   ) |
		(0x0u << GCLK_PCHCTRL_WRTLOCK_OFF);
	/* Clock SERCOM0_CORE using generator 0 (32MHz XOSC) */
	GCLK_PCHCTRL19.U =
		(0x0u << GCLK_PCHCTRL_GEN_OFF    ) |
		(0x1u << GCLK_PCHCTRL_CHEN_OFF   ) |
		(0x0u << GCLK_PCHCTRL_WRTLOCK_OFF);

	/* Clock CAN0 using generator 0 (32MHz XOSC) */
	GCLK_PCHCTRL26.U =
		(0x0u << GCLK_PCHCTRL_GEN_OFF    ) |
		(0x1u << GCLK_PCHCTRL_CHEN_OFF   ) |
		(0x0u << GCLK_PCHCTRL_WRTLOCK_OFF);
}

void setup_systick(void)
{
	/* Enable SysTick and interrupt */
	SYST_CSR.U =
		(0x1u << SYST_CSR_ENABLE_OFF   ) |
		(0x1u << SYST_CSR_TICKINT_OFF  ) |
		(0x1u << SYST_CSR_CLKSOURCE_OFF) |
		(0x0u << SYST_CSR_COUNTFLAG_OFF);

	/* 1ms tick @ 32MHz clock */
	SYST_RVR.U = (0x7A12u << SYST_RVR_RELOAD_OFF);
}

void setup_leds(void)
{
	/* Configure TX_ACT/RX_ACT pins as output */
	PORT_DIR.U |=
		PORT_DIR_DIR9_MSK |
		PORT_DIR_DIR10_MSK;

	/* Turn TX_ACT LED on (active-low) */
	PORT_OUT.B.OUT9 = 0;
	/* Turn RX_ACT LED off (active-low) */
	PORT_OUT.B.OUT10 = 1;
}

void task_1ms(void)
{
	uint8_t c;
	uint32_t crc;

	if (uart_read_char(&c) == 1)
	{
		switch (c)
		{
		case 'a':
			uart_write_char(' ');
			uart_write_char('p');
			uart_write_char('r');
			uart_write_char('e');
			uart_write_char('s');
			uart_write_char('s');
			uart_write_char('e');
			uart_write_char('d');
			uart_write_char(' ');
			uart_write_char('a');
			uart_write_char(' ');
			break;

		/* Test erasing flash */
		case 'e':
			if (flash_erase_row(0xF00u))
			{
				uart_write_char(' ');
				uart_write_char('o');
				uart_write_char('k');
				uart_write_char(' ');
			}
			else
			{
				uart_write_char(' ');
				uart_write_char('n');
				uart_write_char('o');
				uart_write_char('k');
				uart_write_char(' ');
			}
			break;

		/* Test writing flash */
		case 'w':
			if (flash_write_row(0xF00u, some_data))
			{
				uart_write_char(' ');
				uart_write_char('o');
				uart_write_char('k');
				uart_write_char(' ');
			}
			else
			{
				uart_write_char(' ');
				uart_write_char('n');
				uart_write_char('o');
				uart_write_char('k');
				uart_write_char(' ');
			}
			break;

		/* Test hardware accelerated CRC */
		case 'c':
			/* Unlock DSU write control */
			PAC_WRCTRL.U =
				(0x21 << PAC_WRCTRL_PERID_OFF) |
				(0x1u << PAC_WRCTRL_KEY_OFF  );

			/* Start CRC calculation */
			DSU_ADDR.U =
				(uint32_t) some_data |
				(0x0u << DSU_ADDR_AMOD_OFF);
			DSU_LENGTH.U = 256u;
			DSU_DATA = 0xFFFFFFFFu; /* Initial value */
			DSU_CTRL.U = DSU_CTRL_CRC_MSK;

			/* Wait till CRC finished */
			while (!DSU_STATUSA.B.DONE);
			DSU_STATUSA.U = DSU_STATUSA_DONE_MSK;

			crc = DSU_DATA ^ 0xFFFFFFFFu; /* Final XOR value */
			if (crc == 0x8E663A3Du)
			{
				uart_write_char(' ');
				uart_write_char('o');
				uart_write_char('k');
				uart_write_char(' ');
			}
			else
			{
				uart_write_char(' ');
				uart_write_char('n');
				uart_write_char('o');
				uart_write_char('k');
				uart_write_char(' ');
			}
			break;
		}
	}
}

void task_10ms(void)
{
	/* UART transmit */
	uart_write_char('y');
	uart_write_char('o');
}

void task_100ms(void)
{
	static uint8_t cycle = 0;

	/* Toggle TX_ACT/RX_ACT LEDs */
	PORT_OUT.U ^= PORT_DIR_DIR9_MSK;
	PORT_OUT.U ^= PORT_DIR_DIR10_MSK;

	/* Fill CAN TX buffer 0 */
	can_tx_buffer[0].U[0] =
		(0x123u << CAN_TX_BUFFER_STD_ID_OFF);
	can_tx_buffer[0].U[1] =
		(0x3u << CAN_TX_BUFFER_DLC_OFF);
	can_tx_buffer[0].B.DB[0] = cycle;
	can_tx_buffer[0].B.DB[1] = cycle;
	can_tx_buffer[0].B.DB[2] = cycle++;

	/* Transmit message */
	CAN0_TXBAR = 0x1u << 0;
}

void task_1000ms(void)
{
	/* UART transmit */
	uart_write_char(' ');
	uart_write_char('h');
	uart_write_char('e');
	uart_write_char('l');
	uart_write_char('l');
	uart_write_char('o');
	uart_write_char(' ');
}

/**
 * \brief Handles the reset exception.
 *
 * Reset is invoked on power up or a warm reset. The exception model treats
 * reset as a special form of exception. When reset is asserted, the
 * operation of the processor stops, potentially at any point in an
 * instruction. When reset is deasserted, execution restarts from the
 * address provided by the reset entry in the vector table. Execution
 * restarts as privileged execution in Thread mode.
 */
void reset_handler(void)
{
	uint32_t* src;
	uint32_t* dst;
	uint32_t  cnt;
	uint32_t  idx;

	SCB_VTOR = (uint32_t) &_stext;

	/* Relocate data section */
	src = &_sdata;
	dst = &_sdata_reloc;
	while (dst < &_edata_reloc)
	{
		*dst++ = *src++;
	}

	/* Clear bss section */
	dst = &_sbss;
	while (dst < &_ebss)
	{
		*dst++ = 0;
	}

	/* Call constructors */
	cnt = _einit_array - _sinit_array;
	for (idx = 0; idx < cnt; idx++)
	{
		((void(*)(void)) _sinit_array[idx])();
	}

	/* Call main entry point */
	main();

	/* Call destructors */
	cnt = _efini_array - _sfini_array;
	for (idx = 0; idx < cnt; idx++)
	{
		((void(*)(void)) _sfini_array[idx])();
	}

	/* Infinite loop */
	while (true)
	{
		__asm__("nop");
	}
}

/**
 * \brief NMI handler
 *
 * A Non-Maskable Interrupt (NMI) can be signalled by a peripheral or
 * triggered by software. This is the highest priority exception other than
 * reset. It is permanently enabled and has a fixed priority of –2. NMIs
 * cannot be:
 * - Masked or prevented from activation by any other exception.
 * - Preempted by any exception other than Reset.
 */
void __attribute__((interrupt)) nmi_handler(void) {}

/**
 * \brief HardFault handler
 *
 * A HardFault is an exception that occurs because of an error. HardFaults
 * have a fixed priority of –1, meaning they have higher priority than any
 * exception with configurable priority.
 */
void __attribute__((interrupt)) hard_fault_handler(void)
{
	/* Infinite loop so that we can see we hard faulted */
	while (true)
	{
		__asm__("nop");
	}
}

/**
 * \brief SV call handler
 *
 * A Supervisor Call (SVC) is an exception that is triggered by the SVC
 * instruction. In an OS environment, applications can use SVC instructions
 * to access OS kernel functions and device drivers.
 */
void __attribute__((interrupt)) sv_call_handler(void) {}

/**
 * \brief PendSV handler
 *
 * PendSV is an interrupt-driven request for system-level service. In an OS
 * environment, use PendSV for context switching when no other exception is
 * active.
 */
void __attribute__((interrupt)) pend_sv_handler(void) {}

/**
 * \brief SysTick handler
 *
 * If the device implements the SysTick timer, a SysTick exception is
 * generated when the SysTick timer reaches zero. Software can also
 * generate a SysTick exception. In an OS environment, the processor can
 * use this exception as system tick.
 */
void __attribute__((interrupt)) sys_tick_handler(void)
{
	static uint32_t cycle_1ms = 0;
	static uint32_t cycle_10ms = 1;
	static uint32_t cycle_100ms = 2;
	static uint32_t cycle_1000ms = 3;

	if (++cycle_1ms == 1)
	{
		task_1ms();
		cycle_1ms = 0;
	}

	if (++cycle_10ms == 10)
	{
		task_10ms();
		cycle_10ms = 0;
	}

	if (++cycle_100ms == 100)
	{
		task_100ms();
		cycle_100ms = 0;
	}

	if (++cycle_1000ms == 1000)
	{
		task_1000ms();
		cycle_1000ms = 0;
	}
}

/** \brief System IRQ handler */
void __attribute__((interrupt)) system_handler(void)
{
	if (OSCCTRL_INTFLAG.B.CLKFAIL)
	{
		/* XOSC failed, clock switched to OSC48M,
		 * configure prescalers for the new core clock */

		/* Disable SERCOM0 */
		SERCOM0_CTRLA.B.ENABLE = 0x0u;
		while (SERCOM0_SYNCBUSY.U & SERCOM_SYNCBUSY_ENABLE_MSK);
		/* Baudrate 115200 @ 48MHz core clock */
		SERCOM0_BAUD = 63019;
		/* Enable SERCOM0 */
		SERCOM0_CTRLA.B.ENABLE = 0x1u;
		while (SERCOM0_SYNCBUSY.U & SERCOM_SYNCBUSY_ENABLE_MSK);

		/* 1ms tick @ 48MHz clock */
		SYST_RVR.U = (0xBA04u << SYST_RVR_RELOAD_OFF);

		/* Set CAN0 initialization */
		CAN0_CCCR.U |= CAN_CCCR_INIT_MSK;
		while (!CAN0_CCCR.B.INIT);
		/* Set CAN0 configuration change enable */
		CAN0_CCCR.U |= CAN_CCCR_CCE_MSK;
		while (!CAN0_CCCR.B.CCE);
		/* Configure nominal timing for 500kbit/s @ 48MHz core clock */
		CAN0_NBTP.U =
			(0x17u << CAN_NBTP_NTSEG2_OFF) |
			(0x46u << CAN_NBTP_NTSEG1_OFF) |
			(0x00u << CAN_NBTP_NBRP_OFF  ) |
			(0x17u << CAN_NBTP_NSJW_OFF  );
		/* Clear CAN0 configuration change enable */
		CAN0_CCCR.U &= ~CAN_CCCR_CCE_MSK;
		while (CAN0_CCCR.B.CCE);
		/* Clear CAN0 initialization */
		CAN0_CCCR.U &= ~CAN_CCCR_INIT_MSK;
		while (CAN0_CCCR.B.INIT);

		/* Acknowledge interrupt */
		*((uint32_t*) (0x40001000u + 0x08u)) = 2;
	}
}

/** \brief WDT IRQ handler */
void __attribute__((interrupt)) wdt_handler(void) {}

/** \brief RTC IRQ handler */
void __attribute__((interrupt)) rtc_handler(void) {}

/** \brief EIC IRQ handler */
void __attribute__((interrupt)) eic_handler(void) {}

/** \brief FREQM IRQ handler */
void __attribute__((interrupt)) freqm_handler(void) {}

/** \brief TSENS IRQ handler */
void __attribute__((interrupt)) tsens_handler(void) {}

/** \brief NVMCTRL IRQ handler */
void __attribute__((interrupt)) nvmctrl_handler(void) {}

/** \brief DMAC IRQ handler */
void __attribute__((interrupt)) dmac_handler(void) {}

/** \brief EVSYS IRQ handler */
void __attribute__((interrupt)) evsys_handler(void) {}

/** \brief SERCOM1 IRQ handler */
void __attribute__((interrupt)) sercom1_handler(void) {}

/** \brief SERCOM2 IRQ handler */
void __attribute__((interrupt)) sercom2_handler(void) {}

/** \brief SERCOM3 IRQ handler */
void __attribute__((interrupt)) sercom3_handler(void) {}

/** \brief CAN0 IRQ handler */
void __attribute__((interrupt)) can0_handler(void) {}

/** \brief TCC0 IRQ handler */
void __attribute__((interrupt)) tcc0_handler(void) {}

/** \brief TCC1 IRQ handler */
void __attribute__((interrupt)) tcc1_handler(void) {}

/** \brief TCC2 IRQ handler */
void __attribute__((interrupt)) tcc2_handler(void) {}

/** \brief TC0 IRQ handler */
void __attribute__((interrupt)) tc0_handler(void) {}

/** \brief TC1 IRQ handler */
void __attribute__((interrupt)) tc1_handler(void) {}

/** \brief TC2 IRQ handler */
void __attribute__((interrupt)) tc2_handler(void) {}

/** \brief TC3 IRQ handler */
void __attribute__((interrupt)) tc3_handler(void) {}

/** \brief TC4 IRQ handler */
void __attribute__((interrupt)) tc4_handler(void) {}

/** \brief ADC0 IRQ handler */
void __attribute__((interrupt)) adc0_handler(void) {}

/** \brief ADC1 IRQ handler */
void __attribute__((interrupt)) adc1_handler(void) {}

/** \brief AC IRQ handler */
void __attribute__((interrupt)) ac_handler(void) {}

/** \brief DAC IRQ handler */
void __attribute__((interrupt)) dac_handler(void) {}

/** \brief SDADC IRQ handler */
void __attribute__((interrupt)) sdadc_handler(void) {}

/** \brief PTC IRQ handler */
void __attribute__((interrupt)) ptc_handler(void) {}

/** \brief Processor interrupt vector table */
__attribute__((section(".vectors")))
const struct vector_table vectors =
{
	.p_stack    = &_estack,
	.reset      = reset_handler,
	.nmi        = nmi_handler,
	.hard_fault = hard_fault_handler,
	.sv_call    = sv_call_handler,
	.pend_sv    = pend_sv_handler,
	.sys_tick   = sys_tick_handler,
	.irq =
	{
		/* IRQ  0 */ system_handler,
		/* IRQ  1 */ wdt_handler,
		/* IRQ  2 */ rtc_handler,
		/* IRQ  3 */ eic_handler,
		/* IRQ  4 */ freqm_handler,
		/* IRQ  5 */ tsens_handler,
		/* IRQ  6 */ nvmctrl_handler,
		/* IRQ  7 */ dmac_handler,
		/* IRQ  8 */ evsys_handler,
		/* IRQ  9 */ sercom0_handler,
		/* IRQ 10 */ sercom1_handler,
		/* IRQ 11 */ sercom2_handler,
		/* IRQ 12 */ sercom3_handler,
		/* IRQ 13 */ 0, /** Reserved */
		/* IRQ 14 */ 0, /** Reserved */
		/* IRQ 15 */ can0_handler,
		/* IRQ 16 */ 0, /** Reserved */
		/* IRQ 17 */ tcc0_handler,
		/* IRQ 18 */ tcc1_handler,
		/* IRQ 19 */ tcc2_handler,
		/* IRQ 20 */ tc0_handler,
		/* IRQ 21 */ tc1_handler,
		/* IRQ 22 */ tc2_handler,
		/* IRQ 23 */ tc3_handler,
		/* IRQ 24 */ tc4_handler,
		/* IRQ 25 */ adc0_handler,
		/* IRQ 26 */ adc1_handler,
		/* IRQ 27 */ ac_handler,
		/* IRQ 28 */ dac_handler,
		/* IRQ 29 */ sdadc_handler,
		/* IRQ 30 */ ptc_handler,
	},
};
