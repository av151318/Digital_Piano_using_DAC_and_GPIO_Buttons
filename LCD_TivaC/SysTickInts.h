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


// mailbox functions
void heartbeat_Init();
uint32_t SysTick_Mailbox();
uint8_t Mailbox_Flag(void);

#endif
