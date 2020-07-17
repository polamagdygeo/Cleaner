#ifndef LED_H_INCLUDED
#define LED_H_INCLUDED

typedef enum{
    LED_DUST_INDICATOR
}tLED;

typedef enum{
    LED_OFF,
    LED_ON
}tLED_State;

void LED_Init(tLED led,tLED_State inital_state);
void LED_SetState(tLED led,tLED_State state);

#endif // LED_H_INCLUDED
