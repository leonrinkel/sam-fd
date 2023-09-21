/**
 * \file   src/system.c
 * \author Rinkel, Leon <leon@rinkel.me>
 *
 * Implementation of low-level processor stuff such as the vector table.
 */

#include <stdint.h>
#include <stdbool.h>

#include "gclk.h"
#include "linked.h"
#include "mclk.h"
#include "port.h"
#include "sercom.h"
#include "system.h"

/** \brief Main function */
int main(void)
{
	/* Enable PORT peripheral */
	MCLK_APBBMASK.U |= MCLK_APBBMASK_PORT_MSK;
	/* Enable SERCOM0 peripheral */
	MCLK_APBCMASK.U |= MCLK_APBCMASK_SERCOM0_MSK;

	/* Clock SERCOM01234_SLOW using OSC48M */
	GCLK_PCHCTRL18.U =
		(0x0u << GCLK_PCHCTRL_GEN_OFF    ) |
		(0x1u << GCLK_PCHCTRL_CHEN_OFF   ) |
		(0x0u << GCLK_PCHCTRL_WRTLOCK_OFF);
	/* Clock SERCOM0_CORE using OSC48M */
	GCLK_PCHCTRL19.U =
		(0x0u << GCLK_PCHCTRL_GEN_OFF    ) |
		(0x1u << GCLK_PCHCTRL_CHEN_OFF   ) |
		(0x0u << GCLK_PCHCTRL_WRTLOCK_OFF);

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

	/* Baudrate 115200 @ 4MHz core clock */
	SERCOM0_BAUD = 35337;

	/* Enable SERCOM0 */
	SERCOM0_CTRLA.B.ENABLE = 0x1u;
	while (SERCOM0_SYNCBUSY.U & SERCOM_SYNCBUSY_ENABLE_MSK);

	/* Configure TX_ACT/RX_ACT pins as output */
	PORT_DIR.U |=
		PORT_DIR_DIR9_MSK |
		PORT_DIR_DIR10_MSK;

	/* Turn TX_ACT LED on (active-low) */
	PORT_OUT.B.OUT9 = 0;
	/* Turn RX_ACT LED off (active-low) */
	PORT_OUT.B.OUT10 = 1;

	for (;;)
	{
		/* Toggle TX_ACT/RX_ACT LEDs */
		PORT_OUT.U ^= PORT_DIR_DIR9_MSK;
		PORT_OUT.U ^= PORT_DIR_DIR10_MSK;

		/* Delay */
		for (uint32_t i = 0x0000FFFFu; i > 0; i--);

		/* UART transmit */
		*((uint32_t*) 0x42000428) = 'h';
		for (uint32_t i = 0x0000FFFFu; i > 0; i--);
		*((uint32_t*) 0x42000428) = 'e';
		for (uint32_t i = 0x0000FFFFu; i > 0; i--);
		*((uint32_t*) 0x42000428) = 'l';
		for (uint32_t i = 0x0000FFFFu; i > 0; i--);
		*((uint32_t*) 0x42000428) = 'l';
		for (uint32_t i = 0x0000FFFFu; i > 0; i--);
		*((uint32_t*) 0x42000428) = 'o';
		for (uint32_t i = 0x0000FFFFu; i > 0; i--);
		*((uint32_t*) 0x42000428) = '\r';
		for (uint32_t i = 0x0000FFFFu; i > 0; i--);
		*((uint32_t*) 0x42000428) = '\n';
		for (uint32_t i = 0x0000FFFFu; i > 0; i--);
	}

	return 0;
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
void __attribute__((interrupt)) sys_tick_handler(void) {}

/** \brief System IRQ handler */
void __attribute__((interrupt)) system_handler(void) {}

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

/** \brief SERCOM0 IRQ handler */
void __attribute__((interrupt)) sercom0_handler(void) {}

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
