/**
 * appdef.h
 * TinyBlink application definitions
 *
 * Description:
 *      This file contains application specific definitions for TinyBlink,
 *      such as macros for which middleware drivers and animations to use 
 *
 * Author:          Ray Sun
 * Last Updated:    09/06/2019
 */


#ifndef APPDEF_H
#define APPDEF_H

// ############################## DEFINES ######################################

// Software timers
// ----- Uncomment the following two lines to use software timers -----
// ----- Define the number of soft timers used in your application below -----
#define SFT_USE
#define SFT_N           2           // Number of soft timers in application   

// Cycle handlers
// ----- Uncomment as desired to use specific cycle effect handlers -----
// Please note: Direction is with respect to shifts of pattern data, so a right
// shift is counterclockwise on the keychain physically
#define CYC_USE_ONEHOT_R             // One-hot cycle, right shift
#define CYC_USE_ONEHOT_L             // One-hot cycle, left shift
#define CYC_USE_JOHNSON_R            // Johnson counter, right shift
#define CYC_USE_JOHNSON_L            // Johnson counter, left shift
#define CYC_USE_HALFJOHN_R           // 4 LEDs on, right rotate
#define CYC_USE_HALFJOHN_L           // 4 LEDs on, left rotate
#define CYC_USE_FIB_LFSR             // Fibonacci LFSR
#define CYC_USE_GAL_LFSR             // Galois LFSR

// Animation handlers
// ----- Uncomment the below to use the animation driver -----
#define ANI_USE

// Ruddock House slogan
// ----- Uncomment to spread Ruddock industrialism around the globe -----
// If you are not a Caltech undergraduate, this is not particularly useful
#define PAT_USE_RUDDOCK

#endif // APPDEF_H
