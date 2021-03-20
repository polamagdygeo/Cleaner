#include "Button.h"
#include "GPIO.h"
#include "Port.h"

static tButton_State button_current_state[BUTTON_COUNT] = {BUTTON_RELEASED,
                                     BUTTON_RELEASED,
                                     BUTTON_RELEASED};

static tGPIO_State button_previous_sample[BUTTON_COUNT];

static u16 button_pressing_time[BUTTON_COUNT] = BUTTON_PERIOD_MS;

void Button_Init(tButton button)
{
    switch(button)
    {
        case BUTTON_PLUS:
            GPIO_InitPin(BUTTON_PLUS_PORT,BUTTON_PLUS_PIN,GPIO_INPUT_DIR);
        break;

        case BUTTON_MINUS:
            GPIO_InitPin(BUTTON_MINUS_PORT,BUTTON_MINUS_PIN,GPIO_INPUT_DIR);
        break;

         case BUTTON_DUST:
            GPIO_InitPin(BUTTON_DUST_PORT,BUTTON_DUST_PIN,GPIO_INPUT_DIR);
        break;
    }
}

tButton_State Button_GetState(tButton button)
{
    return button_current_state[button];
}

u16 Button_GetPressingTime(tButton button)
{
    return dust_button_pressing_time[button];
}

void Button_Update(void)
{
    tButton button_itr;

    for(button_itr = BUTTON_PLUS ;button_itr < BUTTON_COUNT ; button_itr++)
    {
        tGPIO_State ButtonCurrSample;

        switch(button_itr)
        {
            case BUTTON_PLUS:
                ButtonCurrSample = GPIO_GetPinState(BUTTON_PLUS_PORT,BUTTON_PLUS_PIN);
            break;

            case BUTTON_MINUS:
                ButtonCurrSample = GPIO_GetPinState(BUTTON_MINUS_PORT,BUTTON_MINUS_PIN);
            break;

            case BUTTON_DUST:
                ButtonCurrSample = GPIO_GetPinState(BUTTON_DUST_PORT,BUTTON_DUST_PIN);
            break;
        }

        switch(button_current_state[button_itr])
        {
            case BUTTON_RELEASED:
                if((ButtonCurrSample == GPIO_LOW) && 
                (button_previous_sample[button_itr] == GPIO_LOW))
                {
                    button_current_state[button_itr] = BUTTON_PRE_PRESSED;
                }
            break;

            case BUTTON_PRE_PRESSED:
                if(ButtonCurrSample == GPIO_LOW)
                {
                    button_current_state[button_itr] = BUTTON_PRESSED;
                }
            break;

            case BUTTON_PRESSED:
                if((ButtonCurrSample == GPIO_HIGH) && 
                (button_previous_sample[button_itr] == GPIO_HIGH))
                {
                    button_current_state[button_itr] = BUTTON_PRE_RELEASED;
                    button_pressing_time[button_itr] = BUTTON_PERIOD_MS;
                }

                if(button_pressing_time[button_itr] < 65535)
                {
                    button_pressing_time[button_itr] += BUTTON_PERIOD_MS;
                }

            break;

            case BUTTON_PRE_RELEASED:
                if(ButtonCurrSample == GPIO_HIGH)
                {
                    button_current_state[button_itr] = BUTTON_RELEASED;
                }
            break;
        }

        button_previous_sample[button_itr] = ButtonCurrSample;
    }
}


