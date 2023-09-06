/*
 * UART.h
 *
 * Created: 30-Aug-23 4:28:49 PM
 *  Author: Ahmed & Wessam
 */ 


#ifndef UART_H_
#define UART_H_

//----------------------------------
//Includes
//----------------------------------
#include "MemoryMap.h"
#include "Utils.h"

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Macros Configuration References
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//UCSRA
#define		MPCM		0
#define		U2X			1
#define		PE			2
#define		DOR			3
#define		FE			4
#define		UDRE		5
#define		TXC			6
#define		RXC			7

//UCSRB
#define		TXB8		0
#define		RXB8		1
#define		UCSZ2		2
#define		TXEN		3
#define		RXEN		4
#define		UDRIE		5
#define		TXCIE		6
#define		RXCIE		7

//UCSRC
#define		UCPOL		0
#define		UCSZ0		1
#define		UCSZ1		2
#define		USBS		3
#define		UPM0		4
#define		UPM1		5
#define		UMSEL		6
#define		URSEL		7

#define DefaultStop		'\r'

/*
 * =============================================================================================
 * 										APIs Supported by "MCAL UART DRIVER"
 * =============================================================================================
 */

void UART_Init(void);

void UART_Send(unsigned char data);

unsigned char UART_Receive(void);	

void UART_SendString(unsigned char* String);

void UART_ReceiveString (unsigned char* Buff);
	


#endif /* UART_H_ */