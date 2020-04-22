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
    DDRA = 0x00; PORTA = 0xFF; //onfigure PORTA as input, initialize to 1s
    DDRB = 0xFF; PORTB = 0x00; //configure port B's 8 pins as outputs
    unsigned char led = 0x00;
    unsigned char button = 0x00;
    /* Insert your solution below */
    while (1) {
        //if PA is 1, set PB1PB0=01, else  =10
        // 1) Read inputs
        button = ~PINA & 0x01; //Button connected to A0
        if(button){
            led = (led & 0xFC) | 0x01;//set B to 0x01
        } else {
            led = (led & 0xFC) | 0x02;//set B to 0x02
        }
        PORTB = led;
    }
    return 1;
}
