/**
 * \file   inc/system.hpp
 * \author Rinkel, Leon <leon@rinkel.me>
 *
 * Declaration of low-level processor stuff such as the vector table.
 */

#pragma once

#include "types.hpp"

/** Structure of the processor interrupt vector table. */
struct vector_table
{
	void* p_stack; /**< Initial stack pointer value. */

	/**
	 * Reset is invoked on power up or a warm reset. The exception model treats
	 * reset as a special form of exception. When reset is asserted, the
	 * operation of the processor stops, potentially at any point in an
	 * instruction. When reset is deasserted, execution restarts from the
	 * address provided by the reset entry in the vector table. Execution
	 * restarts as privileged execution in Thread mode.
	 */
	exception_handler_t reset;

	/**
	 * A Non-Maskable Interrupt (NMI) can be signalled by a peripheral or
	 * triggered by software. This is the highest priority exception other than
	 * reset. It is permanently enabled and has a fixed priority of –2. NMIs
	 * cannot be:
	 * - Masked or prevented from activation by any other exception.
	 * - Preempted by any exception other than Reset.
	 */
	exception_handler_t nmi;

	/**
	 * A HardFault is an exception that occurs because of an error. HardFaults
	 * have a fixed priority of –1, meaning they have higher priority than any
	 * exception with configurable priority.
	 */
	exception_handler_t hard_fault;

	uint32_t:32; /**< Reserved */
	uint32_t:32; /**< Reserved */
	uint32_t:32; /**< Reserved */
	uint32_t:32; /**< Reserved */
	uint32_t:32; /**< Reserved */
	uint32_t:32; /**< Reserved */
	uint32_t:32; /**< Reserved */

	/**
	 * A Supervisor Call (SVC) is an exception that is triggered by the SVC
	 * instruction. In an OS environment, applications can use SVC instructions
	 * to access OS kernel functions and device drivers.
	 */
	exception_handler_t sv_call;

	uint32_t:32; /**< Reserved */
	uint32_t:32; /**< Reserved */

	/**
	 * PendSV is an interrupt-driven request for system-level service. In an OS
	 * environment, use PendSV for context switching when no other exception is
	 * active.
	 */
	exception_handler_t pend_sv;

	/**
	 * If the device implements the SysTick timer, a SysTick exception is
	 * generated when the SysTick timer reaches zero. Software can also
	 * generate a SysTick exception. In an OS environment, the processor can
	 * use this exception as system tick.
	 */
	exception_handler_t sys_tick;

	/**
	 * An interrupt, or IRQ, is an exception signalled by a peripheral, or
	 * generated by a software request. All interrupts are asynchronous to
	 * instruction execution. In the system, peripherals use interrupts to
	 * communicate with the processor.
	 */
	exception_handler_t irq[32];
};
