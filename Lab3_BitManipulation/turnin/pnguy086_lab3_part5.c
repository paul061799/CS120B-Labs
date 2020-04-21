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
    /* Insert DDR and PORT initializations */
    DDRD = 0x00; PORTD = 0xFF;
    DDRB = 0xFE; PORTB = 0x01; //set PB0 to input and PB7...PB1 as output
    /* Insert your solution below */
    unsigned char tmpB = 0;
    unsigned short weight = 0;
    while (1) {
        tmpB = PINB & 0x01;
        weight = (PIND << 1) | tmpB;

        tmpB = tmpB & 0x00;
        if(weight >= 70){
          tmpB = tmpB | 0x02;
        } else if(weight > 5) {
          tmpB = tmpB | 0x04;
        }
        PORTB = tmpB;
    }
    return 1;
}
