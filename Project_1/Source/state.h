#ifndef STATE_H_
#define STATE_H_

#define STATE_define(_stateFunc_) void ST_##_stateFunc_()
#define STATE(_stateFunc_) ST_##_stateFunc_

#include<stdio.h>
#include<stdlib.h>

/*states Connection*/

void set_Pressure_Val(int d);
void High_Pressure_Detected();
void Start_Alarm();
void Stop_Alarm();



#endif /* STATE_H_ */
