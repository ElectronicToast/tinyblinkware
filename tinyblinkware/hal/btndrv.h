/**
 * btndrv.h
 * TinyBlink HAL Button Driver
 *
 * Description:
 *      Header for TinyBlink HAL button driver functions.
 *
 * Author:          Ray Sun
 * Last Updated:    09/06/2019
 */


#ifndef BTNDRV_H
#define BTNDRV_H

// ############################# INCLUDES ######################################

#include "portdef.h"

// ############################## DEFINES ######################################

#define BTN_GIMSK_MSK       0b00100000
//                            0--00000              Reserved
//                            -0------              External INT disabled
//                            --1-----              Pin change interrupt enabled

#define BTN_PCMSK_MSK       PIN_USR_MSK         //  Enable PC interrupt on pin

#define BTN_PIN             PIN_USR
#define BTN_PIN_MSK         PIN_USR_MSK

// ########################## PUBLIC FUNCTIONS #################################

void btn_init();
void btn_wait_press();              // Blocking wait for press
uint8_t btn_is_pressed();           // Check button state
uint8_t btn_has_press();            // Non-blocking has been pressed

void btn_handler();                 // To be called by PC interrupt


#endif // BTNDRV_H
