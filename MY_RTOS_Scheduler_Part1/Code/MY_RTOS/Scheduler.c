/*
 * Scheduler.c
 *
 *  Created on: Oct 17, 2023
 *      Author: Ahmed & Wessam
 */

#include "Scheduler.h"
#include "MYRTOS_FIFO.h"

struct {
	Task_ref* OSTasks[100]; //Scheduler Table
	unsigned int _S_MSP_Task;
	unsigned int _E_MSP_Task;
	unsigned int PSP_Task_Locator;
	unsigned int NoOfActiveTasks;
	Task_ref* CurrentTask;
	Task_ref* NextTask;
	enum{
		OSsuspend,
		OSrunning
	}OSmodeID;

}OS_Control;

FIFO_Buf_t Ready_Queue;
Task_ref* Ready_Queue_FIFO[100];
Task_ref MYRTOS_idleTask ;

//to excute specific OS services
void OS_SVC_services (int* StackFramePointer)
{
	//OS_SVC_Set Stack -> r0 -> argument 0 = StackFramePointer
	//OS_SVC_Set Stack : r0,r1,r2,r3,r12,LR.PC.XPSR

	unsigned char SVC_Number;

	SVC_Number = *((unsigned char*)(((unsigned char*)StackFramePointer[6])-2)) ;

	switch(SVC_Number)
	{
	case 1:

		break;
	case 2:

		break;
	case 3:

		break;
	}

}


void PendSV_Handler ()
{
	//Clear PendSV
	// SCB -> ICSR |= SCB_ICSR_PENDSVCLR_Msk
}

void MYRTOS_Idle_Task()
{
	while (1)
	{
		__asm("NOP");
	}
}

int OS_SVC_Set(int SVC_ID)
{
	int result;
	switch(SVC_ID)
	{
	case 1: //Activate Task
		__asm("svc #0x01");
		break;
	case 2: //Terminate Task
		__asm("svc #0x02");
		break;
	case 3: //OS PendSV
		__asm("svc #0x03");
		break;
	}

}


void MYRTOS_Create_MainStack()
{
	OS_Control._S_MSP_Task = &_estack;
	OS_Control._E_MSP_Task = OS_Control._S_MSP_Task - MainStackSize;
	//Aligned 8 Bytes spaces between main task and PSP tasks
	OS_Control.PSP_Task_Locator = (OS_Control._E_MSP_Task - 8 );

	//if (_E_MSP_Task < &_eheap) Error:excedded the available stack size

}



MYRTOS_errorID MYRTOS_init()
{
	MYRTOS_errorID error = NoError ;

	//Update OS Mode (OSsuspend)
	OS_Control.OSmodeID = OSsuspend;

	//Specify the Main Stack for OS
	MYRTOS_Create_MainStack();

	//Create OS Ready Queue
	if (FIFO_init(&Ready_Queue, Ready_Queue_FIFO, 100) != FIFO_NO_ERROR)
		error += Ready_Queue_init_error;

	//Configure IDLE Task
	strcpy (MYRTOS_idleTask.TaskName , "idleTask");
	MYRTOS_idleTask.priority = 255;
	MYRTOS_idleTask.p_TaskEntry = MYRTOS_Idle_Task ;
	MYRTOS_idleTask.Stack_Size = 300;

	error += MYRTOS_CreateTask(&MYRTOS_idleTask);




	return error ;

}


void MyRTOS_Create_Task_Stack(Task_ref* Tref)
{
	//Task Frame
	/* ====================
	 * XPSR
	 * PC
	 * LR
	 * r12
	 * r4,r3,r2,r1,r0
	 * =====================
	 * r5,r6,r7,r8,r9,r11 (Saved/Restore) Manual
	 */
	Tref->Current_PSP = Tref->_S_PSP_Task ;

	Tref->Current_PSP--;
	*(Tref->Current_PSP) = 0x01000000; // DUMMY_XPSR should T = 1 to avoid BUS fault

	Tref->Current_PSP--;
	*(Tref->Current_PSP) = (unsigned int)Tref->p_TaskEntry ; //PC

	Tref->Current_PSP--; //LR = 0xFFFFFFFD (EXC_RETURN) Return to thread and PSP stack
	*(Tref->Current_PSP) = 0xFFFFFFFD ;

	for (int j=0; j<13;j++)
	{
		Tref->Current_PSP--;
		*(Tref->Current_PSP) = 0;
	}


}




MYRTOS_errorID MYRTOS_CreateTask(Task_ref* Tref)
{
	MYRTOS_errorID error = NoError ;

	//Create its own PSP stack
	//Check task stack size exceeded the PSP stack
	Tref->_S_PSP_Task = OS_Control.PSP_Task_Locator;
	Tref->_E_PSP_Task = Tref->_S_PSP_Task - Tref->Stack_Size;

	//	-					-
	//	- _S_PSP_Task		-
	//	- Task stack		-
	//	- _E_PSP_Task		-
	//	-					-
	//	- _eheap			-
	//	-					-
	if(Tref->_E_PSP_Task < (unsigned int) (&(_eheap)))
	{
		return Task_exceeded_StackSize;
	}

	//Aligned 8 Bytes spaces between Task PSP and other
	OS_Control.PSP_Task_Locator = (Tref->_E_PSP_Task - 8 );

	//Initialize PSP Task stack
	MyRTOS_Create_Task_Stack(Tref);

	//Task State Update -> Suspend
	Tref->TaskState = Suspend;

	return error ;

}









