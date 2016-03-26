////QA Tests
//  
//#include <stdio.h>
//#include <stdlib.h>
//#include <proc/p32mx470f512l.h>
//#include "config.h"
//#include "timer.h"
//
// 
//int main(void)
//{
//    int i = 0;
//    int val = 0;
//    initADC();
//    initPWM();
//    LATDbits.LATD1 = 0; // INPUT 4
//  
//    while(1)
//    {
//	//Forward
//        AD1CHSbits.CH0SA = 0;       //Scan AN0
//        AD1CHSbits.CH0SA = 2;       //Scan AN2
//        
//        //enable an open-drain collector
//        ODCBbits.ODCB1 = 1;         
//        ODCBbits.ODCB3 = 1;
//         
//        LATBbits.LATB1 = 0;
//        LATBbits.LATB3 = 0;
// 
//		for(i=0;i<9;i++)	{ // delay between motor moving forwards and backwards
//			delayUs(100);
//		}
//    
//		//Backward
// 
//        AD1CHSbits.CH0SA = 1;       //Scan AN1
//        AD1CHSbits.CH0SA = 3;       //Scan AN3
//        
//        //enables an open-drain collector
//        ODCBbits.ODCB0 = 1;
//        ODCBbits.ODCB2 = 1;
//         
//        LATBbits.LATB0 = 0;
//        LATBbits.LATB2 = 0;
//        
//   
//    return 0;
//}
//
//void initPWM()
//{  
//    
//    RPD1Rbits.RPD1R= 12;            //Maps to the pin RD1   Pin 20 on J11
//    TRISDbits.TRISD1 = 0;           //pin D1
//    T2CONbits.ON = 1;               //Turn Timer 2 on
//    PR2 = 10000;                    //One microsecond period
//    TMR2 = 0;
//    T2CONbits.TCKPS = 0;            //One microsecond  //prescaler is zero       
//    T2CONbits.TON = 1;              //Turning it on  
//    OC1CONbits.OCTSEL = 0;          //Uses Timer 2
//    OC1CONbits.OCM = 6;             //PWM Mode fault pin disable 
//    
//    OC1RS = 2500;                    //OC1RS / PR2  =  2500/10000 = 25% duty cycle
//	//OC1RS = 5000;                    //OC1RS / PR2  =  2500/10000 = 50% duty cycle
//	//OC1RS = 7500;                    //OC1RS / PR2  =  2500/10000 = 75% duty cycle
//	//OC1RS = 9900;                    //OC1RS / PR2  =  2500/10000 = 99% duty cycle
//    OC1R = 0;                        //Reads 
//    
//    OC1CONbits.ON = 1;              //Output compare module //ON
//}
//
// 
// //ssrc
//
//void initADC()
//{
//    TRISBbits.TRISB0 = 0;       //This is AN0
//    AD1CON1bits.FORM = 0;       //Integer 16-bit  for fraction 
//    AD1CON1bits.SSRC = 7;       //Auto sampling 
//    AD1CON1bits.ASAM = 1;       //Auto sampling 
//    AD1CON2bits.VCFG = 0;       //Using Vdd and Vss as reference 
//    AD1CON2bits.CSCNA = 0;      //Channel scanning disable
//    AD1CON2bits.SMPI = 15;      //Interrupts at the completion of conversion for each 15 sample/convert sequence
//    AD1CON2bits.ALTS = 0;       //Always use one MUX A
//    AD1CON3bits.ADRC = 0;       //Clock derived from Peripheral Bus Clock (PBCLK)     
//    AD1CON3bits.SAMC = 3;       //Auto sampling time bits 
//    AD1CON3bits.ADCS = 8;       //Like a prescaler
//    AD1CHSbits.CH0NA = 0;       //Want the negative reference as low
//    AD1CHSbits.CH0SA = 0;       //Scan AN0
//    AD1CON1bits.ADON = 1;       //Turn on the ADC    Turn on Last
//                                //Channel 0 positive input is AN0  //Find pin AN0 
//                                //AN0 is pin 34 on J11 
//}
