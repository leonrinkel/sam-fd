cmake_minimum_required(VERSION 3.25.2)

project(flasher
	LANGUAGES C
	VERSION 0.1
)

add_executable(
	${PROJECT_NAME}
	crc.c
	flasher.c
	serial_unix.c
	serial_windows.c
)
