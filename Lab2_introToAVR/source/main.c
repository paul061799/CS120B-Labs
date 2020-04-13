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
 	 DDRC= 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs, initialize to 0s
 	 //unsigned char tmpB = 0x00; // Temporary variable to hold the value of B
 	 unsigned char tmpA = 0x00; // Temporary variable to hold the value of A
   unsigned char cntavail = 0x00;
   while(1) {
 		   // 1) Read input
 		   tmpA = !PINA & 0x0F; //changes inputs so that 1 is available, 0 is full
 		   // 2) Perform computation
 		   //count the number of spaces available
       switch (tmpA){
         case 0x00:
            cntavail = 0x04;
            break;
         case 0x01:
         case 0x02:
         case 0x04:
         case 0x08:
            cntavail = 0x03;
            break;
         case 0x03:
         case 0x05:
         case 0x09:
         case 0x0A:
         case 0x06:
         case 0x0C:
            cntavail = 0x02;
            break;
         case 0x07:
         case 0x0B:
         case 0x0D:
         case 0x0E:
            cntavail = 0x01;
            break;
         case 0x0F:
            cntavail = 0x00;
            break;
       }
 	      // 3) Write output
        //if(cntavail == 0){
          //PORTC = 0x80;
        //} else {
          PORTC = cntavail;
        //}
 	  }
 	  return 0;
 }
