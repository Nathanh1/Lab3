// ******************************************************************************************* //
// 
// File:        timer.c
// Due Date:    3/25/2016
// Team:        203
// Description: timer.c file for Lab 3 Part 2 
// ******************************************************************************************* //


#include <xc.h>
#include "timer.h"

#define TIMER1FLAG IFS0bits.T1IF
#define CN T1CONbits.ON

#define UP 1
#define DOWN 0

#define ENABLE 1
#define DISABLE 0

#define TIMER1 TMR1

#define CLEAR 0x0000

#define PRVAL (delay % (256*2))*8 - 1

#define InitPRVAL 4095

#define DELAY delay/(256*2)

#define PERIODREGISTER PR1

void delayUs(unsigned int delay)
{
    int j=0;
    
    TIMER1FLAG = DOWN; //PUT THE FLAG DOWN
    
    TIMER1 = CLEAR; //CLEAR THE TIMER
    
    CN = ENABLE; //ENABLE CHANGE NOTIFICATION
    
    PERIODREGISTER = InitPRVAL;
    /*
    for(j=0; j < DELAY; j++)
    {
        
        while(TIMER1FLAG = DOWN);//WHILE FLAG IS DOWN
        
        TIMER1FLAG = DOWN;//FORCE FLAG DOWN
        
    }*/
    
    while(TIMER1FLAG == DOWN);//WHILE FLAG IS DOWN
        
    TIMER1FLAG = DOWN;//FORCE FLAG DOWN
    
    
    PERIODREGISTER = PRVAL; //SET TIMER1 PERIOD REGISTER TO DELAY CALCULATION
    /*
    while(TIMER1FLAG==DOWN); //BREAK IF TIMER 2 FLAG GOES UP
    
    TIMER1FLAG = DOWN; //PUT THE FLAG DOWN
    */
    CN = DISABLE; //DISABLE CHANGE NOTIFICATION
}