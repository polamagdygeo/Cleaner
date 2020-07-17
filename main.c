// PIC16F877A Configuration Bit Settings
// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include "Main.h"
#include "OS.h"
#include "Display.h"
#include "Time.h"
#include "Motor.h"
#include "VC.h"
#include "LED.h"
#include "Button.h"
#include "SSD.h"
#include "Timer.h"

int main(void)
{
    u16 time;
    LED_Init(LED_DUST_INDICATOR,LED_OFF);

    SSD_Init(SSD_LEFT,SSD_NO_DASH);
    SSD_Init(SSD_CENTER,SSD_NO_DASH);
    SSD_Init(SSD_RIGHT,SSD_NO_DASH);

    Display_Init();

    Motor_Init(MOTOR_ANGLE_140);

    Button_Init(BUTTON_PLUS);
    Button_Init(BUTTON_MINUS);
    Button_Init(BUTTON_DUST);

    VC_Init();

    TIME_Init();

    OS_Init();
    while(1)
    {
        OS_Schedule();
    }

    return 0;
}
