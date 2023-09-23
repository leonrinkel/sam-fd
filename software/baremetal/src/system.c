/* SPDX-License-Identifier: MIT */
/**
 * \file      src/system.c
 * \brief     Implementation of low-level processor stuff such as the vector table
 * \copyright Copyright (c) 2023 Leon Rinkel
 */

#include <stdint.h>
#include <stdbool.h>

#include <gclk.h>
#include <linked.h>
#include <mclk.h>
#include <nvic.h>
#include <nvmctrl.h>
#include <oscctrl.h>
#include <port.h>
#include <sercom.h>
#include <syst.h>
#include <system.h>
#include <uart.h>

void setup_clocks(void);
void setup_systick(void);
void setup_leds(void);

void task_1ms(void);
void task_10ms(void);
void task_100ms(void);
void task_1000ms(void);

/** \brief Main function */
int main(void)
{
	setup_clocks();
	setup_systick();
	setup_uart();
	setup_leds();

	while (true)
	{
		__asm__("nop");
	}

	return 0;
}

void setup_clocks(void)
{
	/* Enable MCLK, OSCCTRL and GCLK APB clocks */
	MCLK_APBAMASK.U |=
		MCLK_APBAMASK_MCLK_MSK |
		MCLK_APBAMASK_OSCCTRL_MSK |
		MCLK_APBAMASK_GCLK_MSK;
	/* Enable PORT and NVMCTRL APB clocks */
	MCLK_APBBMASK.U |=
		MCLK_APBBMASK_PORT_MSK |
		MCLK_APBBMASK_NVMCTRL_MSK;
	/* Enable SERCOM0 APB clocks */
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

}

void task_10ms(void)
{
	/* UART transmit */
	uart_write_char('y');
	uart_write_char('o');
}

void task_100ms(void)
{
	/* Toggle TX_ACT/RX_ACT LEDs */
	PORT_OUT.U ^= PORT_DIR_DIR9_MSK;
	PORT_OUT.U ^= PORT_DIR_DIR10_MSK;
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
