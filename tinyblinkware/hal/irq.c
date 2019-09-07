/**
 * irq.c
 * TinyBlink System Interrupt Service Routines
 *
 * Description:
 *      TinyBlink interrupt service routines.
 *
 * Author:          Ray Sun
 * Last Updated:    09/06/2019
 */


// ############################# INCLUDES ######################################

#include "irq.h"
#include "btndrv.h"
#include "leddrv.h"
#include "softtimer.h"

// ########################## PUBLIC FUNCTIONS #################################

// Timer 1 compare match interrupt - millisecond tick
ISR(TIMER1_COMPA_vect) {
    sft_handler();              // Update soft timers
}

// Pin change interrupt request - check if button is pressed
ISR(PCINT0_vect) {
    // Only one PCINT enabled, so it is the button
    btn_handler();
}
