/*
 * DC.h
 *
 *  Created on: Jul 31, 2023
 *      Author: Ahmed & Wessam
 */

#ifndef DC_H_
#define DC_H_

#include "state.h"

enum DC{
	DC_idle,
	DC_busy
};

/* prototypes */
void DC_init();
STATE_define(DC_Idle);
STATE_define(DC_Busy);

extern void (*DC_state)();


#endif /* DC_H_ */
