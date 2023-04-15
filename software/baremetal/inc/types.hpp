/**
 * \file   inc/type.hpp
 * \author Rinkel, Leon <leon@rinkel.me>
 *
 * Definitions of some commonly used types.
 */

#pragma once

typedef unsigned char  uint8_t;  /**< Unsigned integer of 8-bit size. */
typedef unsigned short uint16_t; /**< Unsigned integer of 16-bit size. */
typedef unsigned int   uint32_t; /**< Unsigned integer of 32-bit size. */

typedef signed char  int8_t;  /**< Signed integer of 8-bit size. */
typedef signed short int16_t; /**< Signed integer of 16-bit size. */
typedef signed int   int32_t; /**< Signed integer of 32-bit size. */

typedef void (*exception_handler_t)(void); /**< Processor exception handler. */
