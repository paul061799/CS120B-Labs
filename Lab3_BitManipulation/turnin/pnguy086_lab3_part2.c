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
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    unsigned char level = 0;
    unsigned char tmpC = 0;
    while (1) {
        level = PINA & 0x0F;

        if(level >= 13 && level <= 15){
          tmpC = 0x3F; //PC5 - PC0
        } else if (level >= 10) {
          tmpC = 0x3E; //PC5 - PC1
        } else if (level >= 7) {
          tmpC = 0x3C; //PC5 - PC2
        } else if (level >= 5) {
          tmpC = 0x38; //PC5 - PC3
        } else if (level >= 3) {
          tmpC = 0x30; //PC5 - PC4
        } else if (level > 0) {
          tmpC = 0x20; //PC5
        }

        //remains 0 if level 0

        if(level < 5){
          tmpC = tmpC | 0x40;
        }

        PORTC = tmpC;
    }
    return 1;
}
