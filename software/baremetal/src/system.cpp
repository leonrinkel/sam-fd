/**
 * \file src/system.cpp
 * \author Rinkel, Leon <leon@rinkel.me>
 *
 * Implementation of low-level processor stuff such as the vector table.
 */

#include "system.hpp"

#include "samfd.hpp"
#include "types.hpp"
#include "linked.hpp"

/**
 * Main function.
 *
 * We could just call our wrapper class in the reset handler but some debuggers
 * seem to require a main function to work properly.
 */
int main(void)
{
	samfd().run();
}

/**
 * Handles the reset exception.
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

	/* Relocate data section. */
	src = &_sdata;
	dst = &_sdata_reloc;
	while (dst < &_edata_reloc)
	{
		*dst++ = *src++;
	}

	/* Clear bss section. */
	dst = &_sbss;
	while (dst < &_ebss)
	{
		*dst++ = 0;
	}

	/* Call constructors. */
	cnt = _einit_array - _sinit_array;
	for (idx = 0; idx < cnt; idx++)
	{
		((void(*)(void)) _sinit_array[idx])();
	}

	/* Call main entry point. */
	main();

	/* Call destructors. */
	cnt = _efini_array - _sfini_array;
	for (idx = 0; idx < cnt; idx++)
	{
		((void(*)(void)) _sfini_array[idx])();
	}

	/* Infinite loop. */
	while (true)
	{
		__asm__("nop");
	}
}

/** NMI handler.
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
 * HardFault handler.
 *
 * A HardFault is an exception that occurs because of an error. HardFaults
 * have a fixed priority of –1, meaning they have higher priority than any
 * exception with configurable priority.
 */
void __attribute__((interrupt)) hard_fault_handler(void)
{
	/* Infinite loop so that we can see we hard faulted. */
	while (true)
	{
		__asm__("nop");
	}
}

/**
 * SV call handler.
 *
 * A Supervisor Call (SVC) is an exception that is triggered by the SVC
 * instruction. In an OS environment, applications can use SVC instructions
 * to access OS kernel functions and device drivers.
 */
void __attribute__((interrupt)) sv_call_handler(void) {}

/**
 * PendSV handler.
 *
 * PendSV is an interrupt-driven request for system-level service. In an OS
 * environment, use PendSV for context switching when no other exception is
 * active.
 */
void __attribute__((interrupt)) pend_sv_handler(void) {}

/**
 * SysTick handler.
 *
 * If the device implements the SysTick timer, a SysTick exception is
 * generated when the SysTick timer reaches zero. Software can also
 * generate a SysTick exception. In an OS environment, the processor can
 * use this exception as system tick.
 */
void __attribute__((interrupt)) sys_tick_handler(void) {}

/** System IRQ handler */
void __attribute__((interrupt)) system_handler(void) {}

/** WDT IRQ handler */
void __attribute__((interrupt)) wdt_handler(void) {}

/** RTC IRQ handler */
void __attribute__((interrupt)) rtc_handler(void) {}

/** EIC IRQ handler */
void __attribute__((interrupt)) eic_handler(void) {}

/** FREQM IRQ handler */
void __attribute__((interrupt)) freqm_handler(void) {}

/** TSENS IRQ handler */
void __attribute__((interrupt)) tsens_handler(void) {}

/** NVMCTRL IRQ handler */
void __attribute__((interrupt)) nvmctrl_handler(void) {}

/** DMAC IRQ handler */
void __attribute__((interrupt)) dmac_handler(void) {}

/** EVSYS IRQ handler */
void __attribute__((interrupt)) evsys_handler(void) {}

/** SERCOM0 IRQ handler */
void __attribute__((interrupt)) sercom0_handler(void) {}

/** SERCOM1 IRQ handler */
void __attribute__((interrupt)) sercom1_handler(void) {}

/** SERCOM2 IRQ handler */
void __attribute__((interrupt)) sercom2_handler(void) {}

/** SERCOM3 IRQ handler */
void __attribute__((interrupt)) sercom3_handler(void) {}

/** CAN0 IRQ handler */
void __attribute__((interrupt)) can0_handler(void) {}

/** TCC0 IRQ handler */
void __attribute__((interrupt)) tcc0_handler(void) {}

/** TCC1 IRQ handler */
void __attribute__((interrupt)) tcc1_handler(void) {}

/** TCC2 IRQ handler */
void __attribute__((interrupt)) tcc2_handler(void) {}

/** TC0 IRQ handler */
void __attribute__((interrupt)) tc0_handler(void) {}

/** TC1 IRQ handler */
void __attribute__((interrupt)) tc1_handler(void) {}

/** TC2 IRQ handler */
void __attribute__((interrupt)) tc2_handler(void) {}

/** TC3 IRQ handler */
void __attribute__((interrupt)) tc3_handler(void) {}

/** TC4 IRQ handler */
void __attribute__((interrupt)) tc4_handler(void) {}

/** ADC0 IRQ handler */
void __attribute__((interrupt)) adc0_handler(void) {}

/** ADC1 IRQ handler */
void __attribute__((interrupt)) adc1_handler(void) {}

/** AC IRQ handler */
void __attribute__((interrupt)) ac_handler(void) {}

/** DAC IRQ handler */
void __attribute__((interrupt)) dac_handler(void) {}

/** SDADC IRQ handler */
void __attribute__((interrupt)) sdadc_handler(void) {}

/** PTC IRQ handler */
void __attribute__((interrupt)) ptc_handler(void) {}

/** Processor interrupt vector table. */
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

const volatile struct cpuid::_cpuid* cpuid::cpuid_ro(void)
{
	return ((const volatile struct cpuid::_cpuid*) _cpuid_register_address);
}

uint8_t cpuid::get_revision(void)
{
	return cpuid_ro()->revision;
}

enum cpuid::partno cpuid::get_partno(void)
{
	return static_cast<enum cpuid::partno>(cpuid_ro()->partno);
}

enum cpuid::architecture cpuid::get_architecture(void)
{
	return static_cast<enum cpuid::architecture>(cpuid_ro()->architecture);
}

uint8_t cpuid::get_variant(void)
{
	return cpuid_ro()->variant;
}

enum cpuid::implementer cpuid::get_implementer(void)
{
	return static_cast<enum cpuid::implementer>(cpuid_ro()->implementer);
}
