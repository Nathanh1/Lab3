// ******************************************************************************************* //
// 
// File:        lcd.h
// Due Date:    3/25/2016
// Team:        203
// Description: lcd.h header file for Lab 3 Part 2 
// ******************************************************************************************* //



void writeLCD(unsigned char word, unsigned int commandType, unsigned int delay);
void writeFourBits(unsigned char word, unsigned int commandType, unsigned int delayAfter, unsigned int lower);
void initLCD(void);
void clearLCD(void);
void moveCursorLCD(unsigned char x, unsigned char y);
void printCharLCD(char c);
void printStringLCD(const char* s);
void testLCD();