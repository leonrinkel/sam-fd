#ifndef FLASHER_CRC_H
#define FLASHER_CRC_H

#include <stdint.h>
#include <stddef.h>

uint32_t crc32(const void* buf, size_t size);

#endif /* FLASHER_CRC_H */
