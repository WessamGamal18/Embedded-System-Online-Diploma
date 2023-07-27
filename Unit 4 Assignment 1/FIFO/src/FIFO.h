/*
 * FIFO.h
 *
 *  Created on: Jul 26, 2023
 *      Author: Wessam
 */

#ifndef FIFO_H_
#define FIFO_H_
#include <stdio.h>
#include <stdint.h>
#define element_type uint8_t
/*craete buffer*/

/* FIFO data types*/
typedef struct {
	unsigned int length;
	unsigned int count;
	element_type* base;
	element_type* tail;
	element_type* head;
} FIFO_Buf_t;

typedef enum {
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_null
}E_Buffer_status;

/* FIFO APIS*/

E_Buffer_status FIFO_enqueue(FIFO_Buf_t* fifo, element_type* ENQ_Data);
E_Buffer_status FIFO_dequeue(FIFO_Buf_t* fifo, element_type* DEQ_Data);
void FIFO_print(FIFO_Buf_t* fifo);
E_Buffer_status FIFO_init(FIFO_Buf_t* fifo, element_type* buff , uint32_t buff_length);
E_Buffer_status FIFO_Is_Buf_Full(FIFO_Buf_t* fifo);




#endif /* FIFO_H_ */
