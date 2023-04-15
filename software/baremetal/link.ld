OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)

MEMORY
{
	FLASH (rx ) : ORIGIN = 0x00001000, LENGTH = 0x00009000
	RAM   (rwx) : ORIGIN = 0x20000000, LENGTH = 0x00002000
}

STACK_SIZE = 0x800;

SECTIONS
{
	.text :
	{
		. = ALIGN(4);
		_stext = .;
		KEEP(*(.vectors .vectors.*))
		*(.text .text.*)

		. = ALIGN(4);
		_sinit_array = .;
		KEEP(*(SORT(.init_array.*)))
		KEEP(*(.init_array))
		_einit_array = .;

		. = ALIGN(4);
		_sfini_array = .;
		KEEP(*(.fini_array))
		KEEP(*(SORT(.fini_array.*)))
		_efini_array = .;

		. = ALIGN(4);
		_etext = .;
	} > FLASH

	.rodata :
	{
		. = ALIGN(4);
		_srodata = .;
		*(.rodata .rodata.*)
		. = ALIGN(4);
		_erodata = .;
	} > FLASH

	.data :
	{
		. = ALIGN(4);
		_sdata = LOADADDR(.data);
		_sdata_reloc = .;
		*(.data .data.*)
		. = ALIGN(4);
		_edata_reloc = .;
	} > RAM AT >FLASH

	.bss :
	{
		. = ALIGN(4);
		_sbss = .;
		*(.bss .bss.*)
		. = ALIGN(4);
		_ebss = .;
	} > RAM

	.stack :
	{
		. = ALIGN(4);
		_sstack = .;
		. = . + STACK_SIZE;
		. = ALIGN(4);
		_estack = .;
	} > RAM
}
