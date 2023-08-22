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
    // PD0 as input 
	Reset_Bit(DDRD,0);
	Set_Bit(PORTD,0);
	
	// PD5,6,7 as output
	Set_Bit(DDRD,5);
	Set_Bit(DDRD,6);
	Set_Bit(DDRD,7);
	
	unsigned char i=5;
    while (1) 
    {
		while(i<8) 
		{
			while(Read_Bit(PIND,0)==0);
			if (Read_Bit(PIND,0)==1)
			{
				Set_Bit(PORTD,i);
				while(Read_Bit(PIND,0)==1);
			}
			i++;
		}
		
		while(Read_Bit(PORTD,5)==1)
		{
			i--;
			while(i>4)
			{
				while(Read_Bit(PIND,0)==0);
				if (Read_Bit(PIND,0)==1)
				{
					Reset_Bit(PORTD,i);
					while(Read_Bit(PIND,0)==1);
				}
				i--;
			}
			i++;
		}
			
	}
	return 0;
}

