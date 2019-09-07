/**
 * softtimer.c
 * TinyBlink HAL Software Timer
 *
 * Description:
 *      Functions providing software-defined millisecond timers for general
 *      TinyBlink application usage.
 *
 * Author:          Ray Sun
 * Last Updated:    09/06/2019
 */


// ############################# INCLUDES ######################################

#include "softtimer.h"

#ifdef SFT_USE

// ######################### PRIVATE VARIABLES #################################

static uint16_t __soft_timer[SFT_N];     // 2 bytes each, for maximum 65.536 s

// ########################## PUBLIC FUNCTIONS #################################

// Initializes all soft timers to bottom value
void sft_init() {
    for (uint8_t i = 0; i < SFT_N; i++) {
        __soft_timer[i] = SFT_BOTTOM;
    }
}

// Starts a delay on soft timer 'sftim' for 'delay' milliseconds
void sft_start_time(uint8_t sftim, uint16_t delay) {
    __soft_timer[sftim] = delay;
}

// Clears a soft timer 'sftim'
void sft_reset(uint8_t sftim) {
    __soft_timer[sftim] = SFT_BOTTOM;
}

// Check if soft timer `sftim` is done
uint8_t sft_is_done(uint8_t sftim) {
    return (__soft_timer[sftim] == SFT_BOTTOM) ? TRUE : FALSE;
}

// Handler to call once per millisecond
void sft_handler() {
    for (uint8_t i = 0; i < SFT_N; i++) {
        if (__soft_timer[i] != SFT_BOTTOM) {
            __soft_timer[i] --;
        }
    }
}


#endif // SFT_USE
