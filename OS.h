#ifndef OS_H_INCLUDED
#define OS_H_INCLUDED

#define OS_TICK_MS                          10

void OS_Init(void);

void OS_Schedule(void);

void __interrupt() OS_Update(void);

#endif // OS_H_INCLUDED
