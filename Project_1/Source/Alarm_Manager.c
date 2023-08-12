#include "Alarm_Manager.h"
#include "Alarm_Driver.h"


void (*AM_state)();

void High_Pressure_Detected()
{
	// high pressure detected
	// set global pointer to alarm on state
	AM_state = STATE(Alarm_On);
	
}

STATE_define(Alarm_On)
{
	// start alarm on the actuator
	AD_state = STATE(Alarm_on);
	AM_state = STATE(Alarm_waiting);
}

STATE_define(Alarm_waiting)
{
	// using delay function in driver
	AM_state = STATE(Alarm_Off);
	AM_state();
}

STATE_define(Alarm_Off)
{
	// stop alarm on the actuator
	AD_state = STATE(Alarm_off);
	AM_state = STATE(Alarm_waiting);
}