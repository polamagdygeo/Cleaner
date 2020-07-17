#include "Button.h"
#include "GPIO.h"
#include "Port.h"

static tButton_State ButtonState[3]={BUTTON_RELEASED,
                                     BUTTON_RELEASED,
                                     BUTTON_RELEASED};

static tGPIO_State  ButtonPrevSample[3];

static u16 Dust_Button_Pressing_Time=BUTTON_PERIOD_MS;

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
    return ButtonState[button];
}

u16 Button_GetPressingTime(tButton button)
{
    u16 ret_val;
    switch(button)
    {
        case BUTTON_DUST:
            ret_val=Dust_Button_Pressing_Time;
        break;
    }
    return ret_val;
}

static void Button_Plus_Update(void)
{
    tGPIO_State ButtonCurrSample;

    ButtonCurrSample=GPIO_GetPinState(BUTTON_PLUS_PORT,BUTTON_PLUS_PIN);

    switch(ButtonState[BUTTON_PLUS])
    {
        case BUTTON_RELEASED:
            if((ButtonCurrSample== GPIO_LOW) && (ButtonPrevSample[BUTTON_PLUS]== GPIO_LOW))
            {
                ButtonState[BUTTON_PLUS]=BUTTON_PRE_PRESSED;
            }
        break;

        case BUTTON_PRE_PRESSED:
            if(ButtonCurrSample== GPIO_LOW)
            {
                ButtonState[BUTTON_PLUS]=BUTTON_PRESSED;
            }
        break;

        case BUTTON_PRESSED:
            if((ButtonCurrSample == GPIO_HIGH) && (ButtonPrevSample[BUTTON_PLUS]== GPIO_HIGH))
            {
                ButtonState[BUTTON_PLUS]=BUTTON_PRE_RELEASED;
            }
        break;

        case BUTTON_PRE_RELEASED:
            if(ButtonCurrSample == GPIO_HIGH)
            {
                ButtonState[BUTTON_PLUS]=BUTTON_RELEASED;
            }
        break;
    }

    ButtonPrevSample[BUTTON_PLUS]=ButtonCurrSample;
}

static void Button_Minus_Update(void)
{
    tGPIO_State ButtonCurrSample;

    ButtonCurrSample=GPIO_GetPinState(BUTTON_MINUS_PORT,BUTTON_MINUS_PIN);

    switch(ButtonState[BUTTON_MINUS])
    {
        case BUTTON_RELEASED:
            if((ButtonCurrSample== GPIO_LOW)&& (ButtonPrevSample[BUTTON_MINUS]== GPIO_LOW))
            {
                ButtonState[BUTTON_MINUS]=BUTTON_PRE_PRESSED;
            }
        break;

        case BUTTON_PRE_PRESSED:
            if(ButtonCurrSample== GPIO_LOW)
            {
                ButtonState[BUTTON_MINUS]=BUTTON_PRESSED;
            }
        break;

        case BUTTON_PRESSED:
            if((ButtonCurrSample == GPIO_HIGH) && (ButtonPrevSample[BUTTON_MINUS]== GPIO_HIGH))
            {
                ButtonState[BUTTON_MINUS]=BUTTON_PRE_RELEASED;
            }
        break;

        case BUTTON_PRE_RELEASED:
            if(ButtonCurrSample == GPIO_HIGH)
            {
                ButtonState[BUTTON_MINUS]=BUTTON_RELEASED;
            }
        break;
    }

    ButtonPrevSample[BUTTON_MINUS]=ButtonCurrSample;
}

static void Button_Dust_Update(void)
{
    tGPIO_State ButtonCurrSample;

    ButtonCurrSample=GPIO_GetPinState(BUTTON_DUST_PORT,BUTTON_DUST_PIN);

    switch(ButtonState[BUTTON_DUST])
    {
        case BUTTON_RELEASED:
            if((ButtonCurrSample== GPIO_LOW)&& (ButtonPrevSample[BUTTON_DUST]== GPIO_LOW))
            {
                ButtonState[BUTTON_DUST]=BUTTON_PRE_PRESSED;
            }
        break;

        case BUTTON_PRE_PRESSED:
            if(ButtonCurrSample== GPIO_LOW)
            {
                ButtonState[BUTTON_DUST]=BUTTON_PRESSED;
            }
        break;

        case BUTTON_PRESSED:
            if((ButtonCurrSample == GPIO_HIGH) && (ButtonPrevSample[BUTTON_DUST]== GPIO_HIGH))
            {
                ButtonState[BUTTON_DUST]=BUTTON_PRE_RELEASED;
                Dust_Button_Pressing_Time=BUTTON_PERIOD_MS;
            }

            if(Dust_Button_Pressing_Time<65535)
            {
                Dust_Button_Pressing_Time+=BUTTON_PERIOD_MS;
            }

        break;

        case BUTTON_PRE_RELEASED:
            if(ButtonCurrSample == GPIO_HIGH)
            {
                ButtonState[BUTTON_DUST]=BUTTON_RELEASED;
            }
        break;
    }

    ButtonPrevSample[BUTTON_DUST]=ButtonCurrSample;
}

void Button_Update(void)
{
    Button_Plus_Update();
    Button_Minus_Update();
    Button_Dust_Update();
}


