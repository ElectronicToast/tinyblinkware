/**
 * cycdrv.h
 * TinyBlink cycle driver
 *
 * Description:
 *      Header for TinyBlink cycle driver.
 *
 * Author:          Ray Sun
 * Last Updated:    09/06/2019
 */


#ifndef CYCDRV_H
#define CYCDRV_H

// ############################# INCLUDES ######################################

#include <stdint-gcc.h>
#include "../app/appdef.h"

// ############################# DEFINES #######################################

// ########################## PUBLIC FUNCTIONS #################################

// One-hot cycle
#ifdef CYC_USE_ONEHOT_R
uint8_t cyc_onehot_next_r (uint8_t pat);
#endif // CYC_USE_ONEHOT_R
#ifdef CYC_USE_ONEHOT_L
uint8_t cyc_onehot_next_l (uint8_t pat);
#endif // CYC_USE_ONEHOT_L

// "Johnson counters" - circling all on to all off by 'bit shifts'
#ifdef CYC_USE_JOHNSON_R
uint8_t cyc_johnson_next_r (uint8_t pat);
#endif // CYC_USE_JOHNSON_R
#ifdef CYC_USE_JOHNSON_L
uint8_t cyc_johnson_next_l (uint8_t pat);
#endif // CYC_USE_JOHNSON_L

// "Half-Johnson" counters - some LEDs on all the time, circling
#ifdef CYC_USE_HALFJOHN_R
uint8_t cyc_halfjohn_next_r (uint8_t pat);
#endif // CYC_USE_HALFJOHN_R
#ifdef CYC_USE_HALFJOHN_L
uint8_t cyc_halfjohn_next_l (uint8_t pat);
#endif // CYC_USE_HALFJOHN_L

// Fibonacci LFSR
#ifdef CYC_USE_FIB_LFSR
uint8_t cyc_fib_lfsr_next (uint8_t pat);
#endif // CYC_USE_FIB_LFSR

// Galois LFSR
#ifdef CYC_USE_GAL_LFSR
uint8_t cyc_gal_lfsr_next (uint8_t pat);
#endif // CYC_USE_GAL_LFSR

#endif // CYCDRV_H
