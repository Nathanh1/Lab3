// ******************************************************************************************* //
// 
// File:        lcd.c
// Due Date:    3/25/2016
// Team:        203
// Description: lcd.c file for Lab 3 Part 2 
// ******************************************************************************************* //


#include <xc.h>
#include "lcd.h"
#include "timer.h"

#define PIN_RS   TRISCbits.TRISC4   //PIN21 J10 LCD 4
#define PIN_E    TRISCbits.TRISC2   //PIN19 J10 LCD 6
#define PIN_RW   TRISCbits.TRISC14  //PIN17 J10 LCD 5

#define RS    LATCbits.LATC4  //PIN21 J10 LCD 4
#define E     LATCbits.LATC2  //PIN19 J10 LCD 6
#define RW    LATCbits.LATC14 //PIN17 J10 LCD 5

#define PIN_D4   TRISEbits.TRISE7 //PIN5  J10 LCD 11
#define PIN_D5   TRISEbits.TRISE5 //PIN7  J10 LCD 12
#define PIN_D6   TRISEbits.TRISE3 //PIN9  J10 LCD 13
#define PIN_D7   TRISEbits.TRISE1 //PIN11 J10 LCD 14

#define D4    LATEbits.LATE7 //PIN5  J10 LCD 11
#define D5    LATEbits.LATE5 //PIN7  J10 LCD 12
#define D6    LATEbits.LATE3 //PIN9  J10 LCD 13 
#define D7    LATEbits.LATE1 //PIN11 J10 LCD 14

#define TURNON 1
#define TURNOFF 0

#define LOWERBITS 0
#define UPPERBITS 1

#define DELAYAFTER 40

#define OUTPUT 0
#define INPUT 1

#define ENDOFSTRING '\0'

#define ROW2 2

#define SECONDLINE 0x80+0x40
#define FIRSTLINE  0x80

#define COMMANDZERO 0

#define DELAYTEST 1
#define STRINGTEST 0



void writeFourBits(unsigned char word, unsigned int commandType, unsigned int delayAfter, unsigned int lower)
{
   
    word = (!lower) ? word>>4 : word;
    
    RS = (commandType) ? TURNON : TURNOFF;   
    
    delayUs(1); //DELAY 1US
    
    //BIT SHIFT TO ASSIGN WORD TO PIN
    
    D7 = (word>>3) & 1; //SHIFT THREE AND ASSIGN
    D6 = (word>>2) & 1; //SHIFT TWO AND ASSIGN
    D5 = (word>>1) & 1; //SHIFT ONE AND ASSIGN
    D4 = (word>>0) & 1; //SHIFT ZERO AND ASSIGN
    
    E = TURNON;
    
    delayUs(1); //DELAY 1US
    
    E = TURNOFF; 
    
    delayUs(delayAfter);
}

void writeLCD(unsigned char word, unsigned int commandType, unsigned int delayAfter)
{
    writeFourBits(word, commandType, delayAfter,LOWERBITS);
    
    writeFourBits(word, commandType, delayAfter,UPPERBITS); 
    
}

void printCharLCD(char c) 
{
    
    writeLCD(c,TURNON, DELAYAFTER);
    
}

void initLCD(void) 
{
    int j=0;
    
    PIN_RS = OUTPUT;
    PIN_E  = OUTPUT; 
    PIN_RW = OUTPUT; 
    
    PIN_D7 = OUTPUT;
    PIN_D6 = OUTPUT;
    PIN_D5 = OUTPUT; 
    PIN_D4 = OUTPUT;
    
    RW = OUTPUT;

    for(j=0;j<=2;j++)
        {
            
            delayUs(5000);//15ms Delay
        
        }
    
    writeFourBits(0b000011, COMMANDZERO, DELAYAFTER, UPPERBITS);
    
    delayUs(4100);//4.1ms Delay
    
    writeFourBits(0b000011, COMMANDZERO, DELAYAFTER, UPPERBITS);
    
    delayUs(100);//100Us Delay
    
    writeFourBits(0b000011, COMMANDZERO, DELAYAFTER, UPPERBITS);
    
    writeFourBits(0b000010, COMMANDZERO, DELAYAFTER, UPPERBITS); 
    
    writeLCD(0b101011, COMMANDZERO, DELAYAFTER);
    
    writeLCD(0b001000, COMMANDZERO, DELAYAFTER); 
    
    clearLCD();
    
    writeLCD(0b000110, COMMANDZERO, DELAYAFTER);
    
    writeLCD(0b001100, COMMANDZERO, DELAYAFTER);
}

void printStringLCD(const char* s) 
{
     while(*s != ENDOFSTRING)
        {
            printCharLCD(*s);
        
            s=s+1;        
        }
}

void clearLCD()
{
    writeLCD(0b000001, COMMANDZERO, 41*DELAYAFTER);
}

void moveCursorLCD(unsigned char x, unsigned char y)
{
    if (y == ROW2)
    {
        writeLCD(x+SECONDLINE,COMMANDZERO, DELAYAFTER);
    }
    else
    {
        writeLCD(x+FIRSTLINE,COMMANDZERO, DELAYAFTER);
    }
}

void testLCD()
{
    initLCD();
    
    int i = 0;
    
    printCharLCD('c');
    
    for(i = 0; i < 1000; i++) delayUs(1000);
    
    clearLCD();
    
    printStringLCD("Hello!");
    
    moveCursorLCD(1, 2);
    
    for(i = 0; i < 1000; i++) delayUs(1000);
    
    printStringLCD("Hello!");
    
    for(i = 0; i < 1000; i++) delayUs(1000);
}
