/*
 * LIFO.h
 *
 *  Created on: Jul 26, 2023
 *      Author: Wessam
 */

#ifndef LIFO_H_
#define LIFO_H_


#include <stdio.h>
#include <stdint.h>
#define element_type uint8_t
/*craete buffer*/

/* LIFO data types*/
typedef struct {
	unsigned int length;
	unsigned int count;
	element_type* base;
	element_type* head;
} LIFO_Buf_t;

typedef enum {
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_null
}E_Buffer_status;

/* LIFO APIS*/

E_Buffer_status LIFO_Add_item(LIFO_Buf_t* lifo, element_type item);
E_Buffer_status LIFO_Pop_item(LIFO_Buf_t* lifo, element_type* item);
E_Buffer_status LIFO_init(LIFO_Buf_t* lifo, element_type* buff , uint32_t buff_length);
E_Buffer_status LIFO_Is_Buf_Full(LIFO_Buf_t* lifo);




#endif /* LIFO_H_ */
