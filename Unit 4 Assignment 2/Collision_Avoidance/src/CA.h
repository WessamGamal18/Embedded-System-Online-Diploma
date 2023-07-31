/*
 * Collision_Avoidance.h
 *
 *  Created on: Jul 29, 2023
 *      Author: Ahmed & Wessam
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"

enum CA{
	CA_waiting,
	CA_driving
};

/* prototypes */
STATE_define(CA_Waiting);
STATE_define(CA_Driving);

/* golbal pointer to function */
extern void (*CA_state)();



#endif /* CA_H_ */
