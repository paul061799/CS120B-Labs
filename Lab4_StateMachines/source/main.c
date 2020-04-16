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

enum States{Start, B0_Press, B0_Release, B1_Press, B1_Release} state;

void Tick() {
    switch(state){
        case Start:
            state = B0_Release;
            break;
        case B0_Release:
            state = (PINA == 0x01) ? B0_Press : B0_Release;
            break;
        case B0_Press:
            state = (PINA == 0x01) ? B0_Press : B1_Release;
            break;
        case B1_Release:
            state = (PINA == 0x01) ? B1_Press : B1_Release;
            break;
        case B1_Press:
            state = (PINA == 0x01) ? B1_Press : B0_Release;
            break;
        default:
            printf("State Transition Error\n");
            break;
    }

    switch(state){
        case Start:
            PORTB = 0x01;
            break;
        case B0_Release:
            break;
        case B0_Press:
            PORTB = 0x02;
            break;
        case B1_Release:
            break;
        case B1_Press:
            PORTB = 0x01;
            break;
        default:
            printf("State Action Error \n");
            break;
    }
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    /* Insert your solution below */
    state = Start;
    while (1) {
      Tick();
    }
    return 1;
}
