/**
 * \file   inc/linked.hpp
 * \author Rinkel, Leon <leon@rinkel.me>
 *
 * Declaration of addresses provided by the linker.
 */

#pragma once

#include "types.hpp"

extern uint32_t _stext;              /**< Start of text section. */
extern uint32_t _etext;              /**< End of text section. */
extern void (*_sinit_array[])(void); /**< Start of init array. */
extern void (*_einit_array[])(void); /**< End of init array. */
extern void (*_sfini_array[])(void); /**< Start of fini array. */
extern void (*_efini_array[])(void); /**< End of fini array. */
extern uint32_t _srodata;            /**< Start of rodata section. */
extern uint32_t _erodata;            /**< End of rodata section. */
extern uint32_t _sdata;              /**< Start of data section. */
extern uint32_t _sdata_reloc;        /**< Start of data section in ram. */
extern uint32_t _edata_reloc;        /**< End of data section in ram. */
extern uint32_t _sbss;               /**< Start of bss section. */
extern uint32_t _ebss;               /**< End of bss section. */
extern uint32_t _stack;              /**< Start of stack section. */
extern uint32_t _estack;             /**< End of stack section. */
