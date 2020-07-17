
#include "LED.h"
#include "Port.h"
#include "GPIO.h"

void LED_Init(tLED led,tLED_State inital_state)
{
    switch(led)
    {
        case LED_DUST_INDICATOR:
            GPIO_InitPin(LED_DUST_INDICATOR_PORT,LED_DUST_INDICATOR_PIN,GPIO_OUTPUT_DIR);
            GPIO_SetPinState(LED_DUST_INDICATOR_PORT,LED_DUST_INDICATOR_PIN,inital_state);
        break;
    }
}

void LED_SetState(tLED led,tLED_State state)
{
    switch(led)
    {
        case LED_DUST_INDICATOR:
            GPIO_SetPinState(LED_DUST_INDICATOR_PORT,LED_DUST_INDICATOR_PIN,state);
        break;
    }
}
