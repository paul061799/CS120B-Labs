/*	Author: pnguy086
 *  Partner(s) Name:
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
 #include <avr/io.h>
 #ifdef _SIMULATE_
 #include "simAVRHeader.h"
 #endif

 int main(void) {
   DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
   DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
   DDRC = 0x00; PORTC = 0xFF; // Configure port C's 8 pins as inputs
 	 DDRD= 0xFF; PORTD = 0x00; // Configure port D's 8 pins as outputs, initialize to 0s
 	 //unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
 	 unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
   unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
   unsigned char tmpC = 0x00; // Temporary variable to hold the value of C
   unsigned char tmpD = 0x00;
   unsigned long totalWeight = 0x00;
   unsigned short diffAC = 0x00;
   while(1) {
 		   // 1) Read input
 		   tmpA = PINA;
       tmpB = PINB;
       tmpC = PINC;
 		   // 2) Perform computation
 		   //calculate weight & difference between A and C
       totalWeight = tmpA + tmpB + tmpC;
       if(tmpA > tmpC){
         diffAC = tmpA - tmpC;
       } else {
         diffAC = tmpC - tmpA;
       }
 	      // 3) Write output
        //PD0
        if(totalWeight > 140) {
          tmpD = tmpD | 0x01;
        }
        //PD1
        if(diffAC >= 80){
          tmpD = tmpD | 0x02;
        }

        //PD7...PD2
        tmpD = tmpD | (totalWeight & 0xFC);

        PORTD = tmpD;
 	  }
 	  return 0;
 }
