/*
     SysTickInts.h
 *
 *  Created on: Dec 5, 2024
 *      Author: Daniel Vasquez
 *
     To use SysTickInts.h:
     validate proper practice and include SysTickInts.h in your source file you intend to deploy

     initialize with SysTick_Init()
     SysTick_Handler() will run automatically as a background thread
 *
 */

#ifndef __SYSTICKINTS_H__
#define __SYSTICKINTS_H__

// **************SysTick_Init*********************
// Initialize SysTick periodic interrupts
// Input: interrupt period
//        Units of period are 12.5ns (assuming 80 MHz clock)
//        Maximum is 2^24-1
//        Minimum is determined by length of ISR
// Output: none
void SysTick_Init(uint32_t period);
void SysTick_Handler();
#endif
