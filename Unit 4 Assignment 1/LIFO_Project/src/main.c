/*
 * main.c
 *
 *  Created on: Jul 26, 2023
 *      Author: Ahmed & Wessam
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdint.h>
#include "LIFO.h"
#define width1 3
element_type Buff[width1];
#define width2 4


int main()
{
	element_type temp,i;
	LIFO_Buf_t LIFO_UART,LIFO_I2C;
	if(LIFO_init(&LIFO_UART , Buff , width1) == LIFO_no_error)
		printf("LIFO UART init ---- Done \n");
	else
		printf("LIFO UART init ---- Failed \n");

	element_type* Buff2 = (element_type*) malloc(width2*sizeof(element_type));
	if(LIFO_init(&LIFO_I2C , Buff2 , width2) == LIFO_no_error)
		printf("LIFO I2C init ---- Done \n");
	else
		printf("LIFO UART init ---- Failed \n");
	printf("\n");
	for (i=0;i<width1;i++)
	{
		if( LIFO_Add_item(&LIFO_UART,i) == LIFO_no_error)
			printf("LIFO UART add : %d\n",i);
	}
	printf("\n");
	for (i=0;i<width1;i++)
	{
		if(LIFO_Pop_item(&LIFO_UART, &temp) == LIFO_no_error)
			printf("LIFO UART get : %d\n",temp);
	}
	/* LIFO_I2C*/
	printf("\n=======LIFO I2C (Dynamic Allocation)=======\n");

	for (i=0;i<width2;i++)
	{
		if( LIFO_Add_item(&LIFO_I2C,i) == LIFO_no_error)
			printf("LIFO I2C add : %d\n",i);
	}
	printf("\n");
	for (i=0;i<width2;i++)
	{
		if(LIFO_Pop_item(&LIFO_I2C, &temp) == LIFO_no_error)
			printf("LIFO I2C get : %d\n",temp);
	}

	return 0;
}

