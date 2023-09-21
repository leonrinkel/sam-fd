cmake_minimum_required(VERSION 3.25.2)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/toolchain.cmake)

project(baremetal
	LANGUAGES C CXX
	VERSION 0.1
)

option(BUILD_DOC "Build documentation" OFF)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_FLAGS "-fno-exceptions -ffreestanding -fno-jump-tables")

set(CMAKE_C_FLAGS_DEBUG "-O0 -g3")
set(CMAKE_C_FLAGS_RELEASE "-Os -g0")

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
)

add_link_options(
	-mcpu=cortex-m0plus
	-mthumb
	-nolibc
	-nostdlib
	-T${CMAKE_SOURCE_DIR}/link.ld
)

add_executable(
	${PROJECT_NAME}
	src/system.c
)

target_include_directories(
	${PROJECT_NAME}
	PRIVATE inc
)

set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX .elf)

set(BIN_FILE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.bin)
add_custom_command(
	TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND
		arm-none-eabi-objcopy -O binary $<TARGET_FILE:${PROJECT_NAME}> ${BIN_FILE}
	WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
	COMMENT "Objcopying elf to bin ${BIN_FILE}"
)

set(HEX_FILE ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.hex)
add_custom_command(
	TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND
		arm-none-eabi-objcopy -O ihex $<TARGET_FILE:${PROJECT_NAME}> ${HEX_FILE}
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
