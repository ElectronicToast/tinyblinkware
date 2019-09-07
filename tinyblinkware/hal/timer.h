/**
 * timer.h
 * TinyBlink HAL timer functions
 *
 * Description:
 *      Header for TinyBlink HAL timer functions with system timer register
 *      definitions.
 *
 * Author:          Ray Sun
 * Last Updated:    09/06/2019
 */


#ifndef TIMER_H
#define TIMER_H

// ############################# INCLUDES ######################################

#include <avr/io.h>
#include <stdint-gcc.h>
#include "timerdef.h"

// ############################## DEFINES ######################################

// Default - HS timer disabled
#define HS_TCCR_A_MSK_OFF       0b00000000
#define HS_TCCR_B_MSK_OFF       0b00000000

// PWM mode
#define HS_TCCR_A_MSK_PWM       0b11000001
//                                11------          A inverting mode, fast PWM
//                                --00----          B disconnected
//                                ----00--          Reserved
//                                ------01          Phase correct PWM mode
#define HS_TCCR_B_MSK_PWM       0b00000001
//                                00------          Do not force output compare
//                                --00----          Reserved
//                                ----0---          PC PWM mode, TOV don't care
//                                -----001          Do not prescale

#define HS_TOP                  255

#define TICK_TCCR_MSK           0b10000100
//                                1-------          Clear on compare match C
//                                -0------          No PWM
//                                --00----          No output on OC1A
//                                ----0100          Prescale by 8
// Can't clear timer on compare match A, so clear on compare match C and
// set OCRA and OCRC to the same value

#define TICK_TCNT_INIT          0

#define TICK_RATE               124         // 125 timer counts per ms given
                                            // (1 MHz CPU) / (1000 * prescale)
                                            // = TICK_RATE counts per ms
                                            
#define TIMSK_MSK               0b01000000
//                                0-------          Reserved
//                                -10-----          Timer 1 A compare match
//                                ---00---          Timer 0 compare disabled
//                                -----0--          Timer 1 overflow disabled
//                                ------0-          Timer 1 overflow disabled
//                                -------0          Reserved

// ########################## PUBLIC FUNCTIONS #################################

void timer_init();              // Initialize system hardware timers


#endif // TIMER_H
