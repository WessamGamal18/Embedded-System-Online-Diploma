#ifndef _Pressure_Sensor_Driver_H_
#define _Pressure_Sensor_Driver_H_

#include "state.h"

enum PS{
	PS_reading,
	PS_waiting
};
void PS_init();


/*global pointer to function */
extern void (*PS_state)();

STATE_define(PS_reading);
STATE_define(PS_waiting);



#endif