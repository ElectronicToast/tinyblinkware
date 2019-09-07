/**
 * main.c
 *
 * Description:
 *      Main loop for TinyBlink ATtiny85 LED keychain firmware.
 *
 * Author:          Ray Sun
 * Last Updated:    09/06/2019
 */


// ############################# INCLUDES ######################################

/*************** BEGIN SYSTEM CODE 1 - DO NOT MODIFY! *************************/
#include "hal/systemdef.h"

#include <avr/io.h>
/**************** END SYSTEM CODE 1 - DO NOT MODIFY! **************************/

//#include <util/delay.h>             // Include for _delay_ms() wait function

/*************** BEGIN SYSTEM CODE 2 - DO NOT MODIFY! *************************/
#include "main.h"

#include "app/appdef.h"
#include "app/animations.h"

#include "hal/system.h"
#include "hal/port.h"
#include "hal/timer.h"
#include "hal/leddrv.h"
#include "hal/btndrv.h"
#include "hal/softtimer.h"
#include "hal/irq.h"

#include "middleware/cycdrv.h"
#include "middleware/anidrv.h"
/**************** END SYSTEM CODE 2 - DO NOT MODIFY! **************************/

#define SFT_PAT                 0           // Use SFT 0 for updating pattern
#define SFT_PWM                 1           // Use SFT 1 for PWM DC updating

#define PAT_CYC_RATE            100         // Default pattern update rate
#define PAT_FAST_RATE           50          // Faster

#define PWM_CYC_RATE            20          // PWM cycling update rate

/*************** BEGIN SYSTEM CODE 3 - DO NOT MODIFY! *************************/

// ############################# MAINLOOP ######################################

// Application entry point
int main(void)
{
    // Initialize peripherals
    sys_pwr_init();             // Save power
    port_init();                // Set up ports
    timer_init();               // Set up timers
    sft_init();                 // Set up software timers
    leddrv_init();              // Set up LED driver
    btn_init();                 // Initialize button driver

    sei();                      // Enable interrupts

/**************** END SYSTEM CODE 3 - DO NOT MODIFY! **************************/

    /********************* BEGIN USER CODE SETUP ******************************/

    uint8_t pattern = 0x80;
    uint16_t pat_delay = 0;
    uint8_t pat_num = 0;
    
    uint8_t pwm_direction = 0;
    uint8_t pwm_level = 0;
    
    leddrv_write(0);            // Clear display
        
    /********************** END USER CODE SETUP *******************************/

    while (1)
    {
        /***************** BEGIN USER CODE LOOP *******************************/

        /* Pattern map:
         * 0 : One-hot cycle, right
         * 1 : One-hot cycle, left
         * 2 : Johnson counter, right
         * 3 : Johnson counter, left
         * 4 : "Half-Johnson" cycle, right
         * 5 : "Half-Johnson" cycle, left
         * 6 : Fibonacci LFSR, left
         * 7 : Galois LFSR, right
         * 8 : my_house animation (See Ruddock House, Caltech)
         * 9 : PWM pulse, or experimental animation
         */
         
        // Check for button press
        if (btn_has_press()) {
            // Go to the next pattern
            pat_num ++;
            
            // Start my_house animation if applicable
            if (pat_num == 8) {
                // Typecast to avoid compiler complaints
                ani_init(   (uint8_t *) ani_my_house_pats, 
                            (uint16_t *) ani_my_house_dels, 
                            ANI_MY_HOUSE_LEN  );
            }            
            else if (pat_num == 9) {     
// Experimental mode
#ifdef EXECUTE
                ani_init(   (uint8_t *) ani_exe_pats, 
                            (uint16_t *) ani_exe_dels, 
                            ANI_EXE_LEN     );
// Otherwise set all LEDs on
#else
                pattern = 0xFF;
                leddrv_pwm_start();
#endif // EXECUTE   
            }

            // Reset if beyond max # pattern
            else if (pat_num > 9) {
                pat_num = 0;
#ifndef EXECUTE    
                leddrv_pwm_stop();
#endif // EXECUTE       
            }                
                
            // Reset pattern soft timer to immediately transition
            sft_reset(SFT_PAT);
        }
        
        // Soft timer 0 for pattern control
        if (sft_is_done(SFT_PAT)) {
            // Get next pattern
            switch (pat_num) {
                case 0:
                    pattern = cyc_onehot_next_r(pattern);
                    pat_delay = PAT_FAST_RATE;
                    break;   
                case 1:
                    pattern = cyc_onehot_next_l(pattern);
                    pat_delay = PAT_FAST_RATE;
                    break;
                case 2:
                    pattern = cyc_johnson_next_r(pattern);
                    pat_delay = PAT_CYC_RATE;
                    break;
                case 3:
                    pattern = cyc_johnson_next_l(pattern);
                    pat_delay = PAT_CYC_RATE;
                    break; 
                case 4:
                    pattern = cyc_halfjohn_next_r(pattern);
                    pat_delay = PAT_CYC_RATE;
                    break;
                case 5:
                    pattern = cyc_halfjohn_next_l(pattern);
                    pat_delay = PAT_CYC_RATE;
                    break;
                case 6:
                    pattern = cyc_fib_lfsr_next(pattern);
                    pat_delay = PAT_CYC_RATE;
                    break;
                case 7:
                    pattern = cyc_gal_lfsr_next(pattern);
                    pat_delay = PAT_CYC_RATE;
                    break;
                case 8:
                    // Must do it in this order since 
                    // 'ani_get_pat_next' post-increments
                    pat_delay = ani_get_delay();
                    pattern = ani_get_pat_next();
                    break;
                case 9:
                    // If using experimental build, get experimental pattern
#ifdef EXECUTE
                    pat_delay = ani_get_delay() * ANI_EXE_DEL_U;
                    pattern = ani_get_pat_next();
#endif // EXECUTE
                    // Otherwise keep all LEDs on
                    break;
                default:
                    break;
            }         
            
            // Write the pattern out       
		    leddrv_write(pattern);
            
            // Restart pattern soft timer with new delay
            sft_start_time(SFT_PAT, pat_delay);
        }          
        
        // Soft timer 1 for PWM
        // Currently just rolls brightness up and down
        if (sft_is_done(SFT_PWM)) {
            
            // Write out current brightness
            leddrv_pwm_set_dc(pwm_level);
            
            // Brightening
            if (pwm_direction == TRUE) {
                pwm_level ++;
                if (pwm_level == 60)
                    pwm_direction = FALSE;
            }
            // Darkening
            else {
                pwm_level --;
                if (pwm_level == 0)
                    pwm_direction = TRUE;
            }
            
            // Restart PWM soft timer
            sft_start_time(SFT_PWM, PWM_CYC_RATE);
        }   

        /****************** END USER CODE LOOP ********************************/
    }
}
