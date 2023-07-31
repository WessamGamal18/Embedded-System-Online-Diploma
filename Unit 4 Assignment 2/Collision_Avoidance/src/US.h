/*
 * US.h
 *
 *  Created on: Jul 31, 2023
 *      Author: Ahmed & Wessam
 */

#ifndef US_H_
#define US_H_


#include "state.h"

enum US{
	US_busy
};

void US_init();
STATE_define(US_Busy);

/*global pointer to function */
extern void (*US_state)();


#endif /* US_H_ */
