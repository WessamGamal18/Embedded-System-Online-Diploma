/*
 ============================================================================
 Name        : FIFO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "FIFO.h"

E_Buffer_status FIFO_init(FIFO_Buf_t* fifo, element_type* buff , uint32_t buff_length)
{
	if(buff==NULL)
		return FIFO_null;
	fifo->length = buff_length;
	fifo->base = buff;
	fifo->head = fifo->base;
	fifo->tail = fifo->base;
	fifo->count = 0;
	return FIFO_no_error;
}
E_Buffer_status FIFO_enqueue(FIFO_Buf_t* fifo, element_type* ENQ_Data)
{
	if(FIFO_Is_Buf_Full(fifo) == FIFO_no_error)
	{
		*(fifo->head) = *(ENQ_Data);
		fifo->count++;
		/*Circler FIFO*/
		if (fifo->head == (fifo->base +(fifo->length * sizeof(element_type))))
			fifo->head = fifo->base;
		else
			fifo->head++;
		return FIFO_no_error;
	}
	else
	{
		printf("FIFO Enqueue Failed \n");
		return (FIFO_Is_Buf_Full(fifo));
	}
}
E_Buffer_status FIFO_dequeue(FIFO_Buf_t* fifo, element_type* DEQ_Data)
{
	if (!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;
	else if (fifo->count == 0)
	{
		printf("FIFO Is Empty \n");
		return FIFO_empty;
	}
	else
	{
		*DEQ_Data =*(fifo->tail);
		fifo->count--;
		if (fifo->tail == (fifo->base +(fifo->length * sizeof(element_type))))
			fifo->tail = fifo->base;
		else
			fifo->tail++;
		return FIFO_no_error;
	}

}
void FIFO_print(FIFO_Buf_t* fifo)
{
	char i;
	element_type* temp = fifo->tail;
	if (!fifo->base || !fifo->head || !fifo->tail)
		printf("FIFO Is NULL \n");
	else if (fifo->count == 0)
		printf("FIFO Is Empty \n");
	else
	{
		printf("======FIFO Print========\n");
		for (i=0;i<fifo->count;i++)
		{
			printf("\t  %x  \t \n",*temp);
			if (temp == (fifo->base +(fifo->length * sizeof(element_type))))
			{
				temp = fifo->base;
				continue;
			}
			temp++;
		}
		printf("===========================\n");
	}

}
E_Buffer_status FIFO_Is_Buf_Full(FIFO_Buf_t* fifo)
{
	if (!fifo->base || !fifo->head || !fifo->tail)
		return FIFO_null;
	if(fifo->count == fifo->length)
	{
		printf("FIFO Is Full \n");
		return FIFO_full;
	}
	else
		return FIFO_no_error;
}
