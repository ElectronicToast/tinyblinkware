/**
 * timer.c
 * TinyBlink HAL timer functions
 *
 * Description:
 *      TinyBlink HAL timer functions for initialization of hardware timers.
 *
 * Author:          Ray Sun
 * Last Updated:    09/06/2019
 */


// ############################# INCLUDES ######################################

#include "timer.h"

// ########################## PUBLIC FUNCTIONS #################################

void timer_init() {
    TICK_TCCR = TICK_TCCR_MSK;              // Set up 1 ms CTC tick
    TICK_OCR_A = TICK_RATE;                 
    TICK_OCR_C = TICK_RATE;
    TICK_TCNT = TICK_TCNT_INIT;             // Clear timer on startup

    // Timer defaults to disabled on power up
    HS_TCCR_A = HS_TCCR_A_MSK_OFF;          // PWM initially off
    HS_TCCR_B = HS_TCCR_B_MSK_OFF;
    
    SYS_TIMSK = TIMSK_MSK;
}
