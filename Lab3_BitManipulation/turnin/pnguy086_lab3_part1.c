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
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    unsigned char tmpA = 0;
    unsigned char tmpB = 0;
    unsigned char count = 0;
    while (1) {
        tmpA = PINA;
        tmpB = PINB;

        count = ((tmpA & 0x80) >> 7) + ((tmpA & 0x40) >> 6) + ((tmpA & 0x20) >> 5) + ((tmpA & 0x10) >> 4) +
                ((tmpA & 0x08) >> 3) + ((tmpA & 0x04) >> 2) + ((tmpA & 0x02) >> 1) + (tmpA & 0x01) +
                ((tmpB & 0x80) >> 7) + ((tmpB & 0x40) >> 6) + ((tmpB & 0x20) >> 5) + ((tmpB & 0x10) >> 4) +
                ((tmpB & 0x08) >> 3) + ((tmpB & 0x04) >> 2) + ((tmpB & 0x02) >> 1) + (tmpB & 0x01);

        PORTC = count;
    }
    return 1;
}
