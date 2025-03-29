#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "PLL.h"
#include "DAC.h"

void main(void) {
  uint8_t Data = 0;  // 0 to 15 DAC output

  PLL_Init(Bus80MHz);  // set system clock to 80 MHz

  DAC_Init();

  while(1) {
    DAC_Out(Data);
    Data = 0x0F & (Data+1);  // 0, 1, 2, ..., 14, 15, 0, 1, 2, ...
  }
}

