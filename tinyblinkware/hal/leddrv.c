/**
 * leddrv.c
 * TinyBlink HAL LED Driver
 *
 * Description:
 *      Functions for writing LED data to TinyBlink hardware.
 *
 * Author:          Ray Sun
 * Last Updated:    09/06/2019
 */


// ############################# INCLUDES ######################################

#include "leddrv.h"
#include "portdef.h"
#include <util/atomic.h>

// ########################## PUBLIC FUNCTIONS #################################

// Set up USI interface for master only SPI
void leddrv_init (void) {
	USICR = USICR_MSK;			        // Initialize USI in three wire mode
}

// Write LED data
void leddrv_write (uint8_t leds) {
    USIDR = leds;                       // Load output data 
    USISR = 1 << USIOIF;                // Clear transfer complete flag
    
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE)   // Ensure consistent clock period
    {
        // Wait for USI complete flag
        do  {
            // Strobe clock with software if not using hardware clock
#ifndef LEDDRV_USE_HW_CLOCK
            USICR |= (1<<USITC);        // Toggle clock to strobe USI out
#endif // LEDDRV_USE_HW_CLOCK
        } while ( !(USISR & (1 << USIOIF) ) );
    }     
    
    IO_PORT |= PIN_RCLK_MSK;            // Pulse RCLK to latch LED state
    IO_PORT &= ~PIN_RCLK_MSK;
}

// Enables PWM brightness control
void leddrv_pwm_start () {
    LED_PWM_TCCR_A = HS_TCCR_A_MSK_PWM; // Set up PWM
    LED_PWM_TCCR_B = HS_TCCR_B_MSK_PWM;
    LED_PWM_TCNT = 0;                   // Clear count to avoid glitch
    LED_PWM_OCR = LED_PWM_DUTY_INIT;
}

// Disable PWM control
void leddrv_pwm_stop() {
    LED_PWM_TCCR_A = HS_TCCR_A_MSK_OFF; // Turn off the PWM
    LED_PWM_TCCR_B = HS_TCCR_B_MSK_OFF;
}

// Set duty cycle of PWM
void leddrv_pwm_set_dc (uint8_t duty) {
    LED_PWM_OCR = duty;
}
