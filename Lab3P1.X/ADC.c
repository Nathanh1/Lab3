



#include <xc.h>
#include "ADC.h"
 
 //ssrc

void initADC()
{
    TRISBbits.TRISB0 = 0;       //This is AN0
    AD1CON1bits.FORM = 0;       //Integer 16-bit  for fraction 
    AD1CON1bits.SSRC = 7;       //Auto sampling 
    AD1CON1bits.ASAM = 1;       //Auto sampling 
    AD1CON2bits.VCFG = 0;       //Using Vdd and Vss as reference 
    AD1CON2bits.CSCNA = 0;      //Channel scanning disable
    AD1CON2bits.SMPI = 15;      //Interrupts at the completion of conversion for each 15 sample/convert sequence
    AD1CON2bits.ALTS = 0;       //Always use one MUX A
    AD1CON3bits.ADRC = 0;       //Clock derived from Peripheral Bus Clock (PBCLK)     
    AD1CON3bits.SAMC = 3;       //Auto sampling time bits 
    AD1CON3bits.ADCS = 8;       //Like a prescaler
    AD1CHSbits.CH0NA = 0;       //Want the negative reference as low
    AD1CHSbits.CH0SA = 0;       //Scan AN0
    AD1CON1bits.ADON = 1;       //Turn on the ADC    Turn on Last
                                //Channel 0 positive input is AN0  //Find pin AN0 
                                //AN0 is pin 34 on J11 
                               
    
    
    
}
