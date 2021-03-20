#ifndef OS_H_INCLUDED
#define OS_H_INCLUDED

#define OS_TICK_MS                          10UL

void OS_Init(void);

void OS_ScheduleAndDispatch(void);

void __interrupt() OS_TickUpdate(void);

#endif // OS_H_INCLUDED
