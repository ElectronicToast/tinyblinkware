/**
 * cycdrv.c
 * TinyBlink cycle driver
 *
 * Description:
 *      Functions for manipulating patterns of TinyBlink LEDs in logically
 *      simple ways, such as one-hot or LFSR.
 *
 * Author:          Ray Sun
 * Last Updated:    09/06/2019
 */


// ############################# INCLUDES ######################################

#include "cycdrv.h"

// ########################## PUBLIC FUNCTIONS #################################

// One-hot pattern update
//      Assumes input is one-hot, but will correct within 8 cycles
#ifdef CYC_USE_ONEHOT_R
uint8_t cyc_onehot_next_r (uint8_t pat) {
    if (pat == 0x00) 
        return 0x80;
    else 
        return pat >> 1;
}
#endif // CYC_USE_ONEHOT_R

#ifdef CYC_USE_ONEHOT_L
uint8_t cyc_onehot_next_l (uint8_t pat) {
    if (pat == 0x00)
        return 0x01;
    else
        return pat << 1;
}
#endif // CYC_USE_ONEHOT_L

// "Johnson counters" - circling all on to all off by 'bit shifts'
//      Assumes valid input, but will correct within 8 cycles
#ifdef CYC_USE_JOHNSON_R
uint8_t cyc_johnson_next_r (uint8_t pat) {
    if (pat == 0xFF)
        return 0x7F;
    else if (pat == 0x00)
        return 0x80;
    else
        return ((int8_t) pat ) >> 1;
}
#endif // CYC_USE_JOHNSON_R

#ifdef CYC_USE_JOHNSON_L
uint8_t cyc_johnson_next_l (uint8_t pat) {
    if (pat == 0xFF)
        return 0xFE;
    else if (pat == 0x00)
        return 0x01;
    else {
        uint8_t lsb = pat & 0x01;
        pat <<= 1;
        return pat | lsb;           // Turn on low bit if was on
    }
}
#endif // CYC_USE_JOHNSON_L

// "Half-Johnson" counters - some number of LEDs on all the time
//      Depends on what previous pattern was
//      Application code should set pattern to known value upon start of cycle
#ifdef CYC_USE_HALFJOHN_R
uint8_t cyc_halfjohn_next_r (uint8_t pat) {
    uint8_t msb = (pat & 0x01) << 7;        // Get new MSB to shift in
    return (pat >> 1) | msb;
}
#endif // CYC_USE_HALFJOHN_R

#ifdef CYC_USE_HALFJOHN_L
uint8_t cyc_halfjohn_next_l (uint8_t pat) {
    uint8_t lsb = (pat & 0x80) >> 7;        // Get new LSB to shift in
    return (pat << 1) | lsb;
}
#endif // CYC_USE_HALFJOHN_L

// Fibonacci LFSR - left shift
//      No checking for illegal state of 0x00!
#ifdef CYC_USE_FIB_LFSR
uint8_t cyc_fib_lfsr_next (uint8_t pat) {
    // XOR bit 1, 2, 3, and 7
    uint8_t lsb = (pat >> 7) ^ ((pat & 0x08) >> 3) ^ 
                  ((pat & 0x04) >> 2) ^ ((pat & 0x02) >> 1);
    return (pat << 1) | lsb;
}
#endif // CYC_USE_FIB_LFSR

// Galois LFSR - right shift
//      No checking for illegal state of 0x00!
#ifdef CYC_USE_GAL_LFSR
uint8_t cyc_gal_lfsr_next (uint8_t pat) {
    uint8_t lsb = pat & 0x01;               // Get the LSB
    pat >>= 1;                              // Shift
    if (lsb)                                // Apply toggle mask of B8 if carry
        return pat ^ 0xB8;
    else 
        return pat;
}
#endif // CYC_USE_GAL_LFSR
