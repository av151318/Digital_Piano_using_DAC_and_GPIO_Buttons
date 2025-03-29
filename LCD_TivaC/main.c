#include <stdint.h>
#include "LCD.h"
#include "TimerA0.h"
#include "PLL.h"

#include "tm4c123gh6pm.h"
#include "ADCSWTrigger.h"
#include "SysTickInts.h"


void main()
{
    //initialize timer
    // set system clock to 80 MHz
    PLL_Init(Bus80MHz);
    // (80 MHz / 10 Hz) = 8,000,000
    //this will create the 0.1s interrupt period
    SysTick_Init(8000000);

    //initialize LCD
    LCD_Init();
    // initialize ADC sample
    ADC0_InitSWTriggerSeq3_Ch8();
    //init heartbeat LED
    heartbeat_Init();

    char NOM[] = "Temp Sensor(F,C)";
    //output string to show feature
    LCD_OutString(NOM);
    // Move cursor to the 2nd line
    LCD_OutCmd(0xC0);

    //initialize data vars
    uint16_t adcSample;
    uint32_t temperature;

    while(1){
        //check for mailbox flag
        if (Mailbox_Flag()){

        // read mailbox data, clears mailbox flag
        adcSample = SysTick_Mailbox();

        // Convert ADC sample to temperature
        temperature = OnDemandTempF(adcSample);

        // Display the temperature in F on the LCD
        LCD_OutUFix(temperature);

        // Display the temperature in C on the LCD
        LCD_OutChar(',');
        LCD_OutUFix(OnDemandTempC(adcSample)*10);

        // Move cursor to the 2nd line (resets cursor to overwrite with next value)
        LCD_OutCmd(0xC0);

        }
    };

}
