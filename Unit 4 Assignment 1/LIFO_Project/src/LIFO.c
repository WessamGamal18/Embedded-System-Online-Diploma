/*
 * LIFO.c
 *
 *  Created on: Jul 26, 2023
 *      Author: Ahmed & Wessam
 */
#include "LIFO.h"

E_Buffer_status LIFO_Add_item(LIFO_Buf_t* lifo, element_type item)
{
	if (!lifo->base || !lifo->head)
		return LIFO_null;
	else if(LIFO_Is_Buf_Full(lifo) == LIFO_no_error)
	{
		*(lifo->head) = item;
		lifo->count++;
		/*Check*/
		if (lifo->head == (lifo->base +(lifo->length * sizeof(element_type))))
			return LIFO_no_error;
		else
		{
			lifo->head++;
			return LIFO_no_error;
		}
	}
	else
	{
		printf("LIFO Add Failed \n");
		return (LIFO_Is_Buf_Full(lifo));
	}

}
E_Buffer_status LIFO_Pop_item(LIFO_Buf_t* lifo, element_type* item)
{
	if (!lifo->base || !lifo->head)
		return LIFO_null;
	else if (lifo->count == 0)
	{
		printf("LIFO Is Empty \n");
		return LIFO_empty;
	}
	else
	{
		lifo->head--;
		*item =*(lifo->head);
		lifo->count--;
		return LIFO_no_error;
	}

}
E_Buffer_status LIFO_init(LIFO_Buf_t* lifo, element_type* buff , uint32_t buff_length)
{
	if(buff==NULL)
		return LIFO_null;
	lifo->length = buff_length;
	lifo->base = buff;
	lifo->head = lifo->base;
	lifo->count = 0;
	return LIFO_no_error;
}


E_Buffer_status LIFO_Is_Buf_Full(LIFO_Buf_t* lifo)
{
	if (!lifo->base || !lifo->head)
		return LIFO_null;
	else if (lifo->count == lifo->length)
	{
		printf("LIFO Is Full \n");
		return LIFO_full;
	}
	else
		return LIFO_no_error;


}
