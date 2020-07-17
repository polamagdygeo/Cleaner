#include "GPIO.h"

void GPIO_InitPort(tGPIO_Port port,u8 mask,tGPIO_Dir dir)
{
    switch(port)
    {
        case GPIO_PORTA:
            GPIO_PORT_DIR_SET(GPIO_PORTA_DIR_REG,mask,dir);
        break;
        case GPIO_PORTB:
            GPIO_PORT_DIR_SET(GPIO_PORTB_DIR_REG,mask,dir);
        break;
        case GPIO_PORTC:
            GPIO_PORT_DIR_SET(GPIO_PORTC_DIR_REG,mask,dir);
        break;
        case GPIO_PORTD:
            GPIO_PORT_DIR_SET(GPIO_PORTD_DIR_REG,mask,dir);
        break;
        case GPIO_PORTE:
            GPIO_PORT_DIR_SET(GPIO_PORTE_DIR_REG,mask,dir);
        break;
        default:
        break;
    }
}

void GPIO_InitPin(tGPIO_Port port,tGPIO_Pin pin,tGPIO_Dir dir)
{
    switch(port)
    {
        case GPIO_PORTA:
            GPIO_PIN_DIR_SET(GPIO_PORTA_DIR_REG,pin,dir);
        break;
        case GPIO_PORTB:
            GPIO_PIN_DIR_SET(GPIO_PORTB_DIR_REG,pin,dir);
        break;
        case GPIO_PORTC:
            GPIO_PIN_DIR_SET(GPIO_PORTC_DIR_REG,pin,dir);
        break;
        case GPIO_PORTD:
            GPIO_PIN_DIR_SET(GPIO_PORTD_DIR_REG,pin,dir);
        break;
        case GPIO_PORTE:
            GPIO_PIN_DIR_SET(GPIO_PORTE_DIR_REG,pin,dir);
        break;
        default:
        break;
    }
}

tGPIO_State GPIO_GetPinState(tGPIO_Port port,tGPIO_Pin pin)
{
    tGPIO_State state;

    switch(port)
    {
        case GPIO_PORTA:
            state=GPIO_PIN_READ(GPIO_PORTA_DATA_REG,pin);
        break;
        case GPIO_PORTB:
            state=GPIO_PIN_READ(GPIO_PORTB_DATA_REG,pin);
        break;
        case GPIO_PORTC:
            state=GPIO_PIN_READ(GPIO_PORTC_DATA_REG,pin);
        break;
        case GPIO_PORTD:
            state=GPIO_PIN_READ(GPIO_PORTD_DATA_REG,pin);
        break;
        case GPIO_PORTE:
            state=GPIO_PIN_READ(GPIO_PORTE_DATA_REG,pin);
        break;
        default:
        break;
    }
    return state;
}

void GPIO_SetPortState(tGPIO_Port port,u8 mask,tGPIO_State state)
{
    switch(port)
    {
        case GPIO_PORTA:
            GPIO_PORT_DIR_SET(GPIO_PORTA_DATA_REG,mask,state);
        break;
        case GPIO_PORTB:
            GPIO_PORT_DIR_SET(GPIO_PORTB_DATA_REG,mask,state);
        break;
        case GPIO_PORTC:
            GPIO_PORT_DIR_SET(GPIO_PORTC_DATA_REG,mask,state);
        break;
        case GPIO_PORTD:
            GPIO_PORT_DIR_SET(GPIO_PORTD_DATA_REG,mask,state);
        break;
        case GPIO_PORTE:
            GPIO_PORT_DIR_SET(GPIO_PORTE_DATA_REG,mask,state);
        break;
        default:
        break;
    }
}

void GPIO_SetPinState(tGPIO_Port port,tGPIO_Pin pin,tGPIO_State state)
{
    switch(port)
    {
        case GPIO_PORTA:
            GPIO_PIN_DIR_SET(GPIO_PORTA_DATA_REG,pin,state);
        break;
        case GPIO_PORTB:
            GPIO_PIN_DIR_SET(GPIO_PORTB_DATA_REG,pin,state);
        break;
        case GPIO_PORTC:
            GPIO_PIN_DIR_SET(GPIO_PORTC_DATA_REG,pin,state);
        break;
        case GPIO_PORTD:
            GPIO_PIN_DIR_SET(GPIO_PORTD_DATA_REG,pin,state);
        break;
        case GPIO_PORTE:
            GPIO_PIN_DIR_SET(GPIO_PORTE_DATA_REG,pin,state);
        break;
        default:
        break;
    }
}

void GPIO_TogglePinState(tGPIO_Port port,tGPIO_Pin pin)
{
    tGPIO_State current_pin_state=GPIO_GetPinState(port,pin);
    GPIO_SetPinState(port,pin,~current_pin_state);
}


