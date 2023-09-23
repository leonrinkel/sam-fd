/* SPDX-License-Identifier: MIT */
/**
 * \file      inc/uart.h
 * \brief     Declaration related to the UART driver
 * \copyright Copyright (c) 2023 Leon Rinkel
 */

#ifndef SAMFD_UART_H
#define SAMFD_UART_H

#include <stdint.h>

void setup_uart(void);

uint8_t uart_write_char(uint8_t c);

/** \brief SERCOM0 IRQ handler */
void __attribute__((interrupt)) sercom0_handler(void);

#endif /* SAMFD_UART_H */