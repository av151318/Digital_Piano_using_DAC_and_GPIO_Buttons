/*
 * piano.c
 *
 *  Created on: Dec 5, 2024
 *      Author: Daniel Vasquez
 */
#include <stdint.h>
#include "piano.h"
#include "tm4c123gh6pm.h"

void button_Init() {
    // Here we use code from previous GPIO init rituals and adapt accordingly
    // This code uses GPIO Port A Pins 2-4

    // 1) Activate clock for Port A
    // Assuming 0x01 for Port A
    SYSCTL_RCGCGPIO_R |= 0x01;
    while ((SYSCTL_PRGPIO_R & 0x01) == 0) {};
    // 2) Unlock the lock register for Port A
    GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY;
    // Enable commit for PA2, PA3, and PA4
    GPIO_PORTA_CR_R |= INPUT;
    // 3) Disable analog functionality
    GPIO_PORTA_AMSEL_R &= ~INPUT;
    // 4) Configure as GPIO
    // PA2, PA3, and PA4
    GPIO_PORTA_PCTL_R &= ~0x000FFF00;
    // 5) Set direction register
    // PA2, PA3, and PA4 input
    GPIO_PORTA_DIR_R &= ~INPUT;
    // 6) Regular port function
    GPIO_PORTA_AFSEL_R &= ~INPUT;
    // 7) Enable PA2, PA3, PA4 digital pins
    GPIO_PORTA_DEN_R |= INPUT;

}

// Return the logical key code for the pattern of keys pressed
uint8_t Piano_In() {
    // Read the state of PA2, PA3, and PA4 and return the 3-bit value
    return ( (GPIO_PORTA_DATA_R & INPUT) >> 2) ;
}
