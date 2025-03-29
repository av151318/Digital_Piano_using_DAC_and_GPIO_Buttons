#ifndef __LCD_H__
#define __LCD_H__

// Clear the LCD
// Inputs: none
// Outputs: none
void LCD_Clear();

// Initialize LCD
// Inputs: none
// Outputs: none
void LCD_Init(void);

// Output a character to the LCD
// Inputs: letter is ASCII character, 0 to 0x7F
// Outputs: none
void LCD_OutChar(char letter);

// Output a command to the LCD
// Inputs: 8-bit command
// Outputs: none
void LCD_OutCmd(unsigned char command);

//------------LCD_OutString------------
// Output String (NULL termination)
// Input: pointer to a NULL-terminated string to be transferred
// Output: none
void LCD_OutString(char *ptr);

//-----------------------LCD_OutUDec-----------------------
// Output a 32-bit number in unsigned decimal format
// Input: 32-bit number to be transferred
// Output: none
// Variable format 1-10 digits with no space before or after
void LCD_OutUDec(uint32_t n);



// -----------------------LCD_OutUFix----------------------
// Output characters to LCD display in fixed-point format
// unsigned decimal, resolution 0.001, range 0.000 to 9.999
// Inputs:  an unsigned 32-bit number
// Outputs: none
void LCD_OutUFix(uint32_t number);

#endif
