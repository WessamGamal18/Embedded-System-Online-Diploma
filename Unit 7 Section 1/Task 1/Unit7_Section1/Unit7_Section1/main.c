/*
 * Unit7_Section1.c
 *
 * Created: 21-Aug-23 5:51:16 PM
 * Author : Ahmed & Wessam
 */ 
#define F_CPU 8000000UL

#include <util/delay.h>
#include "MemoryMap.h"
#include "Utils.h"

int main(void)
{
    // PC0 as input 
	Reset_Bit(DDRC,0);
	Set_Bit(PORTC,0);
	
	// PA as output
	Set_Bit(DDRA,0);
	Set_Bit(DDRA,1);
	Set_Bit(DDRA,2);
	Set_Bit(DDRA,3);
	Set_Bit(DDRA,4);
	Set_Bit(DDRA,5);
	Set_Bit(DDRA,6);
	Set_Bit(DDRA,7);
	
	
    while (1) 
    {
		if (Read_Bit(PINC,0)==0)
		{
			Set_Bit(PORTA,0);
			_delay_ms(1000);
			Set_Bit(PORTA,1);
			_delay_ms(1000);
			Set_Bit(PORTA,2);
			_delay_ms(1000);
			Set_Bit(PORTA,3);
			_delay_ms(1000);
			Set_Bit(PORTA,4);
			_delay_ms(1000);
			Set_Bit(PORTA,5);
			_delay_ms(1000);
			Set_Bit(PORTA,6);
			_delay_ms(1000);
			Set_Bit(PORTA,7);
			_delay_ms(1000);
			// turn off leds
			Reset_Bit(PORTA,7);
			_delay_ms(1000);
			Reset_Bit(PORTA,6);
			_delay_ms(1000);
			Reset_Bit(PORTA,5);
			_delay_ms(1000);
			Reset_Bit(PORTA,4);
			_delay_ms(1000);
			Reset_Bit(PORTA,3);
			_delay_ms(1000);
			Reset_Bit(PORTA,2);
			_delay_ms(1000);
			Reset_Bit(PORTA,1);
			_delay_ms(1000);
			Reset_Bit(PORTA,0);
			while(Read_Bit(PINC,0)==0);
		}
	}
	return 0;
}

