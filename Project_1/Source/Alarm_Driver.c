#include "Alarm_Driver.h"
#include <time.h>
void (*AD_state)();

void AD_init()
{
	// init Alarm driver
	// Call the alarm driver or functions
}


void Start_Alarm()
{
	// turn on alarm
	Set_Alarm_actuator(0);
}
void Stop_Alarm()
{
	// turn off alarm
	Set_Alarm_actuator(1);

}
STATE_define(Alarm_on)
{
	Start_Alarm();
	// wait 60 seconds (example)
	Delay(10000000);
	AD_state = STATE(Alarm_on);
}

STATE_define(Alarm_off)
{
	Stop_Alarm();
	AD_state = STATE(Alarm_off);
}
