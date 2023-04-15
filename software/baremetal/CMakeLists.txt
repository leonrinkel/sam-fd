cmake_minimum_required(VERSION 3.25.2)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/toolchain.cmake)
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

project(baremetal
	LANGUAGES CXX
	VERSION 0.1
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS -fno-exceptions)

add_compile_options(
	-mcpu=cortex-m0plus
	-mthumb
	-O0
	-Wall
	-Wextra
	-Wno-packed-bitfield-compat
)

add_link_options(
	-mcpu=cortex-m0plus
	-mthumb
	-nolibc
	-nostdlib
	-T${CMAKE_SOURCE_DIR}/link.ld
)

add_executable(baremetal
	src/mclk.cpp
	src/optional.cpp
	src/port.cpp
	src/samfd.cpp
	src/system.cpp
)

target_include_directories(baremetal PRIVATE inc)

set_target_properties(baremetal PROPERTIES SUFFIX .elf)

set(BIN_FILE ${CMAKE_CURRENT_BINARY_DIR}/baremetal.bin)
add_custom_command(
	TARGET baremetal POST_BUILD
	COMMAND
		arm-none-eabi-objcopy -O binary $<TARGET_FILE:baremetal> ${BIN_FILE}
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	COMMENT "Objcopying elf to bin ${BIN_FILE}"
)

set(HEX_FILE ${CMAKE_CURRENT_BINARY_DIR}/baremetal.hex)
add_custom_command(
	TARGET baremetal POST_BUILD
	COMMAND
		arm-none-eabi-objcopy -O ihex $<TARGET_FILE:baremetal> ${HEX_FILE}
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	COMMENT "Objcopying elf to hex ${HEX_FILE}"
)
