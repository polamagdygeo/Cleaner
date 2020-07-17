#ifndef _TIME_H_
#define _TIME_H_

#include "Main.h"


void TIME_Init(void);
void TIME_TriggerTimeSandwichUS(u16 delay_us);
void TIME_WaitTimeSandwich(void);
void TIME_TriggerDelayUS(u16 delay_us);



#endif
