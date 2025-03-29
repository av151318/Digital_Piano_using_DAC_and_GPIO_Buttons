/*
 * soundDriver.c
 *
 *  Created on: Dec 5, 2024
 *      Author: Daniel Vasquez
 */
#include <stdint.h>
#include "soundDriver.h"
#include "DAC.h"
#include "tm4c123gh6pm.h"

//sine wave array we use for our piano
const uint8_t sineWave[32]= {8,9,11,12,13,14,14,15,15,15,14,14,13,12,11,9,8,7,5,4,3,2,2,1,1,1,2,2,3,4,5,7};

// Initialize the sound driver
void Sound_Init(void) {
    // Initialize SysTick timer
    SysTick_Init(80000000);
    //initialize DAC
    DAC_Init();
}

// Play a note
// this maps button press to proper frequency to traverse array later in ISR
void Sound_Play(unsigned int key) {

    if (key == OFF) {
        // Stop the sound
        NVIC_ST_RELOAD_R = 0;}
    else {
        // Set reload value for the note frequency by performing magic calculation
        // This is magic stuff.
        // I love engineering and the adaptability to create musical tone that this offers.
        // Calculate the reload value for the note frequency
        NVIC_ST_RELOAD_R = (80000000 / key) / 32;
    }
}
