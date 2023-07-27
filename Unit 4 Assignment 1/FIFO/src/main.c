/*
 * main.c
 *
 *  Created on: Jul 26, 2023
 *      Author: Wessam
 */
#include <stdio.h>
#include <stdlib.h>
#include "FIFO.h"
#define width1 5
element_type uart_Buff[width1];

int main()
{
	element_type temp,i;
	FIFO_Buf_t FIFO_UART;
	if(FIFO_init(&FIFO_UART , uart_Buff , width1) == FIFO_no_error)
	{
		printf("FIFO init ---- Done \n");
		for(i=0;i<width1;i++)
		{
			if(FIFO_enqueue(&FIFO_UART,&i)== FIFO_no_error)
				printf("FIFO Enqueue (%x) ---- Done \n",i);
			else
				printf("FIFO Enqueue (%x) ---- Failed \n",i);
		}
	}
	FIFO_print(&FIFO_UART);
	if (FIFO_dequeue(&FIFO_UART,&temp)== FIFO_no_error)
		printf("FIFO Dequeue : Data=%X \n",temp);
	if (FIFO_dequeue(&FIFO_UART,&temp)== FIFO_no_error)
		printf("FIFO Dequeue : Data=%X \n",temp);
	printf("\nBefore Enqueue again\n");
	FIFO_print(&FIFO_UART);
	for(i=0;i<2;i++)
	{
		if(FIFO_enqueue(&FIFO_UART,&i)== FIFO_no_error)
			printf("FIFO Enqueue (%x) ---- Done \n",i);
		else
			printf("FIFO Enqueue (%x) ---- Failed \n",i);
	}
	FIFO_print(&FIFO_UART);
	return 0;
}
