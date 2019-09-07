/**
 * port.c
 * TinyBlink HAL Port Routines
 *
 * Description:
 *      Functions to service TinyBlink I/O ports.
 *
 * Author:          Ray Sun
 * Last Updated:    09/06/2019
 */


// ############################# INCLUDES ######################################

#include "port.h"

// ########################## PUBLIC FUNCTIONS #################################

// Initialize all I/O pins
void port_init() {
    IO_DDR = DDR_MSK;
    IO_PORT = PORT_INIT;
}
