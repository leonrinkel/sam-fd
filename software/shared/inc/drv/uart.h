/* SPDX-License-Identifier: MIT */
/**
 * \file      inc/drv/uart.h
 * \brief     Declaration related to the UART driver
 * \copyright Copyright (c) 2023 Leon Rinkel
 */

#ifndef SAMFD_DRV_UART_H
#define SAMFD_DRV_UART_H

#include <stdint.h>

void setup_uart(void);

uint8_t uart_read_char(char* c);

uint8_t uart_write_char(char c);

uint16_t uart_available(void);

uint16_t uart_read(char* buf, uint16_t len);

uint16_t uart_write(char* buf, uint16_t len);

/** \brief SERCOM0 IRQ handler */
void __attribute__((interrupt)) sercom0_handler(void);

#endif /* SAMFD_DRV_UART_H */
