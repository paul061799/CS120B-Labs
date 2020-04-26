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

enum States{Start, Init, Incr, Decr, Reset} state;

unsigned char count; //updated in transitions

void Tick() {

    switch(state){ //state transitions
        case Start:
            state = Init;
            count = 0x07;
            break;
        case Init:
            if(PINA == 0x02){if(count > 10){count--;}
                              state = Decr;}//count-- doesn't execute
            else if (PINA == 0x01) {state = Incr;
                                    if(count < 9){count++;}}
            else if (PINA == 0x03) {state = Reset;}
            else {state = Init;}
            break;
        case Incr:
            if(PINA == 0x01){state = Incr;}
            else if (PINA == 0x02) {state = Decr;
                                    if(count > 0) { count--; }}
            else if (PINA == 0x03) {state = Reset;}
            break;
        case Decr:
            if(PINA == 0x01){state = Incr;
                             if(count < 9) { count++; }}
            else if (PINA == 0x02) {state = Decr;}
            else if (PINA == 0x03) {state = Reset;}
            break;
        case Reset:
            if(PINA != 0x03) {state = Init;}
            else {state = Reset;}
            break;
        default:
            printf("State Transition Error\n");
            break;
    } //state transitions

    switch(state){
        case Init:
        case Incr:
        case Decr:
          break;
        case Reset:
            count = 0;
            break;
        default:
            printf("State Action Error \n");
            break;
    }

    PORTC = count;
}

int main(void) {
    /* Insert DDR and PORT initializations */
    DDRA = 0x00; PORTA = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    /* Insert your solution below */
    state = Start;
    while (1) {
      Tick();
    }
    return 1;
}
