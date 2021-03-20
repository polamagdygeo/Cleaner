#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <pic16f877a.h>

#define F_OSC   8000000ul

/*Standard types redefinitions*/
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u16;
typedef signed int s16;
typedef unsigned long u32;
typedef signed long s32;

/********************************************************************
*   Interrupt
********************************************************************/

#define INTERRUPT_SET_GLOBAL_EN(STATE)              (GIE = STATE)
#define INTERRUPT_SET_PERIPHERAL_EN(STATE)          (PEIE = STATE)

/********************************************************************
*   GPIO
********************************************************************/

/*IO Ports registers redefinition*/
#define GPIO_PORTA_DIR_REG                          TRISA
#define GPIO_PORTB_DIR_REG                          TRISB
#define GPIO_PORTC_DIR_REG                          TRISC
#define GPIO_PORTD_DIR_REG                          TRISD
#define GPIO_PORTE_DIR_REG                          TRISE

#define GPIO_PORTA_DATA_REG                         PORTA
#define GPIO_PORTB_DATA_REG                         PORTB
#define GPIO_PORTC_DATA_REG                         PORTC
#define GPIO_PORTD_DATA_REG                         PORTD
#define GPIO_PORTE_DATA_REG                         PORTE

/*IO Ports Operation*/
#define GPIO_PIN_DIR_SET(PORT_DIR_REG,PIN,DIR)      (PORT_DIR_REG = (((PORT_DIR_REG) & (~(1<<(PIN)))) | ((DIR)<<(PIN))))
#define GPIO_PORT_DIR_SET(PORT_DIR_REG,MASK,DIR)    (PORT_DIR_REG = (((PORT_DIR_REG) & (~(MASK))) | ((DIR)&(MASK))))

#define GPIO_PIN_WRITE(PORT_DATA_REG,PIN,VAL)       (PORT_DATA_REG = (((PORT_DATA_REG) & (~(1<<(PIN)))) | ((VAL)<<(PIN))))
#define GPIO_PORT_WRITE(PORT_DATA_REG,MASK,VAL)     (PORT_DATA_REG = (((PORT_DATA_REG) & (~(MASK))) | ((VAL)&(MASK))))

#define GPIO_PIN_READ(PORT_DATA_REG,PIN)            (((PORT_DATA_REG) & (1<<(PIN))) >> (PIN))
#define GPIO_PORT_READ(PORT_DATA_REG,MASK)          ((PORT_DATA_REG) & (MASK))

/********************************************************************
*   Timer
********************************************************************/
/*Timer0 Operations*/
#define TIMER0_SET_PRESCALER()                      PS0 = 1;\
                                                    PS1 = 1;\
                                                    PS2 = 1;\
                                                    PSA = 0
#define TIMER0_CLEAR_FLAG()                         (TMR0IF = 0)
#define TIMER0_CHECK_FLAG()                         (TMR0IF)
#define TIMER0_SET_MODE(MODE)                       (T0CS = MODE)
#define TIMER0_SET_INTERRUPT_EN(STATE)              (TMR0IE = STATE)
#define TIMER0_SET_COUNT(COUNT)                     (TMR0 = (COUNT))
#define TIMER0_GET_COUNT()                          (TMR0)

/*Timer1 Operations*/
#define TIMER1_SET_STATE(STATE)                     (TMR1ON = STATE)
#define TIMER1_SET_PRESCALER()                      T1CKPS0 = 1;\
                                                    T1CKPS1 = 1
#define TIMER1_CLEAR_FLAG()                         (TMR1IF = 0)
#define TIMER1_CHECK_FLAG()                         (TMR1IF)
#define TIMER1_SET_MODE(MODE)                       (TMR1CS = MODE)
#define TIMER1_SET_INTERRUPT_EN(STATE)              (TMR1IE = STATE)
#define TIMER1_SET_COUNT(COUNT)                     (TMR1H = ((COUNT) & 0xff00) >> 8);\
                                                    (TMR1L = ((COUNT) & 0x00ff))
#define TIMER1_GET_COUNT()                           ((((TMR1H) & 0xff00) >> 8) | ((TMR1L) & 0x00ff))



#endif // MAIN_H_INCLUDED
