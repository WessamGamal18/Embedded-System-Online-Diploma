/*
 * DC_motor.c
 *
 *  Created on: Jul 29, 2023
 *      Author: Ahmed & Wessam
 */


#include "DC.h"
#include "state.h"
int DC_speed =0;
void (*DC_state)();
enum DC DC_state_id;

void DC_init()
{
	/* init DC */
	printf("DC_init \n");
}

void DC_motor (int s)
{
	DC_speed =s ;
	DC_state = STATE(DC_Busy);
	printf("CA-------speed=%d---------> DC\n",DC_speed);

}

STATE_define(DC_Idle)
{
	DC_state_id = DC_idle;
	printf("DC_idle state : speed=%d \n \n \n",DC_speed);
}

STATE_define(DC_Busy)
{
	/* state action */
	DC_state_id = DC_busy;

	/* call DC driver */
	DC_state = STATE(DC_Idle);
	printf("DC_busy state : speed=%d \n \n \n",DC_speed);
}


