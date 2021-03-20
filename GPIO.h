#ifndef GPIO_H_INCLUDED
#define GPIO_H_INCLUDED

#include "Main.h"

typedef enum{
    GPIO_PORTA,
    GPIO_PORTB,
    GPIO_PORTC,
    GPIO_PORTD,
    GPIO_PORTE
}tGPIO_Port;

typedef enum{
    GPIO_PIN0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7
}tGPIO_Pin;

typedef enum{
    GPIO_OUTPUT_DIR,
    GPIO_INPUT_DIR
}tGPIO_Dir;

typedef enum{
    GPIO_LOW,
    GPIO_HIGH
}tGPIO_State;

void GPIO_InitPin(tGPIO_Port port,tGPIO_Pin pin,tGPIO_Dir dir);
void GPIO_InitPort(tGPIO_Port port,u8 mask,tGPIO_Dir dir);
tGPIO_State GPIO_GetPinState(tGPIO_Port port,tGPIO_Pin pin);
void GPIO_SetPinState(tGPIO_Port port,tGPIO_Pin pin,tGPIO_State state);
void GPIO_SetPortState(tGPIO_Port port,u8 mask,tGPIO_State state);
void GPIO_TogglePinState(tGPIO_Port port,tGPIO_Pin pin);

#endif // GPIO_H_INCLUDED
