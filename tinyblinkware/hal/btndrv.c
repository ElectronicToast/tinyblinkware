/**
 * btndrv.c
 * TinyBlink HAL Button Driver
 *
 * Description:
 *      Functions for reading TinyBlink button presses using an external
 *      pin change interrupt.
 *
 * Author:          Ray Sun
 * Last Updated:    09/06/2019
 */


// ############################# INCLUDES ######################################

#include <stdint-gcc.h>
#include <util/atomic.h>
#include "systemdef.h"
#include "btndrv.h"

// ######################### PRIVATE VARIABLES #################################

static uint8_t __btn_down = 0;      // Button has been pressed since last check

// ########################## PUBLIC FUNCTIONS #################################

// Initialize button driver
void btn_init() {
    // Modify if necessary, if additional interrupts are added
    GIMSK = BTN_GIMSK_MSK;
    PCMSK = BTN_PCMSK_MSK;
}

// Blocking wait for button press
void btn_wait_press() {
    while (__btn_down != TRUE) {;}

    __btn_down = FALSE;
}

// Check button status
uint8_t btn_is_pressed() {
    return __btn_down;
}

// Nonblocking wait for button press - return TRUE if button is down
// and otherwise FALSE
uint8_t btn_has_press() {
    uint8_t __btn_status = FALSE;

    // Atomic check-and-clear - restores I flag
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
        if (__btn_down) {
            __btn_down = FALSE;
            __btn_status = TRUE;
        }
        else {
            __btn_status = FALSE;
        }
    }

    return __btn_status;
}

// Handler for button presses, to be called by pin change ISR
void btn_handler() {
    // If the button is down (falling edge), set the flag
    if ( !(IO_PIN & BTN_PIN_MSK) ) {
        __btn_down = TRUE;
    }     
}
