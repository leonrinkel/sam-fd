#if defined __linux__ || defined __APPLE__

#include <stdbool.h>
#include <stdint.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include "serial.h"

static int portfd = 0;

bool serial_open(const char* port)
{
	struct termios tty;

	/* Open serial port */
	portfd = open(port, O_RDWR | O_NOCTTY | O_SYNC);
	if (portfd < 0)
	{
		perror("open()");
		return false;
	}

	/* Read TTY attrs */
	if (tcgetattr(portfd, &tty) != 0)
	{
		perror("tcgetattr()");
		return false;
	}

	/* Change TTY baudrate */
	cfsetospeed(&tty, B115200);
	cfsetispeed(&tty, B115200);

	/* Set TTY attributes */
	if (tcsetattr(portfd, TCSANOW, &tty) != 0)
	{
		perror("tcsetattr()");
		return false;
	}

	return true;
}

bool serial_write(uint8_t* data, uint16_t len)
{
	ssize_t nwritten;

	/* Serial write from buffer */
	nwritten = write(portfd, data, len);
	if (nwritten < 0)
	{
		perror("write()");
		return false;
	}

	/* Check amount written */
	if (nwritten != len)
	{
		return false;
	}

	/* Flush port */
	if (fsync(portfd) < 0)
	{
		perror("fsync()");
		return false;
	}

	return true;
}

bool serial_read(uint8_t* data, uint16_t len)
{
	ssize_t nread;

	/* Serial read to buffer */
	nread = read(portfd, data, len);
	if (nread < 0)
	{
		perror("read()");
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
	if (portfd != 0)
	{
		close(portfd);
	}
}

#endif
