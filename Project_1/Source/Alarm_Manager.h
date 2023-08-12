#ifndef _Alarm_Manager_H_
#define _Alarm_Manager_H_

#include "state.h"

enum AM{
	HighP_Detected,
	Alarm_On,
	Alarm_waiting,
	Alarm_Off
};

/*global pointer to function */
extern void (*AM_state)();

STATE_define(Alarm_On);
STATE_define(Alarm_waiting);
STATE_define(Alarm_Off);



#endif