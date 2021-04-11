/*	Author: cfeld005
 *  Partner(s) Name: 
 *	Lab Section: 023
 *	Assignment: Lab #3  Exercise #2
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
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    DDRC = 0xFF; PORTC = 0x00;

   unsigned char tmpA, tmpB, tmpC;
    while (1) {
	tmpA = PINA;
	tmpB = tmpA;
	tmpB = tmpB/16;
	tmpA *= 16;
	tmpC = tmpA;

        PORTB = tmpB;
	PORTC = tmpC;
    }
    return 1;
}
