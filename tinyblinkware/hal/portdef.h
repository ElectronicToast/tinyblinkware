/**
 * port.h
 * TinyBlink System Port Definitions
 *
 * Description:
 *      This file contains hardware definitions for the TinyBlink (ATtiny85)
 *      I/O ports, pins, and associated registers.
 *
 * Author:          Ray Sun
 * Last Updated:    09/06/2019
 */


#ifndef PORTDEF_H
#define PORTDEF_H

// ############################# INCLUDES ######################################

#include <avr/io.h>

// ############################## DEFINES ######################################

// TinyBlink I/O port
#define IO_PORT         PORTB
#define IO_DDR          DDRB
#define IO_PIN          PINB

// TinyBlink pin definitions
#define PIN_OE          0
#define PIN_OE_MSK      (1 << PIN_OE)
#define PIN_SER         1
#define PIN_SER_MSK     (1 << PIN_SER)
#define PIN_SRCLK       2
#define PIN_SRCLK_MSK   (1 << PIN_SRCLK)
#define PIN_RCLK        3
#define PIN_RCLK_MSK    (1 << PIN_RCLK)
#define PIN_USR         4
#define PIN_USR_MSK     (1 << PIN_USR)
#define PIN_RST         5
#define PIN_RST_MSK     (1 << PIN_RST)


#endif // PORTDEF_H
