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

void __attribute__((interrupt)) nmi_handler(void) {}

void __attribute__((interrupt)) hard_fault_handler(void)
{
	/* Infinite loop so that we can see we hard faulted. */
	while (true)
	{
		__asm__("nop");
	}
}

void __attribute__((interrupt)) sv_call_handler(void) {}
void __attribute__((interrupt)) pend_sv_handler(void) {}
void __attribute__((interrupt)) sys_tick_handler(void) {}
void __attribute__((interrupt)) system_handler(void) {}
void __attribute__((interrupt)) wdt_handler(void) {}
void __attribute__((interrupt)) rtc_handler(void) {}
void __attribute__((interrupt)) eic_handler(void) {}
void __attribute__((interrupt)) freqm_handler(void) {}
void __attribute__((interrupt)) tsens_handler(void) {}
void __attribute__((interrupt)) nvmctrl_handler(void) {}
void __attribute__((interrupt)) dmac_handler(void) {}
void __attribute__((interrupt)) evsys_handler(void) {}
void __attribute__((interrupt)) sercom0_handler(void) {}
void __attribute__((interrupt)) sercom1_handler(void) {}
void __attribute__((interrupt)) sercom2_handler(void) {}
void __attribute__((interrupt)) sercom3_handler(void) {}
void __attribute__((interrupt)) can0_handler(void) {}
void __attribute__((interrupt)) tcc0_handler(void) {}
void __attribute__((interrupt)) tcc1_handler(void) {}
void __attribute__((interrupt)) tcc2_handler(void) {}
void __attribute__((interrupt)) tc0_handler(void) {}
void __attribute__((interrupt)) tc1_handler(void) {}
void __attribute__((interrupt)) tc2_handler(void) {}
void __attribute__((interrupt)) tc3_handler(void) {}
void __attribute__((interrupt)) tc4_handler(void) {}
void __attribute__((interrupt)) adc0_handler(void) {}
void __attribute__((interrupt)) adc1_handler(void) {}
void __attribute__((interrupt)) ac_handler(void) {}
void __attribute__((interrupt)) dac_handler(void) {}
void __attribute__((interrupt)) sdadc_handler(void) {}
void __attribute__((interrupt)) ptc_handler(void) {}

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
