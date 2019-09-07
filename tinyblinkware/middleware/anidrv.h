/**
 * anidrv.h
 * TinyBlink animation driver
 *
 * Description:
 *      Header for TinyBlink animation driver.
 *
 * Author:          Ray Sun
 * Last Updated:    09/06/2019
 */


#ifndef ANIDRV_H
#define ANIDRV_H

// ############################# INCLUDES ######################################

#include <stdint-gcc.h>
#include "../app/appdef.h"

// ############################# DEFINES #######################################

// ########################## PUBLIC FUNCTIONS #################################

#ifdef ANI_USE

// Initializes animation sequence 'pats' with delays 'delay' with 'len' patterns
void ani_init (uint8_t *pats, uint16_t *dels, uint16_t len);

uint8_t ani_get_pat_next();         // Get next pattern of the current sequence
uint16_t ani_get_delay();           // Get the delay of the current pattern
void ani_restart();                 // Restart the current pattern

#endif // ANI_USE


#endif // ANIDRV_H
