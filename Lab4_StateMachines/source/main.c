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

enum States{Start = 0, Lock = 1, Push1 = 2, Release1 = 3, Unlock = 4} state;

unsigned char lock; //updated in transitions
unsigned char state_num;

void Tick() {

    switch(state){ //state transitions
        case Start:
            state = Lock;
            lock = 0;
            break;
        case Lock:
            if(PINA == 0x04){state = Push1;}
            else {state = Lock;}
            break;
        case Push1:
            if(PINA == 0x00){state = Release1;}
            else if (PINA == 0x04) {state = Push1;}
            else {state = Lock;}
            break;
        case Release1:
            if(PINA == 0x02){state = 4;}
            else if (PINA == 0x00) {state = Release1;}
            else {state = Lock;}
            break;
        case Unlock:
            if(PINA == 0x07) {state = Lock;}
            else {state = Unlock;}
            break;
        default:
            printf("State Transition Error\n");
            break;
    } //state transitions

    switch(state){
        case Start:
        case Lock:
        case Push1:
        case Release1:
          break;
        case Unlock:
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
    /* Insert DDR and PORT Lockializations */
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
