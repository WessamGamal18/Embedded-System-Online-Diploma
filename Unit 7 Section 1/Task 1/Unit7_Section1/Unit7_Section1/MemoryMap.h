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



#endif /* MEMORYMAP_H_ */