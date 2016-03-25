/* 
 * File:   main.c
 * Author: Nathan
 * 
 * 
 */
  
#include <stdio.h>
#include <stdlib.h>
#include <proc/p32mx470f512l.h>
#include "config.h"
#include "ADC.h"
#include "PWM.h"


//for part 2 
//pwm to adc
//OC1RS = ADCBUF0;





int main(void)
{
    int i = 0;
    int val = 0;
    initADC();
    initPWM();
    
  
    while(1)
    {
        val = ADC1BUF0;
        
        for(i = 0; i < (1000*val)/1023; i++)
        {
            LATDbits.LATD1 = 1;
        }
        for(i = 0; i < (int) (1000*(1023 - val))/1023; i++)
        {
            LATDbits.LATD1 = 0;
        }
         
        
        
    }
   
    return 0;
}

