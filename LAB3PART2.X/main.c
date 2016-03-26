// ******************************************************************************************* //
// 
// File:        main.c
// Due Date:    3/25/2016
// Team:        203
// Description: Main of Lab 3 Part 2
// ******************************************************************************************* //


#include <xc.h>
#include <sys/attribs.h>
#include "config.h"

#define PINTypeEN1 TRISAbits.TRISA7//J11 3
#define PINTypeIN1 TRISDbits.TRISD2//J11 17
#define PINTypeIN2 TRISDbits.TRISD3//J11 18

#define PINTypeSW TRISDbits.TRISD7//J11 3

#define PINTypeEN2 TRISGbits.TRISG13//J11 4
#define PINTypeIN4 TRISDbits.TRISD1//J11 20
#define PINTypeIN3 TRISDbits.TRISD0//J11 19

#define INPUT1  LATDbits.LATD3//WRITE J11 3
#define INPUT2  LATDbits.LATD2//WRITE J11 17
#define ENABLE1 LATAbits.LATA7//WRITE J11 18

#define INPUT4  LATDbits.LATD1//WRITE J11 20
#define INPUT3  LATDbits.LATD0//WRITE J11 19å
#define ENABLE2 LATGbits.LATG13//WRITE J11 4

#define BUTTON PORTDbits.RD7//WRITE J11 20

//#define ODCINPUT1 RPD2Rbits.RPD2R //OPEN DRAIN COLLECTOR
//#define ODCINPUT2 RPD3Rbits.RPD3R //OPEN DRAIN COLLECTOR

#define ODCINPUT1 ODCDbits.ODCD2 //OPEN DRAIN COLLECTOR
#define ODCINPUT2 ODCDbits.ODCD3 //OPEN DRAIN COLLECTOR

#define INPUT 1
#define OUTPUT 0

#define ON 1
#define OFF 0

#define PRESSED 1
#define RELEASED 0

volatile int state;

typedef enum stateTypeEnum{
    FORWARD,FIDLE,REVERSE,RIDLE,
    FWAIT , FIWAIT, RWAIT, RIWAIT
} stateType;

int main(void)
{
    
    void initADC();
    void initPWM();
    
    
    stateType state=FORWARD;
    
    int i;
    PINTypeEN1 = OUTPUT;
    PINTypeIN1 = OUTPUT;
    PINTypeIN2 = OUTPUT;
    
    PINTypeEN2 = OUTPUT;
    PINTypeIN4 = OUTPUT;
    PINTypeIN3 = OUTPUT;
    
    //ODCINPUT1 = OFF;
    //ODCINPUT2 = OFF;
    
    ENABLE1 = ON;
    ENABLE2 = ON;
    
    PINTypeSW =INPUT;
 
    initADC();
    initLCD();
    
    clearLCD();
    int val;
    char cval;
    
    while(1)
    {

        switch(state)
        {
            case FORWARD:
                    cval= '0'; 
                    AD1CON2bits.BUFM = 0;
                    val = ADC1BUF0;
                    val=val*4/1023;
                    cval=val+cval;
                        
                                if(cval== '4') 
                                {
                                    cval='0';
                                }
                                else if(cval=='3')
                                {
                                    cval='1';
                                }
                                else if(cval=='2')
                                {
                                    cval='2';
                                }
                                else if(cval=='1')
                                {
                                   cval='3'; 
                                }
                                else if(cval=='0')
                                {
                                   cval='4'; 
                                }

                        if(cval=='4')
                        {
                            INPUT1 = ON;
                            INPUT2 = OFF;

                            INPUT3 = OFF;
                            INPUT4 = OFF;

                            for(i=0;i<9;i++)
                            {
                                delayUs(100);
                            }

                            INPUT1 = OFF;
                            INPUT2 = OFF;

                            INPUT3 = OFF;
                            INPUT4 = OFF;

                            for(i=0;i<1;i++)
                            {
                                delayUs(100);
                            }


                        }
                        else if(cval=='2')
                        {
                            INPUT1 = ON;
                            INPUT2 = OFF;

                            INPUT3 = ON;
                            INPUT4 = OFF;

                            for(i=0;i<9;i++)
                            {
                                delayUs(100);
                            }

                            INPUT1 = OFF;
                            INPUT2 = OFF;

                            INPUT3 = OFF;
                            INPUT4 = OFF;

                            for(i=0;i<1;i++)
                            {
                                delayUs(100);
                            }


                        }
                        else if(cval=='0')
                        {
                            INPUT1 = OFF;
                            INPUT2 = OFF;

                            INPUT3 = ON;
                            INPUT4 = OFF;

                            for(i=0;i<9;i++)
                            {
                                delayUs(100);
                            }

                            INPUT1 = OFF;
                            INPUT2 = OFF;

                            INPUT3 = OFF;
                            INPUT4 = OFF;

                            for(i=0;i<1;i++)
                            {
                                delayUs(100);
                            }
                        }
                    
                    printCharLCD(cval);
                    moveCursorLCD(0,0);
                    
                    if(BUTTON == PRESSED)
                    {
                        state=FWAIT;
                    }
                    
                break;
                
            case FWAIT:
                
                if(BUTTON == RELEASED)
                {
                    state=FIDLE;
                }
                
                break;
                
            case FIDLE:
                    INPUT1 = OFF;
                    INPUT2 = OFF;

                    INPUT3 = OFF;
                    INPUT4 = OFF;
                    if(BUTTON == PRESSED)
                    {
                        state=FIWAIT;
                    }
                break;
            case FIWAIT:
                if(BUTTON == RELEASED)
                    {
                        state=FORWARD;
                    }
                break;
            case REVERSE:

                break;

            case RIDLE:
                    INPUT1 = OFF;
                    INPUT2 = OFF;

                    INPUT3 = OFF;
                    INPUT4 = OFF;
                break;

        }
        
    }
    
    return 0;
}