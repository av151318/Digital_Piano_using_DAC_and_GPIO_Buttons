/*
 * DAC.c
 *
 *  Created on: Dec 5, 2024
 *      Author: Daniel Vasquez
 */

#include <stdint.h>
#include "DAC.h"
#include "tm4c123gh6pm.h"

// Initializes the DAC
void DAC_Init(void) {
    // Enable clock for Port B
    SYSCTL_RCGCGPIO_R |= 0x02;
    while ((SYSCTL_PRGPIO_R & 0x02) == 0) {};

    // Set PB0-PB3 as output
    GPIO_PORTB_DIR_R |= 0x0F;
    GPIO_PORTB_DEN_R |= 0x0F;
}

// Sends a new data value to the DAC
void DAC_Out(uint8_t data) {
    GPIO_PORTB_DATA_R = data;
}
