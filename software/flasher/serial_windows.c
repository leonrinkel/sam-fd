#if defined _WIN32

#include "serial.h"

#include <stdbool.h>
#include <stdint.h>
#include <windows.h>
#include <stdio.h>

static HANDLE hSerial = NULL; /** Serial port handle */

bool serial_open(const char* port)
{
	LPSTR errormsg; /** Error message string */
	DCB serialParams = {0}; /** Serial port parameters */

	/* Open serial port */
	hSerial = CreateFile(
		port, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
	if (hSerial == INVALID_HANDLE_VALUE)
	{
		FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPSTR) &errormsg, 0, NULL
		);
		fprintf(stderr, "CreateFile(): %s", errormsg);
		LocalFree(errormsg);

		return false;
	}

	/* Read serial params */
	serialParams.DCBlength = sizeof(DCB);
	if (!GetCommState(hSerial, &serialParams))
	{
		FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPSTR) &errormsg, 0, NULL
		);
		fprintf(stderr, "GetCommState(): %s", errormsg);
		LocalFree(errormsg);

		return false;
	}

	/* Change serial baudrate */
	serialParams.BaudRate = 115200;

	/* Set serial params */
	if (!SetCommState(hSerial, &serialParams))
	{
		FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPSTR) &errormsg, 0, NULL
		);
		fprintf(stderr, "SetCommState(): %s", errormsg);
		LocalFree(errormsg);

		return false;
	}

	return true;
}

bool serial_write(uint8_t* data, uint16_t len)
{
	DWORD nwritten; /** Number of bytes written via serial port */
	LPSTR errormsg; /** Error message string */

	/* Serial write from buffer */
	if (!WriteFile(hSerial, data, len, &nwritten, NULL))
	{
		FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPSTR) &errormsg, 0, NULL
		);
		fprintf(stderr, "WriteFile(): %s", errormsg);
		LocalFree(errormsg);

		return false;
	}

	/* Check amount written */
	if (nwritten != len)
	{
		return false;
	}

	/* Flush port */
	if (!FlushFileBuffers(hSerial))
	{
		FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPSTR) &errormsg, 0, NULL
		);
		fprintf(stderr, "FlushFileBuffers(): %s", errormsg);
		LocalFree(errormsg);

		return false;
	}

	return true;
}

bool serial_read(uint8_t* data, uint16_t len)
{
	DWORD nread; /** Number of bytes read via serial port */
	LPSTR errormsg; /** Error message string */

	/* Serial read to buffer */
	if (!ReadFile(hSerial, data, len, &nread, NULL))
	{
		FormatMessage(
			FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM |
			FORMAT_MESSAGE_IGNORE_INSERTS,
			NULL, GetLastError(), MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
			(LPSTR) &errormsg, 0, NULL
		);
		fprintf(stderr, "ReadFile(): %s", errormsg);
		LocalFree(errormsg);

		return false;
	}

	/* Check amount read */
	if (nread != len)
	{
		return false;
	}

	return true;
}

void serial_close(void)
{
	/* Close serial port */
	if (hSerial != NULL)
	{
		CloseHandle(hSerial);
	}
}

#endif