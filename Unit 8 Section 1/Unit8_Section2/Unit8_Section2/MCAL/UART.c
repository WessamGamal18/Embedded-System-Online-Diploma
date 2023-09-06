/*
 * UART.c
 *
 * Created: 30-Aug-23 4:28:39 PM
 *  Author: Ahmed & Wessam
 */ 

#include "UART.h"


void UART_Init(void)
{
	//Baudrate 9600
	//U2X: Double the USART Transmission Speed
	//Normal Speed , reset U2X 
	Reset_Bit(UCSRA,U2X);
	UBRRL = 51;
	
	//USART Mode Select
	//0 Asynchronous Operation
	Reset_Bit(UCSRC,UMSEL);
	
	//Disable Parity Mode, UPM1:0 = 00
	Reset_Bit(UCSRC,UPM0);
	Reset_Bit(UCSRC,UPM1);
	
	//USBS: Stop Bit Select, for 1-bit select 0
	Reset_Bit(UCSRC,USBS);
	
	//UCSZ1:0: Character Size, for 8-bit UCSZ0:1 , UCSZ1:1 , UCSZ2:0
	Set_Bit(UCSRC,UCSZ0);
	Set_Bit(UCSRC,UCSZ1);
	Reset_Bit(UCSRB,UCSZ2);
	
	//TXEN: Transmitter Enable, RXEN: Receiver Enable
	Set_Bit(UCSRB,TXEN);
	Set_Bit(UCSRB,RXEN);

	
}

void UART_Send(unsigned char data)
{
	while(!Read_Bit(UCSRA,UDRE));
	UDR = data;
}


void UART_ReceiveString (unsigned char* Buff)
{
	unsigned char x =0;
	Buff[x] = UART_Receive();
	while(Buff[x] != DefaultStop)
	{
		x++;
		Buff[x] = UART_Receive();
	}
	Buff[x] = '\0';
}

void UART_SendString(unsigned char* String)
{
	unsigned char x;
	for(x=0;x<String[x];x++)
	{
		UART_Send(String[x]);
	}
	UART_Send(DefaultStop);
}
		
unsigned char UART_Receive(void)
{
	while(!Read_Bit(UCSRA,RXC));
	return UDR;
}

