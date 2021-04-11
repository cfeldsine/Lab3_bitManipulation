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
    DDRC = 0xFF; PORTC = 0x00;

    unsigned char tmpA, ignition, driver, seatbelt, tmpC, mask;
    while (1) {
	tmpC = 0x00;
    	tmpA = PINA & 0x0F;
	mask = 0x01;

	ignition = PINA & 0x10;
	driver = PINA & 0x20;
	seatbelt = PINA & 0x40;
	
	if (ignition && driver && !seatbelt) {
	    tmpC = tmpC | 0x80;
	}
	
	if (tmpA > 12) {
	    tmpC = tmpC | mask;
	}
	mask *= 2;

	if (tmpA > 9) {
	    tmpC = tmpC | mask;
	}
	mask *= 2;

        if (tmpA > 6) {
            tmpC = tmpC | mask;
        }
        mask *= 2;
     
        if (tmpA > 4) {
            tmpC = tmpC | mask;
        }
        mask *= 2;
    
        if (tmpA > 2) {
            tmpC = tmpC | mask;
        }
	mask *= 2;
	
        if (tmpA > 0) {
            tmpC = tmpC | mask;
        }
	
	mask *= 2;
	
	if (tmpA < 4) {
	    tmpC = tmpC | mask;
	}
        
	PORTC = tmpC;
    }
    return 1;
}
