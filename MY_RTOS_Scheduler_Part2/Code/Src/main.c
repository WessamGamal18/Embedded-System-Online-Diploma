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

#include "core_cm3.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "Stm32_F103C6.h"
#include "Stm32_F103C6_GPIO_Driver.h"
#include "Stm32_F103C6_EXTI_Driver.h"
#include "lcd.h"
#include "keypad.h"
#include "Scheduler.h"


Task_ref Task1,Task2,Task3;
unsigned char Task1LED,Task2LED,Task3LED,Task4LED;

void task1()
{
	while (1)
	{
		//Task 1 code
		Task1LED ^= 1;
	}
}

void task2()
{
	while (1)
	{
		//Task 2 code
		Task2LED ^= 1;
	}
}

void task3()
{
	while (1)
	{
		//Task 3 code
		Task3LED ^= 1;
	}
}

int main(void)
{
	MYRTOS_errorID error = 0;
	//HW_init (initialize clock Tree, Reset controller)
	HW_init();

	if ( MYRTOS_init() != NoError )
		while (1);

	Task1.Stack_Size = 1024;
	Task1.p_TaskEntry = task1;
	Task1.priority = 3;
	strcpy(Task1.TaskName , "task_1");

	Task2.Stack_Size = 1024;
	Task2.p_TaskEntry = task2;
	Task2.priority = 3;
	strcpy(Task2.TaskName , "task_2");

	Task3.Stack_Size = 1024;
	Task3.p_TaskEntry = task3;
	Task3.priority = 3;
	strcpy(Task3.TaskName , "task_3");

	error += MYRTOS_CreateTask(&Task1);
	error += MYRTOS_CreateTask(&Task2);
	error += MYRTOS_CreateTask(&Task3);

	MYRTOS_ActivateTask(&Task1);
	MYRTOS_ActivateTask(&Task2);
	MYRTOS_ActivateTask(&Task3);

	MYRTOS_StartOS();

	while(1)
	{

	}
}

