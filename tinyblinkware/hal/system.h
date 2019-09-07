/**
 * system.h
 * TinyBlink HAL system functions
 *
 * Description:
 *      Header for TinyBlink HAL system functions.
 *
 * Author:          Ray Sun
 * Last Updated:    09/06/2019
 */


#ifndef SYSTEM_H
#define SYSTEM_H

// ############################# INCLUDES ######################################

#include <avr/io.h>

// ############################## DEFINES ######################################

#define SYS_MCUCR_MSK       0b00100000
//                            0-------          BrownOutDetect sleep - not used
//                            -0------          Pullups not disabled
//                            --1-----          Enable sleep
//                            ---00---          Sleep in idle mode
//                            -----0--          BOD sleep not enabled
//                            ------00          No external interrupt on INT0

#define SYS_PRR_MSK         0b00000001
//                            0000----          Reserved
//                            ----00--          Both timers enabled
//                            ------0-          USI enabled
//                            -------1          ADC disabled

// ########################## PUBLIC FUNCTIONS #################################

// Initialize power management
void sys_pwr_init();

// TODO: Add functions for sleeping based on a WDT and on a pin change
// TODO: Implement Brown Out Detector disable to save power

#endif