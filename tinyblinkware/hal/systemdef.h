/**
 * systemdef.h
 * TinyBlink HAL core system definitions
 *
 * Description:
 *      Definitions for the TinyBlink hardware (ATtiny85 MCU) and HAL 
 *      peripherals.
 *
 * Author:          Ray Sun
 * Last Updated:    09/06/2019
 */


#ifndef SYSTEMDEF_H
#define SYSTEMDEF_H

// ############################# DEFINES #######################################

#define F_CPU       1000000U        // Run at 1 MHz

#define TRUE        0xFF            // Logical true
#define FALSE       0x00            // Logical false

// LED driver clock source
// ----- Uncomment the following to use a hardware timer as USI clock -----
// NOT CURRENTLY SUPPORTED WITH LEDDRV PWM since USI uses Timer 0 Compare Match
// A, which is also used as USI Timer 0 Compare Match clock
//#define LEDDRV_USE_HW_CLOCK

#endif
