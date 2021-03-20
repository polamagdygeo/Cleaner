#ifndef TIMER_H_INCLUDED
#define TIMER_H_INCLUDED

#include "Main.h"

typedef enum{
    TIMER0,
    TIMER1,
    TIMER2
}tTimer;

typedef enum{
    TIMER_MODE,
    COUNTER_MODE
}tTimer_Mode;

void Timer_Init(tTimer timer);
void Timer_SetMode(tTimer timer,tTimer_Mode mode);
void Timer_SetTimeMS(tTimer timer,u16 time);
void Timer_SetTimeUS(tTimer timer,u16 time);
void Timer_SetInterruptEn(tTimer timer,u8 state);
void Timer_ClearInterruptFlag(tTimer timer);
u8 Timer_CheckInterruptFlag(tTimer timer);
void Timer_SetState(tTimer timer,u8 state);

#endif // TIMER_H_INCLUDED
