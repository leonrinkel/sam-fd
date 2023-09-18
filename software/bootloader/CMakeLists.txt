cmake_minimum_required(VERSION 3.25.2)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/toolchain.cmake)
set(CMAKE_C_COMPILER_WORKS 1)

project(bootloader
	LANGUAGES C
	VERSION 0.1
)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_compile_options(
	-mthumb
	-Os
	-ffunction-sections
	-mlong-calls
	-Wall
	-Wextra
	-std=gnu99
	-D__SAMC21E16A__
	-mcpu=cortex-m0plus
	-Wno-array-bounds
)

add_link_options(
	-Wl,--start-group
	-lm
	-Wl,--end-group
	-mthumb
	--specs=nano.specs
	-Wl,--gc-sections
	-mcpu=cortex-m0plus
	-T${CMAKE_SOURCE_DIR}/samc21/gcc/gcc/samc21e16a_flash.ld
	-L${CMAKE_SOURCE_DIR}/samc21/gcc/gcc
)

add_executable(bootloader
	hal/src/hal_io.c
	samc21/gcc/system_samc21.c
	hpl/systick/hpl_systick.c
	hal/utils/src/utils_syscalls.c
	samc21/gcc/gcc/startup_samc21.c
	hpl/nvmctrl/hpl_nvmctrl.c
	hal/src/hal_delay.c
	hpl/oscctrl/hpl_oscctrl.c
	hpl/core/hpl_init.c
	hal/utils/src/utils_list.c
	hpl/core/hpl_core_m0plus_base.c
	hal/utils/src/utils_assert.c
	hpl/pac/hpl_pac.c
	hpl/pm/hpl_pm.c
	hal/src/hal_usart_sync.c
	hpl/mclk/hpl_mclk.c
	hpl/gclk/hpl_gclk.c
	hal/src/hal_flash.c
	hal/src/hal_init.c
	hal/src/hal_crc_sync.c
	main.c
	hpl/osc32kctrl/hpl_osc32kctrl.c
	examples/driver_examples.c
	driver_init.c
	hpl/sercom/hpl_sercom.c
	hal/src/hal_gpio.c
	hpl/divas/hpl_divas.c
	hal/utils/src/utils_event.c
	hal/src/hal_sleep.c
	hpl/dmac/hpl_dmac.c
	atmel_start.c
	hal/src/hal_atomic.c
	hpl/dsu/hpl_dsu.c
)

target_include_directories(bootloader PRIVATE
	.
	config
	examples
	hal/include
	hal/utils/include
	hpl/core
	hpl/divas
	hpl/dmac
	hpl/dsu
	hpl/gclk
	hpl/mclk
	hpl/nvmctrl
	hpl/osc32kctrl
	hpl/oscctrl
	hpl/pac
	hpl/pm
	hpl/port
	hpl/sercom
	hpl/systick
	hri
	CMSIS/Core/Include
	samc21/include
)

set_target_properties(bootloader PROPERTIES SUFFIX .elf)

set(BIN_FILE ${CMAKE_CURRENT_BINARY_DIR}/bootloader.bin)
add_custom_command(
	TARGET bootloader POST_BUILD
	COMMAND
		arm-none-eabi-objcopy -O binary $<TARGET_FILE:bootloader> ${BIN_FILE}
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	COMMENT "Objcopying elf to bin ${BIN_FILE}"
)

set(HEX_FILE ${CMAKE_CURRENT_BINARY_DIR}/bootloader.hex)
add_custom_command(
	TARGET bootloader POST_BUILD
	COMMAND
		arm-none-eabi-objcopy -O ihex $<TARGET_FILE:bootloader> ${HEX_FILE}
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	COMMENT "Objcopying elf to hex ${HEX_FILE}"
)
