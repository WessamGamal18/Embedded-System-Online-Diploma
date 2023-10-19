/*
 * CortexMX_OS_Porting.c
 *
 *  Created on: Oct 17, 2023
 *      Author: Ahmed & Wessam
 */


#include "CortexMX_OS_Porting.h"


void HardFault_Handler(void)
{
	while(1);
}
void MemManage_Handler(void)
{
	while(1);
}
void BusFault_Handler(void)
{
	while(1);
}
void UsageFault_Handler(void)
{
	while(1);
}

__attribute ((naked)) void SVC_Handler()
{
	__asm ("tst lr,#4  \n\t"
			"ITE EQ \n\t"
			"mrseq r0,MSP \n\t"
			"mrsne r0,PSP \n\t"
			"B OS_SVC_services");
}


void HW_init()
{
	//intialize clock tree (RCC -> SysTick Timer & CPU) 8 MHZ
	//init HW
	//Clock Tree
	//RCC Default values makes CPU Clock & SysTick Timer clock = 8 MHZ

	// 8 MHZ
	// 1 count -> 0.125 us
	// X count -> 1 ms
	// X = 8000 count

}








