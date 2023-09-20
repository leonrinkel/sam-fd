cmake_minimum_required(VERSION 3.25.2)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/toolchain.cmake)
set(CMAKE_C_COMPILER_WORKS 1)

project(application
	LANGUAGES C
	VERSION 0.1
)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_compile_options(
	-mcpu=cortex-m0plus
	-mthumb
	-mlong-calls
	-Os
	-ffunction-sections
	-g3
	-std=gnu99
	-Wall
	-D__SAMC21E16A__
	-DDEBUG
	-Wno-array-bounds
)

add_link_options(
	-mcpu=cortex-m0plus
	-mthumb
	--specs=nano.specs
	-Wl,--start-group
	-Wl,--end-group
	-Wl,--gc-sections
	-T${CMAKE_SOURCE_DIR}/samc21/gcc/gcc/samc21e16a_flash.ld
	-L${CMAKE_SOURCE_DIR}/samc21/gcc/gcc
	-lm
)

add_executable(application
	hal/src/hal_io.c
	hal/src/hal_can_async.c
	hal/utils/src/utils_syscalls.c
	hal/src/hal_delay.c
	hal/utils/src/utils_list.c
	hal/utils/src/utils_assert.c
	hal/src/hal_usart_sync.c
	hal/src/hal_init.c
	hal/src/hal_gpio.c
	hal/utils/src/utils_event.c
	hal/src/hal_sleep.c
	hal/src/hal_atomic.c
	hpl/systick/hpl_systick.c
	hpl/can/hpl_can.c
	hpl/oscctrl/hpl_oscctrl.c
	hpl/core/hpl_init.c
	hpl/core/hpl_core_m0plus_base.c
	hpl/dmac/hpl_dmac.c
	hpl/pm/hpl_pm.c
	hpl/mclk/hpl_mclk.c
	hpl/gclk/hpl_gclk.c
	hpl/osc32kctrl/hpl_osc32kctrl.c
	hpl/sercom/hpl_sercom.c
	hpl/divas/hpl_divas.c
	samc21/gcc/system_samc21.c
	hpl/nvmctrl/hpl_nvmctrl.c
	hal/src/hal_flash.c
	samc21/gcc/gcc/startup_samc21.c
	stdio_start.c
	stdio_redirect/stdio_io.c
	stdio_redirect/gcc/write.c
	stdio_redirect/gcc/read.c
	main.c
	atmel_start.c
	driver_init.c
	led.c
)

target_include_directories(application PRIVATE
	.
	CMSIS/Core/Include
	config
	hal/include
	hal/utils/include
	hpl/can
	hpl/core
	hpl/divas
	hpl/dmac
	hpl/gclk
	hpl/mclk
	hpl/osc32kctrl
	hpl/oscctrl
	hpl/pm
	hpl/port
	hpl/sercom
	hpl/systick
	hpl/nvmctrl
	hri
	samc21/include
	stdio_redirect
)

set_target_properties(application PROPERTIES SUFFIX .elf)

set(BIN_FILE ${CMAKE_CURRENT_BINARY_DIR}/application.bin)
add_custom_command(
	TARGET application POST_BUILD
	COMMAND
		arm-none-eabi-objcopy -O binary $<TARGET_FILE:application> ${BIN_FILE}
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	COMMENT "Objcopying elf to bin ${BIN_FILE}"
)

set(HEX_FILE ${CMAKE_CURRENT_BINARY_DIR}/application.hex)
add_custom_command(
	TARGET application POST_BUILD
	COMMAND
		arm-none-eabi-objcopy -O ihex $<TARGET_FILE:application> ${HEX_FILE}
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	COMMENT "Objcopying elf to hex ${HEX_FILE}"
)
