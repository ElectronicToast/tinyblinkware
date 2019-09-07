/**
 * anidrv.c
 * TinyBlink animation driver
 *
 * Description:
 *      Functions for retrieving a sequence of LED patterns stored in program
 *      memory for displaying.
 *
 * Notes:
 *      No error checking is performed. 
 *
 * Author:          Ray Sun
 * Last Updated:    09/06/2019
 */


// ############################# INCLUDES ######################################

#include <stddef.h>
#include <avr/pgmspace.h>
#include "anidrv.h"

// ######################### PRIVATE VARIABLES #################################

#ifdef ANI_USE

static uint8_t  *__ani_pats = NULL;
static uint16_t *__ani_dels = NULL;
static uint16_t  __ani_idx  = 0;
static uint16_t  __ani_len  = 0;

// ########################## PUBLIC FUNCTIONS #################################

// Initializes animation sequence 'pats' with delays 'delay' with 'len' patterns
void ani_init (uint8_t *pats, uint16_t *dels, uint16_t len) {
    __ani_pats = pats;
    __ani_dels = dels;
    __ani_len = len;
    __ani_idx = 0;
}

// Get the current pattern of the current sequence with postincrement
uint8_t ani_get_pat_next() {
    // Since this is program memory, must use a read function
    uint8_t pat = pgm_read_byte(__ani_pats + __ani_idx);
    
    // Increment index
    __ani_idx ++;
    if (__ani_idx >= __ani_len)
        __ani_idx = 0;
        
    return pat;
}

// Get the delay of the current pattern
uint16_t ani_get_delay() {
    // Since this is program memory, must use a read function
    return pgm_read_word(__ani_dels + __ani_idx);
}

// Restart the current pattern
void ani_restart() {
    __ani_idx = 0;
}

#endif // ANI_USE
