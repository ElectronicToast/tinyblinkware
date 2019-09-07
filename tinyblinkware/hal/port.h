/**
 * port.h
 * TinyBlink HAL Port Routines
 *
 * Description:
 *      Header for TinyBlink I/O port routines.
 *
 * Author:          Ray Sun
 * Last Updated:    09/06/2019
 */


#ifndef PORT_H
#define PORT_H

// ############################# INCLUDES ######################################

#include "portdef.h"

// ############################## DEFINES ######################################

#define DDR_MSK         0b00001111          // All pins except USER are output
#define PORT_INIT       0b00000000          // Initialize all output to off

// ########################## PUBLIC FUNCTIONS #################################

void port_init();

#endif // PORT_H
