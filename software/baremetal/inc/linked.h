/**
 * \file   inc/linked.h
 * \author Rinkel, Leon <leon@rinkel.me>
 *
 * Declaration of addresses provided by the linker.
 */

#ifndef SAMFD_LINKED_H
#define SAMFD_LINKED_H

#include <stdint.h>

/** \brief Start of text section */
extern uint32_t _stext;
/** \brief End of text section */
extern uint32_t _etext;

/** \brief Start of init array */
extern void (*_sinit_array[])(void);
/** \brief End of init array */
extern void (*_einit_array[])(void);

/** \brief Start of fini array */
extern void (*_sfini_array[])(void);
/** \brief End of fini array */
extern void (*_efini_array[])(void);

/** \brief Start of rodata section */
extern uint32_t _srodata;
/** \brief End of rodata section */
extern uint32_t _erodata;

/** \brief Start of data section */
extern uint32_t _sdata;
/** \brief Start of data section in ram */
extern uint32_t _sdata_reloc;
/** \brief End of data section in ram */
extern uint32_t _edata_reloc;

/** \brief Start of bss section */
extern uint32_t _sbss;
/** \brief End of bss section */
extern uint32_t _ebss;

/** \brief Start of stack section */
extern uint32_t _stack;
/** \brief End of stack section */
extern uint32_t _estack;

#endif /* SAMFD_LINKED_H */
