/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <hal_gpio.h>

// SAMC21 has 9 pin functions

#define GPIO_PIN_FUNCTION_A 0
#define GPIO_PIN_FUNCTION_B 1
#define GPIO_PIN_FUNCTION_C 2
#define GPIO_PIN_FUNCTION_D 3
#define GPIO_PIN_FUNCTION_E 4
#define GPIO_PIN_FUNCTION_F 5
#define GPIO_PIN_FUNCTION_G 6
#define GPIO_PIN_FUNCTION_H 7
#define GPIO_PIN_FUNCTION_I 8

#define PA05 GPIO(GPIO_PORTA, 5)
#define PA06 GPIO(GPIO_PORTA, 6)
#define TX_ACT GPIO(GPIO_PORTA, 9)
#define RX_ACT GPIO(GPIO_PORTA, 10)
#define CAN_ERR GPIO(GPIO_PORTA, 17)
#define CAN_EN GPIO(GPIO_PORTA, 18)
#define PA24 GPIO(GPIO_PORTA, 24)
#define PA25 GPIO(GPIO_PORTA, 25)
#define CAN_STB GPIO(GPIO_PORTA, 27)

#endif // ATMEL_START_PINS_H_INCLUDED
