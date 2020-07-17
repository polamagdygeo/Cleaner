#ifndef PORT_H_INCLUDED
#define PORT_H_INCLUDED

#include "GPIO.h"

/********************************************************************
*   LED
********************************************************************/

#define LED_DUST_INDICATOR_PORT                      GPIO_PORTB
#define LED_DUST_INDICATOR_PIN                       GPIO_PIN0

/********************************************************************
*   BUTTON
********************************************************************/

#define BUTTON_PLUS_PORT                             GPIO_PORTB
#define BUTTON_PLUS_PIN                              GPIO_PIN1

#define BUTTON_MINUS_PORT                            GPIO_PORTB
#define BUTTON_MINUS_PIN                             GPIO_PIN2

#define BUTTON_DUST_PORT                              GPIO_PORTB
#define BUTTON_DUST_PIN                               GPIO_PIN3


/********************************************************************
*   SSD
********************************************************************/

#define SSD_PORT                                       GPIO_PORTD
#define SSD_PINS_MASK                                   0x7f          /*excluding DOT*/
#define SSD_DOT_PIN                                      GPIO_PIN7

#define SSD_LEFT_CTRL_PORT                              GPIO_PORTB
#define SSD_LEFT_CTRL_PIN                               GPIO_PIN6

#define SSD_CENTER_CTRL_PORT                            GPIO_PORTB
#define SSD_CENTER_CTRL_PIN                             GPIO_PIN5

#define SSD_RIGHT_CTRL_PORT                             GPIO_PORTB
#define SSD_RIGHT_CTRL_PIN                              GPIO_PIN4

/********************************************************************
*   Motor
********************************************************************/
#define MOTOR_PORT                                      GPIO_PORTC
#define MOTOR_PIN                                       GPIO_PIN0


#endif // PORT_H_INCLUDED
