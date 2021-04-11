/*	Author: cfeld005
 *  Partner(s) Name: 
 *	Lab Section: 023
 *	Assignment: Lab #3  Exercise #1
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
    DDRB = 0x00; PORTB = 0xFF;
    DDRC = 0xFF; PORTC = 0x00;
    unsigned char i, count, mask, tmpA, tmpB;
    while (1) {
	count = 0x00;
	mask = 0x01;
	tmpA = PINA;
	tmpB = PINB;
	i = 0;

	while (i<8){
	    if (mask & tmpA){
	    	count++;
	    }
	    mask *= 2;
	    i++;	
	}
	mask = 0x01;
	i = 0;
	while (i < 8){
	    if (mask & tmpB){
	    	count++;
	    }
	    mask *= 2;
	    i++;
	}
	PORTC = count;
    }
    return 1;
}
