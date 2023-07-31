/*
 ============================================================================
 Name        : Collision_Avoidance.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "CA.h"

int CA_speed =0;
int CA_distance =0;
int CA_threshold =50;
enum CA CA_state_id;
void (*CA_state)();

STATE_define(CA_Waiting)
{
	/* state name */
	CA_state_id = CA_waiting;
	printf("CA_waiting state: distance =%d  speed=%d \n",CA_distance,CA_speed);

	/* state action */
	CA_speed = 0;
	DC_motor(CA_speed);
}

STATE_define(CA_Driving)
{
	/* state name */
	CA_state_id = CA_driving;
	printf("CA_driving state: distance =%d  speed=%d \n",CA_distance,CA_speed);

	/* state action */
	CA_speed = 30;
	DC_motor(CA_speed);


}

extern void US_distance_set(int d)
{
	CA_distance = d;
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_Waiting)) : (CA_state = STATE(CA_Driving));
	printf("US-------distance=%d---------> CA\n",CA_distance);
}

