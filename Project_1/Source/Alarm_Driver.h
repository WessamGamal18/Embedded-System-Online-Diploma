#ifndef _Alarm_Driver_H_
#define _Alarm_Driver_H_
#include "state.h"

void AD_init();

enum AD{
	Alarm_on,
	Alarm_off
};

/*global pointer to function */
extern void (*AD_state)();

STATE_define(Alarm_on);
STATE_define(Alarm_off);



#endif