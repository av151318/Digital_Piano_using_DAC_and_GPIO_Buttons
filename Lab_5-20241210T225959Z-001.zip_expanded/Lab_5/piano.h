/*
 * piano.h
 *
 *  Created on: Dec 5, 2024
 *      Author: Daniel Vasquez
 *
    To use piano.h:

    initialize with button_Init()
    then call piano_input() to retrieve data from pins that read data input

    validate proper practice and include piano.h in your source file you intend to deploy
 *
 */

#ifndef PIANO_H_
#define PIANO_H_
// Mask for Pins: PA2 (0x04), PA3 (0x08), PA4 (0x10)
#define INPUT 0x1C
void button_Init();
uint8_t piano_Input();
#endif /* PIANO_H_ */
