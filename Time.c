/*
 * File:   Time.c
 * Author: Pola
 *
 * Created on 17 ????, 2019, 12:33 ?
 */

#include "Time.h"
#include "Timer.h"

void TIME_Init(void)
{
    Timer_Init(TIMER1);
}

void TIME_TriggerTimeSandwichUS(u16 delay_us)
{
    Timer_SetTimeUS(TIMER1,delay_us);
    Timer_ClearInterruptFlag(TIMER1);
    Timer_SetState(TIMER1,1);
}

void TIME_WaitTimeSandwich(void)
{
    while(Timer_CheckInterruptFlag(TIMER1)==0);
    Timer_ClearInterruptFlag(TIMER1);
    Timer_SetState(TIMER1,0);
}

void TIME_TriggerDelayUS(u16 delay_us)
{
    TIME_TriggerTimeSandwichUS(delay_us);
    TIME_WaitTimeSandwich();
}
