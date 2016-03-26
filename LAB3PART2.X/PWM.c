// ******************************************************************************************* //
// 
// File:        pwm.c
// Due Date:    3/25/2016
// Team:        203
// Description: pwm.c file for Lab 3 Part 2 
// ******************************************************************************************* //



#include <xc.h>
#include "PWM.h"
 

void initPWM()
{  
    
    RPD1Rbits.RPD1R= 12;            //Maps to the pin RD1   Pin 20 on J11
    TRISDbits.TRISD1 = 0;           //pin D1
    T2CONbits.ON = 1;               //Turn Timer 2 on
    PR2 = 10000;                    //One microsecond period
    TMR2 = 0;
    T2CONbits.TCKPS = 0;            //One microsecond  //prescaler is zero       
    T2CONbits.TON = 1;              //Turning it on  
    OC1CONbits.OCTSEL = 0;          //Uses Timer 2
    OC1CONbits.OCM = 6;             //PWM Mode fault pin disable 
    
    OC1RS = 2500;                    //OC1RS / PR2  =  2500/10000 = 25% duty cycle     
    OC1R = 0;                        //Reads 
    
    OC1CONbits.ON = 1;              //Output compare module //ON
}


