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
#include "UART.h"
#include "keypad.h"
#include "lcd.h"

int main(void)
{
	LCD_INIT();
	Keypad_init();
	UART_Init();
	_delay_ms(100);
	LCD_GOTO_XY(1,0);
	LCD_WRITE_STRING("UART TR");
	unsigned char String[100];
	UART_SendString("Ready");
	while(1){
		
			UART_ReceiveString(String);
			LCD_GOTO_XY(2,0);
			LCD_WRITE_STRING(String);
			LCD_WRITE_STRING(" <Done> ");
			
			
			
		
			}
	return 0;
}

