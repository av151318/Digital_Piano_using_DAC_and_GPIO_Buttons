#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "PLL.h"
#include "DAC.h"
#include "piano.h"
#include "soundDriver.h"

void main(void) {
   // set system clock to 80 MHz
  PLL_Init(Bus80MHz);
  //initialize buttons for piano
  button_Init();
  //initialize soundDriver
  Sound_Init();

  while(1) {
    //listen for piano buttons
    uint8_t key = Piano_In();
    //map keys to their note using case handling
    //call sound driver to play the note
    //to change notes played, change mapping to other notes defined in soundDriver.h
    if (key & 0x01) { Sound_Play(A); }
    else if (key & 0x02) { Sound_Play(E); }
    else if (key & 0x04) { Sound_Play(F); }
    else { Sound_Play(OFF); }

  }
}


