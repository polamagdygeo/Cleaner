#include "Timer.h"
#include "LED.h"

void Timer_SetMode(tTimer timer,tTimer_Mode mode)
{
    switch(timer)
    {
        case TIMER0:
            TIMER0_SET_MODE(mode);
        break;
        case TIMER1:
            TIMER1_SET_MODE(mode);
        break;
    }
}

void Timer_SetInterruptEn(tTimer timer,u8 state)
{
    switch(timer)
    {
        case TIMER0:
            TIMER0_SET_INTERRUPT_EN(state);
        break;
        case TIMER1:
            TIMER1_SET_INTERRUPT_EN(state);
        break;
    }
}

void Timer_Init(tTimer timer)
{
    switch(timer)
    {
        case TIMER0:
            TIMER0_SET_PRESCALER();
        break;
        case TIMER1:
            TIMER1_SET_PRESCALER();
        break;
    }
    Timer_SetMode(timer,TIMER_MODE);
}

void Timer_SetTimeMS(tTimer timer,u16 time)
{
    u16 count_no;
    switch(timer)
    {
        case TIMER0:
            count_no=(time*(2000))/(256);
            TIMER0_SET_COUNT(0xff-count_no);
        break;
        case TIMER1:
            count_no=(time*(250));
            TIMER1_SET_COUNT(0xffff-count_no);
        break;
    }
}

void Timer_SetTimeUS(tTimer timer,u16 time)
{
    u16 count_no;
    switch(timer)
    {
        case TIMER0:
            count_no=(time)/(4*32);
            TIMER0_SET_COUNT(0xff-count_no);
        break;
        case TIMER1:
            count_no=(time)/(4);
            TIMER1_SET_COUNT(0xffff-count_no);
    }
}

void Timer_ClearInterruptFlag(tTimer timer)
{
    switch(timer)
    {
        case TIMER0:
            TIMER0_CLEAR_FLAG();
        break;
         case TIMER1:
            TIMER1_CLEAR_FLAG();
        break;
    }
}
u8 Timer_CheckInterruptFlag(tTimer timer)
{
    u8 flag_state=0;
     switch(timer)
    {
        case TIMER0:
            flag_state=TIMER0_CHECK_FLAG();
        break;
         case TIMER1:
            flag_state=TIMER1_CHECK_FLAG();
        break;
    }
    return flag_state;
}


void Timer_SetState(tTimer timer,u8 state)
{
    switch(timer)
    {
        case TIMER0:

        break;
        case TIMER1:
            TIMER1_SET_STATE(state);
        break;
    }
}
