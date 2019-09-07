/**
 * system.c
 * TinyBlink HAL system functions
 *
 * Description:
 *      TinyBlink HAL system functions for power and sleep management.
 *
 * Author:          Ray Sun
 * Last Updated:    09/06/2019
 */


// ############################# INCLUDES ######################################

#include "system.h"

// ########################## PUBLIC FUNCTIONS #################################

// Enable system sleep and disable unused peripherals
void sys_pwr_init() {
    MCUCR = SYS_MCUCR_MSK;
    PRR = SYS_PRR_MSK;
}

// TODO: Add functions for sleeping based on a WDT and on a pin change
// TODO: Implement Brown Out Detector disable to save power
