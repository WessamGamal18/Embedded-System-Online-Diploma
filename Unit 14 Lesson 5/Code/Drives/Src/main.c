/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "Stm32_F103C6.h"
#include "Stm32_F103C6_GPIO_Driver.h"
#include "Stm32_F103C6_EXTI_Driver.h"
#include "lcd.h"
#include "keypad.h"

uint8_t TaskA_Flag, TaskB_Flag, IRQ_Flag = 0;

#define TaskA_Stack_Size	100 //100 Bytes
#define TaskB_Stack_Size	100 //100 Bytes

extern int _estack ;

//Main Stack
unsigned int _S_MSP = &_estack ;
unsigned int _E_MSP ;

//Process stack Task A
unsigned int _S_PSP_TA ;
unsigned int _E_PSP_TA ;

//Process stack Task B
unsigned int _S_PSP_TB ;
unsigned int _E_PSP_TB ;

#define OS_Set_PSP(add)				__asm volatile("mov r0,%0 \n\t MSR PSP,r0" : : "r" (add))
#define OS_Switch_SP_to_PSP			__asm volatile("MRS r0,CONTROL \n\t mov r1,#0x02 \n\t orr r0,r0,r1 \n\t MSR CONTROL,r0")
#define OS_Switch_SP_to_MSP			__asm volatile("MRS r0,CONTROL \n\t mov r1,#0x05 \n\t and r0,r0,r1 \n\t MSR CONTROL,r0")

#define OS_Generate_Exception		__asm volatile("SVC #0x3")

#define Thread_Mode_Privileged 		__asm volatile("MRS r3,CONTROL \n\t lsr r3,r3,#0x1 \n\t lsl r3,r3,#0x1 \n\t MSR CONTROL,r3")
#define Thread_Mode_UnPrivileged 	__asm volatile("MRS r3,CONTROL \n\t orr r3,r3,#0x1 \n\t MSR CONTROL,r3")

enum CPU_Access_Level {
	Privileged,
	Unprivileged
};

void SVC_Handler()
{
	Thread_Mode_Privileged;
}

void SWITCH_CPU_AccessLevel(enum CPU_Access_Level level)
{
	switch(level)
	{
	case Privileged:
		//Clear Bit 0 CONTROL register
		__asm(" MRS r3,CONTROL   \n\t"
				" lsr r3,r3,#0x1   \n\t"
				" lsl r3,r3,#0x1   \n\t"
				" MSR CONTROL,r3");
		break;

	case Unprivileged:
		//Set Bit 0 CONTROL register
		__asm(" MRS r3,CONTROL   \n\t"
				" orr r3,r3,#0x1   \n\t"
				" MSR CONTROL,r3 " );
		break;
	}
}

void EXTI9_Callback(void)
{
	//CPU in handler mode
	if (IRQ_Flag == 0)
	{
		TaskA_Flag =1;
		IRQ_Flag = 1;
	}else if (IRQ_Flag == 1)
	{
		TaskB_Flag =1;
		IRQ_Flag = 0;
	}
}

int TaskA (int a,int b,int c)
{

	return a+b+c;
}

int TaskB (int a,int b,int c,int d)
{

	return a+b+c+d;
}
void MainOS()
{
	//Main Stack
	_E_MSP = (_S_MSP - 512);

	//Task A
	_S_PSP_TA = (_E_MSP -8);
	_E_PSP_TA = (_S_PSP_TA - TaskA_Stack_Size);

	//Task B
	_S_PSP_TB = (_E_PSP_TA -8);
	_E_PSP_TB = (_S_PSP_TB - TaskB_Stack_Size);

	while (1)
	{
		__asm("NOP");
		if(TaskA_Flag ==1)
		{
			//Set PSP Register = _S_PSP_TA
			OS_Set_PSP(_S_PSP_TA);
			// SP -> PSP
			OS_Switch_SP_to_PSP;
			// Switch from privileged -> unprivileged
			Thread_Mode_UnPrivileged;

			TaskA_Flag = TaskA(1, 2, 3);

			// Switch from unprivileged -> privileged
			OS_Generate_Exception;
			// SP -> MSP
			OS_Switch_SP_to_MSP;

		}else if (TaskB_Flag ==1)
		{
			//Set PSP Register = _S_PSP_TB
			OS_Set_PSP(_S_PSP_TB);
			// SP -> PSP
			OS_Switch_SP_to_PSP;
			// Switch from privileged -> unprivileged
			Thread_Mode_UnPrivileged;

			TaskB_Flag = TaskB(1, 2, 3, 4) ;

			// Switch from unprivileged -> privileged
			OS_Generate_Exception;
			// SP -> MSP
			OS_Switch_SP_to_MSP;

		}

	}

}


int main(void)
{

	//Enable clock
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	AFIO_CLK_EN();

	//Set EXTI Configuration
	EXTI_PinConfig_t EXTI_CGF;
	EXTI_CGF.EXTI_PIN = EXTI9PB9;
	EXTI_CGF.Trigger_Case = EXTI_Trigger_RISING;
	EXTI_CGF.P_IRQ_CallBack = EXTI9_Callback;
	EXTI_CGF.IRQ_EN = EXTI_IRQ_Enable;
	MCAL_EXTI_GPIO_Init(&EXTI_CGF);

	MainOS();
	IRQ_Flag = 1;

	SWITCH_CPU_AccessLevel(Unprivileged);

	while(1)
	{
		if(IRQ_Flag)
		{
			IRQ_Flag =0;
		}else
		{
			/* Misra */
		}
	}
}

