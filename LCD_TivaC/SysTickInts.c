#include <stdint.h>
#include "ADCSWTrigger.h"
#include "tm4c123gh6pm.h"

void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode

volatile float ADCvalue;
volatile uint8_t mailboxFlag = 0;

// **************SysTick_Init*********************
// Initialize SysTick periodic interrupts
// Input: interrupt period
//        Units of period are 12.5ns (assuming 80 MHz clock)
//        Maximum is 2^24-1
//        Minimum is determined by length of ISR
// Output: none
volatile uint32_t Counts;
uint32_t wait_per;

void SysTick_Init(uint32_t period) {
	long sr = StartCritical();
	wait_per = period;

	//ADC0_InitSWTriggerSeq3_Ch8();        // initialize ADC sample PE5/A8

	Counts = 0;

	NVIC_ST_CTRL_R = 0;                  // disable SysTick during setup
	NVIC_ST_RELOAD_R = period - 1;       // maximum reload value
	NVIC_ST_CURRENT_R = 0;               // any write to current clears it
	NVIC_SYS_PRI3_R = (NVIC_SYS_PRI3_R&0x00FFFFFF)|0x40000000;	// priority 2
	NVIC_ST_CTRL_R = 0x00000007;         // enable SysTick with interrupts

	EnableInterrupts();

	EndCritical(sr);
}

void heartbeat_Init(){
    //enable port F for heartbeat LED
    // 1)
    SYSCTL_RCGC2_R  |= 0x20;
    // 2) Unlock the lock register for Port F for part 2
    GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY; // Unlock GPIO Port F Commit Register
    GPIO_PORTF_CR_R = 0xFF; // Enable commit for Port F
    // 3) Disable analog functionality
    GPIO_PORTF_AMSEL_R = 0x00; // Disable analog functionality
    // 5) direction of register
    GPIO_PORTF_PCTL_R = 0x00000000; // Configure Port F as GPIO
    GPIO_PORTF_DIR_R |= 0x0E;  // Set PF3-1 as output
    // 6) port function
    GPIO_PORTF_AFSEL_R = 0x00; // Disable alternate function
    // 7) enable pins
    GPIO_PORTF_DEN_R = 0xFF; // Enable digital I/O on Port F
}

void SysTick_Handler() {
    GPIO_PORTF_DATA_R ^= 0x08; // Toggle heartbeat LED ON (PF1)
	ADCvalue = ADC0_InSeq3();  // sample the ADC and save to mailbox
	mailboxFlag = 1;           // set the mailbox flag, new data is available
	GPIO_PORTF_DATA_R ^= 0x08; // Toggle heartbeat LED OFF (PF1)
}

uint16_t SysTick_Mailbox() {
	//returns data in mailbox, clears mailbox flag
    mailboxFlag = 0;
	//GPIO_PORTF_DATA_R ^= 0x08; // Toggle heartbeat LED OFF (PF1)
	return ADCvalue;
}

uint8_t Mailbox_Flag(void) { return mailboxFlag; }
