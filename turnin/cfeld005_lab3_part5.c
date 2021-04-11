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
    DDRD = 0x00; PORTD = 0xFF;
    DDRB = 0xFE; PORTB = 0x01;

    unsigned char tmpD;
    unsigned char tmpB;
    unsigned short total;

    while (1){
	tmpD = PIND;
    	tmpB = PINB;
    	total = (tmpD*2) + (tmpB & 0x01);

	if (total >= 70) {
	    tmpB = 0x02;
	} else if (total >= 5 && total < 70) {
	    tmpB = 0x04;
	} else {
	    tmpB = 0x00;
	}
	PORTB = tmpB;
    }
    return 1;
}
