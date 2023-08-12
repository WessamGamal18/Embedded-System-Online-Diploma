#include "Pressure_Sensor_Driver.h"
#include "driver.h"

enum PS PS_state_id;
void (*PS_state)();

int PS_Pval =0;


void PS_init()
{
	// init PS sensor
	// Call the PS driver or functions
}


STATE_define(PS_reading)
{
	/* state action */
	PS_state_id = PS_reading;
	/* read from the PS */
	PS_Pval = getPressureVal();

	set_Pressure_Val(PS_Pval);
	PS_state = STATE(PS_waiting);
}

STATE_define(PS_waiting)
{
	// in this state wait untill Sensor pull timer finished then return to reading state
	Delay(1000000);
	PS_state = STATE(PS_reading);
	PS_state();

}

