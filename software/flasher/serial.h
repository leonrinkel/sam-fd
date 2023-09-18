#ifndef SERIAL_H
#define SERIAL_H

#include <stdbool.h>
#include <stdint.h>

bool serial_open(const char* port);

bool serial_write(uint8_t* data, uint16_t len);

bool serial_read(uint8_t* data, uint16_t len);

void serial_close(void);

#endif /* SERIAL_H */
