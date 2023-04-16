cmake_minimum_required(VERSION 3.25.2)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/toolchain.cmake)
set(CMAKE_C_COMPILER_WORKS 1)
set(CMAKE_CXX_COMPILER_WORKS 1)

project(baremetal
	LANGUAGES CXX
	VERSION 0.1
)

option(BUILD_DOC "Build documentation" ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-fno-exceptions -ffreestanding -fno-jump-tables")

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g3")
set(CMAKE_CXX_FLAGS_RELEASE "-Os -g0")

add_compile_options(
	-mcpu=cortex-m0plus
	-mthumb
	-Wall
	-Wextra
	-Wno-packed-bitfield-compat
	-Wno-missing-field-initializers
)

add_link_options(
	-mcpu=cortex-m0plus
	-mthumb
	-nolibc
	-nostdlib
	-T${CMAKE_SOURCE_DIR}/link.ld
)

add_executable(baremetal
	src/gclk.cpp
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

find_package(Doxygen)
if(BUILD_DOC AND DOXYGEN_FOUND)
	set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
	set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

	configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

	add_custom_target(doxygen ALL
		COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
		WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
		VERBATIM
	)
endif(BUILD_DOC AND DOXYGEN_FOUND)
