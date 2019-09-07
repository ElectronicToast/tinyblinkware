/**
 * animations.h
 * TinyBlink application animations
 *
 * Description:
 *      This file contains animations stored in program memory for TinyBlink,
 *      intended to be displayed with anidrv.
 *
 * Author:          Ray Sun
 * Last Updated:    09/06/2019
 */


#ifndef ANIMATIONS_H
#define ANIMATIONS_H

// ############################# INCLUDES ######################################

#include <avr/pgmspace.h>
#include "appdef.h"

// ############################# DEFINES #######################################

#ifdef PAT_USE_RUDDOCK

#define MS_T            200                     // Period of Morse code, in ms
#define MS_3T           MS_T * 3                // 3x period (between letter)
#define MS_7T           MS_T * 7                // 7x period (between word)
#define MS_d            MS_T                    // Dot
#define MS_D            MS_3T                   // Dash
#define MS_S            MS_T                    // Space between dot/dash in char
#define MS_CS           MS_3T                   // Space between letters
#define MS_WS           MS_7T                   // Space between words
#define MS_SOM          3500                    // Start of message delay
#define MS_EOM          3500                    // End of message delay

// Morse code for a certain Ruddock House motto
#define ANI_MY_HOUSE_LEN    285

// TODO: Encapsulate each Morse character in a definition to make Morse patterns
// easier to write

// SOM and EOM indicated by every other LED on
const uint8_t ani_my_house_pats[ANI_MY_HOUSE_LEN] PROGMEM = {
    0x00,                                       // SOM delay
    0xFF, 0x00, 0xFF,                           // M        - -
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,   // Y        - . - -
    0x00,                                       // []
    0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,   // H        . . . . 
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF,               // O        - - - 
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF,               // U        . . -
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF,               // S        . . . 
    0x00,
    0xFF,                                       // E        .
    0x00,                                       // []
    0xFF, 0x00, 0xFF, 0x00, 0xFF,               // W        . - - 
    0x00,    
    0xFF, 0x00, 0xFF,                           // I        . .
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,   // L        . - . .
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,   // L        . - . .
    0x00,                                       // []
    0xFF, 0x00, 0xFF,                           // N        - .
    0x00,
    0xFF,                                       // E        .
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,   // V        . . . -
    0x00,
    0xFF,                                       // E        .
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF,               // R        . - .
    0x00,                                       // []
    0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,   // B        - . . .
    0x00,
    0xFF,                                       // E        .
    0x00,                                       // []
    0xFF, 0x00, 0xFF,                           // A        . -
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF,               // S        . . .
    0x00,                                       // []
    0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,   // C        - . - .
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF,               // O        - - - 
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF,               // O        - - - 
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,   // L        . - . .
    0x00,                                       // []
    0xFF, 0x00, 0xFF,                           // A        . -
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF,               // S        . . . 
    0x00,                                       // []
    0xFF, 0x00, 0xFF, 0x00, 0xFF,               // R        . - .
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF,               // U        . . -
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF,               // D        - . .
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF,               // D        - . . 
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF,               // O        - - -
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,   // C        - . - .
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF,               // K        - . -
    0x00,                                       // []
    0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,   // H        . . . . 
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF,               // O        - - -
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF,               // U        . . -
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF,               // S        . . .
    0x00,
    0xFF,                                       // E        .
    0x00,                                       // []
    0xFF, 0x00, 0xFF,                           // I        . . 
    0x00,                                       // []
    0xFF, 0x00, 0xFF, 0x00, 0xFF,               // W        . - -
    0x00,
    0xFF, 0x00, 0xFF,                           // I        . .
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF,               // S        . . .
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF, 0x00, 0xFF,   // H        . . . .
    0x00,                                       // []
    0xFF, 0x00, 0xFF,                           // I        . .
    0x00,                                       // []
    0xFF, 0x00, 0xFF, 0x00, 0xFF,               // W        . - -
    0x00,
    0xFF,                                       // E        .
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF,               // R        . - .
    0x00,
    0xFF,                                       // E        .
    0x00,                                       // []
    0xFF, 0x00, 0xFF, 0x00, 0xFF,               // D        - . .
    0x00,
    0xFF,                                       // E        .
    0x00,
    0xFF, 0x00, 0xFF,                           // A        . -
    0x00,
    0xFF, 0x00, 0xFF, 0x00, 0xFF,               // D        - . .
    0x00                                        // EOM delay
};

const uint16_t ani_my_house_dels[ANI_MY_HOUSE_LEN] PROGMEM = {
    MS_SOM,                                     // SOM delay
    MS_D, MS_S, MS_D,                           // M        - -
    MS_CS,
    MS_D, MS_S, MS_d, MS_S, MS_D, MS_S, MS_D,   // Y        - . - -
    MS_WS,                                      // []
    MS_d, MS_S, MS_d, MS_S, MS_d, MS_S, MS_d,   // H        . . . .
    MS_CS,
    MS_D, MS_S, MS_D, MS_S, MS_D,               // O        - - -
    MS_CS,
    MS_d, MS_S, MS_d, MS_S, MS_D,               // U        . . -
    MS_CS,
    MS_d, MS_S, MS_d, MS_S, MS_d,               // S        . . .
    MS_CS,
    MS_d,                                       // E        .
    MS_WS,                                      // []
    MS_d, MS_S, MS_D, MS_S, MS_D,               // W        . - -
    MS_CS,
    MS_d, MS_S, MS_d,                           // I        . .
    MS_CS,
    MS_d, MS_S, MS_D, MS_S, MS_d, MS_S, MS_d,   // L        . - . .
    MS_CS,
    MS_d, MS_S, MS_D, MS_S, MS_d, MS_S, MS_d,   // L        . - . .
    MS_WS,                                      // []
    MS_D, MS_S, MS_d,                           // N        - .
    MS_CS,
    MS_d,                                       // E        .
    MS_CS,
    MS_d, MS_S, MS_d, MS_S, MS_d, MS_S, MS_D,   // V        . . . -
    MS_CS,
    MS_d,                                       // E        .
    MS_CS,
    MS_d, MS_S, MS_D, MS_S, MS_d,               // R        . - .
    MS_WS,                                      // []
    MS_D, MS_S, MS_d, MS_S, MS_d, MS_S, MS_d,   // B        - . . .
    MS_CS,
    MS_d,                                       // E        .
    MS_WS,                                      // []
    MS_d, MS_S, MS_D,                           // A        . -
    MS_CS,
    MS_d, MS_S, MS_d, MS_S, MS_d,               // S        . . .
    MS_WS,                                      // []
    MS_D, MS_S, MS_d, MS_S, MS_D, MS_S, MS_d,   // C        - . - .
    MS_CS,
    MS_D, MS_S, MS_D, MS_S, MS_D,               // O        - - -
    MS_CS,
    MS_D, MS_S, MS_D, MS_S, MS_D,               // O        - - -
    MS_CS,
    MS_d, MS_S, MS_D, MS_S, MS_d, MS_S, MS_d,   // L        . - . .
    MS_WS,                                      // []
    MS_d, MS_S, MS_D,                           // A        . -
    MS_CS,
    MS_d, MS_S, MS_d, MS_S, MS_d,               // S        . . .
    MS_WS,                                      // []
    MS_d, MS_S, MS_D, MS_S, MS_d,               // R        . - .
    MS_CS,
    MS_d, MS_S, MS_d, MS_S, MS_D,               // U        . . -
    MS_CS,
    MS_D, MS_S, MS_d, MS_S, MS_d,               // D        - . .
    MS_CS,
    MS_D, MS_S, MS_d, MS_S, MS_d,               // D        - . .
    MS_CS,
    MS_D, MS_S, MS_D, MS_S, MS_D,               // O        - - -
    MS_CS,
    MS_D, MS_S, MS_d, MS_S, MS_D, MS_S, MS_d,   // C        - . - .
    MS_CS,
    MS_D, MS_S, MS_d, MS_S, MS_D,               // K        - . -
    MS_WS,                                      // []
    MS_d, MS_S, MS_d, MS_S, MS_d, MS_S, MS_d,   // H        . . . .
    MS_CS,
    MS_D, MS_S, MS_D, MS_S, MS_D,               // O        - - -
    MS_CS,
    MS_d, MS_S, MS_d, MS_S, MS_D,               // U        . . -
    MS_CS,
    MS_d, MS_S, MS_d, MS_S, MS_d,               // S        . . .
    MS_CS,
    MS_d,                                       // E        .
    MS_WS,                                      // []
    MS_d, MS_S, MS_d,                           // I        . .
    MS_WS,                                      // []
    MS_d, MS_S, MS_D, MS_S, MS_D,               // W        . - -
    MS_CS,
    MS_d, MS_S, MS_d,                           // I        . .
    MS_CS,
    MS_d, MS_S, MS_d, MS_S, MS_d,               // S        . . .
    MS_CS,
    MS_d, MS_S, MS_d, MS_S, MS_d, MS_S, MS_d,   // H        . . . .
    MS_WS,                                      // []
    MS_d, MS_S, MS_d,                           // I        . .
    MS_WS,                                      // []
    MS_d, MS_S, MS_D, MS_S, MS_D,               // W        . - -
    MS_CS,
    MS_d,                                       // E        .
    MS_CS,
    MS_d, MS_S, MS_D, MS_S, MS_d,               // R        . - .
    MS_CS,
    MS_d,                                       // E        .
    MS_WS,                                      // []
    MS_D, MS_S, MS_d, MS_S, MS_d,               // D        - . .
    MS_CS,
    MS_d,                                       // E        .
    MS_CS,
    MS_d, MS_S, MS_D,                           // A        . -
    MS_CS,
    MS_D, MS_S, MS_d, MS_S, MS_d,               // D        - . .
    MS_EOM                                      // EOM delay
};

#endif // PAT_USE_RUDDOCK


// Experimental pattern
//      Note: This is exactly[TM] what[TM] you think it is

#ifdef EXECUTE

#define ANI_EXE_LEN         81

const uint8_t ani_exe_pats[ANI_EXE_LEN] PROGMEM = {
    /*
    330,        440, 330, 440, 523, 440,        523, 440, 523, 659, 523,
        659, 523, 659, 784, 392,        523, 392, 523, 659,
    
    330,        523, 392, 523, 659, 523,        659, 523, 659, 784, 659,
        784, 659, 784, 988, 494,        659, 494, 659, 784,
    
    330,        440, 330, 440, 523, 440,        523, 392, 523, 659, 523,
        659, 523, 659, 784, 659,        523, 392, 523, 659,
    
    392,        523, 392, 523, 659, 523,        659, 523, 659, 784, 659,
        784, 659, 784, 988, 494,        659, 494, 659, 740,
    0
    */
    82,         110, 82, 110, 130, 110,         130, 110, 130, 164, 130, 
        164, 130, 164, 196, 98,         130, 98, 130, 164, 
    82,         130, 98, 130, 164, 130,         164, 130, 164, 196, 164, 
        196, 164, 196, 247, 123,        164, 123, 164, 196, 
    82,         110, 82, 110, 130, 110,         130, 98, 130, 164, 130, 
        164, 130, 164, 196, 164,        130, 98, 130, 164, 
    98,         130, 98, 130, 164, 130,         164, 130, 164, 196, 164, 
        196, 164, 196, 247, 123,        164, 123, 164, 185,
    0
};

#define ANI_EXE_DEL_U       100         // Tempo units (ms)

const uint16_t ani_exe_dels[ANI_EXE_LEN] PROGMEM = {
    /*
    2,          2, 4, 2, 1, 1,          2, 4, 2, 1, 1,
        2, 4, 2, 1, 1,          2, 4, 2, 0.5,
    
    2,          2, 4, 2, 1, 1,          2, 4, 2, 1, 1,
        2, 4, 2, 1, 1,          2, 4, 2, 0.5,
    
    2,          2, 4, 2, 1, 1,          2, 4, 2, 1, 1,
        2, 4, 2, 1, 1,          2, 4, 2, 0.5,
    
    2,          2, 4, 2, 1, 1,          2, 4, 2, 1, 1,
        2, 4, 2, 1, 1,          2, 4, 2, 0.5,
    */
    4,          4, 8, 4, 2, 2,          4, 8, 4, 2, 2,
        4, 8, 4, 2, 2,          4, 8, 4, 1,
    
    4,          4, 8, 4, 2, 2,          4, 8, 4, 2, 2,
        4, 8, 4, 2, 2,          4, 8, 4, 1,
    
    4,          4, 8, 4, 2, 2,          4, 8, 4, 2, 2,
        4, 8, 4, 2, 2,          4, 8, 4, 1,
    
    4,          4, 8, 4, 2, 2,          4, 8, 4, 2, 2,
        4, 8, 4, 2, 2,          4, 8, 4, 1,
    32
};
    
#endif // EXECUTE


#endif // ANIMATIONS_H
