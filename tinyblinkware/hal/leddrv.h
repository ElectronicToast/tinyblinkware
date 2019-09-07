/**
 * leddrv.c
 * TinyBlink HAL LED Driver
 *
 * Description:
 *      Header for TinyBlink HAL LED driver.
 *
 * Author:          Ray Sun
 * Last Updated:    09/06/2019
 */


#ifndef LEDDRV_H
#define LEDDRV_H

// ############################# INCLUDES #######################################

#include <stdint-gcc.h>
#include "timer.h"

// ############################# DEFINES #######################################

// USI control register - for quasi-SPI with shift register
#ifdef LEDDRV_USE_HW_CLOCK
#define USICR_MSK     0b00010101
//                      0-------            Disable start condition interrupt
//                      -0------            Disable counter overflow interrupt
//                      --01----            Three wire mode - "SPI"
//                      ----01--            Timer 0 compare match clock source
//                      ------X-            Don't care
//                      -------1            Toggle USCK
#else
#define USICR_MSK     0b00011011
//                      0-------            Disable start condition interrupt
//                      -0------            Disable counter overflow interrupt
//                      --01----            Three wire mode - "SPI"
//                      ----10--            Positive edge external clock
//                      ------1-            Software clock strobe
//                      -------1            Toggle USCK
#endif

// Default PWM start duty cycle
#define LED_PWM_DUTY_INIT       0
    
// ########################## PUBLIC FUNCTIONS #################################

void leddrv_init();
void leddrv_write (uint8_t leds);

void leddrv_pwm_start();
void leddrv_pwm_stop();
void leddrv_pwm_set_dc (uint8_t duty);


#endif // LEDDRV_H
