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

enum States{Start, 0, 1, 2, 3} state;

unsigned char lock; //updated in transitions

void Tick() {

    switch(state){ //state transitions
        case Start:
            state = 0;
            lock = 0;
            break;
        case 0:
            if(PINA == 0x04){state = 1}
            else {state = 0;}
            break;
        case 1:
            if(PINA == 0x00){state = 2;}
            else if (PINA == 0x04) {state = 1;}
            else {state = 0;}
            break;
        case 2:
            if(PINA == 0x02){state = 3;}
            else if (PINA == 0x00) {state = 2;}
            else {state = 0;}
            break;
        case 3:
            if(PINA == 0x07) {state = 0;}
            else {state = 3;}
            break;
        default:
            printf("State Transition Error\n");
            break;
    } //state transitions

    switch(state){
        case 0:
        case 1:
        case 2:
          break;
        case 3:
            lock = 1;
            break;
        default:
            printf("State Action Error \n");
            break;
    }
    PORTB = lock;
    PORTC = state;
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    state = Start;
    while (1) {
      Tick();
    }
    return 1;
}
