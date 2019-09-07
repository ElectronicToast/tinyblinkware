/**
 * timerdef.h
 * TinyBlink HAL core timer definitions
 *
 * Description:
 *      Definitions for the TinyBlink hardware (ATtiny85) timer registers.
 *
 * Author:          Ray Sun
 * Last Updated:    09/06/2019
 */


#ifndef TIMERDEF_H
#define TIMERDEF_H

// ############################# INCLUDES ######################################

#include <avr/io.h>

// ############################## DEFINES ######################################

// Shared registers
#define TIM_GTCCR       GTCCR
#define TIM_TIMSK       TIMSK

// 'High-speed' timer for PWM and USI - Timer 0
#define HS_TCCR_A       TCCR0A
#define HS_TCCR_B       TCCR0B
#define HS_TCNT         TCNT0
#define HS_OCR_A        OCR0A
#define HS_OCR_B        OCR0B

// Definitions for LED PWM driver
#define LED_PWM_TCCR_A  TCCR0A
#define LED_PWM_TCCR_B  TCCR0B
#define LED_PWM_TCNT    TCNT0
#define LED_PWM_OCR     OCR0A

// Le millisecond tick timer - Timer 1
#define TICK_TCCR       TCCR1
#define TICK_TCNT       TCNT1
#define TICK_OCR_A      OCR1A
#define TICK_OCR_B      OCR1B
#define TICK_OCR_C      OCR1C

#define SYS_TIMSK       TIMSK


#endif // TIMERDEF_H
