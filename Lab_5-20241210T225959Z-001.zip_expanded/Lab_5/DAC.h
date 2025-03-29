/*
 * DAC.h
 *
 *  Created on: Dec 5, 2024
 *      Author: Daniel Vasquez
 *
     To use DAC.h:
     validate proper practice and include DAC.h in your source file you intend to deploy
     ensure proper 4 pin with resistor network to ensure 16 bit precision and accuracy
     be sure to validate your hardware setup shows full precision of all expected 16 bits
     starting from zero output should step 0.2V up to 3.3V as expected from Tiva C board spec of pins



     initialize with DAC_Init()
     use DAC_Out() to output data to the pins

     Common issues include:
     5-10% voltage error range of voltage reading
     some pins may output high at 2V which is not enough since pins need to perform up to 3.3V
     recommend checking board schematic and trying different pins when this issue occurs

 *
 */
#ifndef DAC_H_
#define DAC_H_
void DAC_Init();
void DAC_Out(uint8_t data);
#endif /* DAC_H_ */
