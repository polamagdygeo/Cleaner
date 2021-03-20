#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "Main.h"

#define BUTTON_PERIOD_MS                    20UL

typedef enum{
    BUTTON_PLUS,
    BUTTON_MINUS,
    BUTTON_DUST,
    BUTTON_COUNT
}tButton;

typedef enum{
    BUTTON_RELEASED,
    BUTTON_PRE_PRESSED,
    BUTTON_PRESSED,
    BUTTON_PRE_RELEASED
}tButton_State;

void Button_Init(tButton button);
tButton_State Button_GetState(tButton button);
u16 Button_GetPressingTime(tButton button);
void Button_Update(void);

#endif // BUTTON_H_INCLUDED
