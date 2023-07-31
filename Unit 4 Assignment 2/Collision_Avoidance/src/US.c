/*
 * US_sensor.c
 *
 *  Created on: Jul 29, 2023
 *      Author: Ahmed & Wessam
 */

#include "US.h"

int US_distance =0;
enum US US_state_id;
int generate_random();
void (*US_state)();

/* Module Variables */

int generate_random(int l,int r,int count)
{
	int i,rand_num=0;
	for(i=0; i<count; i++)
	{
		rand_num = (rand() % (r-l+1)) +l;
		return rand_num;
	}
}

void US_init ()
{
	/* init US sensot*/
	/* Call the US driver or functions*/
	printf("UC_init\n");
}
STATE_define(US_Busy)
{
	/* state action */
	US_state_id = US_busy;
	/* read from the US */
	US_distance = generate_random(45,55,1);
	/* print distance */
	printf("US_busy state : distance : %d \n",US_distance);

	US_distance_set(US_distance);
	US_state = STATE(US_Busy);
}
