/**
 * softtimer.h
 * TinyBlink HAL Software Timer
 *
 * Description:
 *      Header for TinyBlink HAL software timer.
 *
 * Author:          Ray Sun
 * Last Updated:    09/06/2019
 */


#ifndef SOFTTIMER_H
#define SOFTTIMER_H

// ############################# INCLUDES ######################################

#include <stdint-gcc.h>
#include "../app/appdef.h"
#include "systemdef.h"

#ifdef SFT_USE

// ############################# DEFINES #######################################

#define SFT_TOP         65535           // Allowed counter top and bottom values
#define SFT_BOTTOM      0

// ########################## PUBLIC FUNCTIONS #################################

void sft_init();                        // Set up soft timers
void sft_start_time(uint8_t sftim, uint16_t delay); // Start a soft timer
void sft_reset(uint8_t sftim);          // Reset a soft timer
uint8_t sft_is_done(uint8_t sftim);     // Check if soft timer is done
void sft_handler();                     // Handler to call once per millisecond

#endif // SFT_USE


#endif // SOFTTIMER_H
