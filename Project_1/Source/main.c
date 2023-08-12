
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "driver.h"
#include "Pressure_Sensor_Driver.h"
#include "Alarm_Manager.h"
#include "Alarm_Driver.h"


void setup()
{
	/* init all the drivers */
	/* IRQ */
	/* init HAL US driver DC driver */
	/* init BLOCK */
	PS_init();
	AD_init();
	/* Set States pointers for each block */
	PS_state = STATE(PS_reading);
	AM_state = STATE(Alarm_waiting);
	AD_state = STATE(Alarm_off);
}

void set_Pressure_Val(int Pressure_Value)
{
	if (Pressure_Value > 20)
	{
		High_Pressure_Detected();
	} 
}

int main()
{
	GPIO_INITIALIZATION ();
	setup();
	while (1)
	{
		/* call state for each block */
		PS_state();
		AM_state();
		AD_state();
		AM_state();
		AD_state();
		
	}
	return 0;

}


