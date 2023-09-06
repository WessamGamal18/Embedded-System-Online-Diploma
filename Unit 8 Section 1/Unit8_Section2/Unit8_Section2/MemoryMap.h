/*
 * MemoryMap.h
 *
 * Created: 21-Aug-23 5:52:07 PM
 *  Author: Ahmed & Wessam
 */ 


#ifndef MEMORYMAP_H_
#define MEMORYMAP_H_

#define PORTA (*(volatile unsigned char *) 0x3B)
#define DDRA (*(volatile unsigned char *) 0x3A)
#define PINA (*(volatile unsigned char *) 0x39)

#define PORTC (*(volatile unsigned char *) 0x35)
#define DDRC (*(volatile unsigned char *) 0x34)
#define PINC (*(volatile unsigned char *) 0x33)

#define PORTD (*(volatile unsigned char *) 0x32)
#define DDRD (*(volatile unsigned char *) 0x31)
#define PIND (*(volatile unsigned char *) 0x30)


#define UCSRA (*(volatile unsigned char *) 0x2B)
#define UCSRB (*(volatile unsigned char *) 0x2A)
#define UCSRC (*(volatile unsigned char *) 0x40)
#define UDR (*(volatile unsigned char *) 0x2C)
#define UBRRL (*(volatile unsigned char *) 0x29)


#endif /* MEMORYMAP_H_ */