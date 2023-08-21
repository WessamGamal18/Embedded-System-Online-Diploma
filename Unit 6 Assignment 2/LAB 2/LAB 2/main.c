/*
 * LAB 2.c
 *
 * Created: 21-Aug-23 2:39:53 PM
 * Author : Ahmed & Wessam
 */ 
#define F_CPU 8000000UL


#include <avr/interrupt.h>
#include <util/delay.h>
#include "utils.h"



#define IO_BASE 0x20
#define IO_POTD *(volatile unsigned int *)(IO_BASE + 0x12)
#define IO_DDRD *(volatile unsigned int *)(IO_BASE + 0x11)
#define IO_DDRB *(volatile unsigned int *)(IO_BASE + 0x17)
#define INT_MCUCR *(volatile unsigned int *)(IO_BASE + 0x35)
#define INT_MCUCSR *(volatile unsigned int *)(IO_BASE + 0x34)
#define INT_GICR *(volatile unsigned int *)(IO_BASE + 0x3B)
#define INT_GIFR *(volatile unsigned int *)(IO_BASE + 0x3A)
#define IO_SREG *(volatile unsigned int *)(IO_BASE + 0x3F)


void interrupt_init()
{
	// INT0 any logical change generates interrput request
	Set_Bit(INT_MCUCR,0);
	Reset_Bit(INT_MCUCR,1);
	// INT1 rising edge generates interrput request
	Set_Bit(INT_MCUCR,2);
	Set_Bit(INT_MCUCR,3);
	// INT2 falling edge generates interrput request
	Reset_Bit(INT_MCUCSR,6);
	// enable all interrput
	Set_Bit(INT_GICR,5);
	Set_Bit(INT_GICR,6);
	Set_Bit(INT_GICR,7);
	sei();

}

void PORT_init()
{
	// set PORTD pin(5,6,7) as output
	Set_Bit(IO_DDRD,5);
	Set_Bit(IO_DDRD,6);
	Set_Bit(IO_DDRD,7);
	// set PORTD pin(2,3) as input
	Reset_Bit(IO_DDRD,2);
	Reset_Bit(IO_DDRD,3);
	// set PORTB pin(2) as input
	Reset_Bit(IO_DDRB,2);
}

int main(void)
{
    interrupt_init();
	PORT_init();
    while (1) 
    {
		// turn off all leds 
		Reset_Bit(IO_POTD,5);
		Reset_Bit(IO_POTD,6);
		Reset_Bit(IO_POTD,7);
    }
	return 0;
}

ISR(INT0_vect)
{
	Set_Bit(IO_POTD,5);
	_delay_ms(1000);
}
ISR(INT1_vect)
{
	Set_Bit(IO_POTD,6);
	_delay_ms(1000);
}
ISR(INT2_vect)
{
	Set_Bit(IO_POTD,7);
	_delay_ms(1000);
}


