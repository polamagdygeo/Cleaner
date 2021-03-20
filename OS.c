#include "OS.h"
#include "Timer.h"
#include "Button.h"
#include "SSD.h"
#include "Display.h"
#include "VC.h"
#include "Motor.h"
#include "GPIO.h"
#include "Time.h"


static volatile u8 tick_flag = 0;

void OS_ScheduleAndDispatch(void)
{
    static u8 Button_Counter = 0;
    static u8 Display_Counter = 0;
    static u8 VC_Counter = 0;
    static u8 Motor_SoftSwitch_Counter = 0;
    static u8 Motor_HarmonicReduction_Counter = 0;


    if(tick_flag == 1)
    {
        tick_flag = 0;
        
        /*Debug pin*/
        GPIO_TogglePinState(GPIO_PORTC,GPIO_PIN1);

        Button_Counter += OS_TICK_MS;
        Display_Counter += OS_TICK_MS;
        VC_Counter += OS_TICK_MS;
        Motor_SoftSwitch_Counter += OS_TICK_MS;
        Motor_HarmonicReduction_Counter += OS_TICK_MS;
        
        TIME_TriggerTimeSandwichUS(550);

        /*Execution time : 315 us*/
        SSD_Update();
        
        if(VC_Counter == VC_PERIOD_MS)
        {
            VC_Counter = 0;
            /*Execution time : 110 us*/
            VC_Update();
        }
        
        if(Display_Counter == DISPLAY_PERIOD_MS)
        {
            Display_Counter = 0;
            /*Execution time : 100 us*/
            Display_Update();
        }
        
        TIME_WaitTimeSandwich();

        /*Execution time : 9300 us*/
        Motor_OutputUpdate();
        
        if(Motor_SoftSwitch_Counter == MOTOR_SOFTSWITCH_PERIOD_MS)
        {
            Motor_SoftSwitch_Counter = 0;
            /*Execution time : 10 us*/
            Motor_SoftSwitchingUpdate();
        }

        if(Motor_HarmonicReduction_Counter == MOTOR_HARMONIC_PERIOD_MS)
        {
            Motor_HarmonicReduction_Counter = 0;
            /*Execution time : 10 us*/
            Motor_HarmonicReductionUpdate();
        }
        
        if(Button_Counter == BUTTON_PERIOD_MS)
        {
            Button_Counter = 0;
            /*Execution time : 165 us*/
            Button_Update();
        }
    }
}

void __interrupt() OS_TickUpdate(void)
{
    Timer_ClearInterruptFlag(TIMER0);
    Timer_SetTimeMS(TIMER0,OS_TICK_MS);
    tick_flag = 1;
}

void OS_Init(void)
{
    Timer_Init(TIMER0);
    Timer_SetTimeMS(TIMER0,OS_TICK_MS);
    Timer_SetInterruptEn(TIMER0,1);
    INTERRUPT_SET_PERIPHERAL_EN(1);
    INTERRUPT_SET_GLOBAL_EN(1);
    Timer_SetState(TIMER0,1);

    /*Debug pin*/
    GPIO_InitPin(GPIO_PORTC,GPIO_PIN1,GPIO_OUTPUT_DIR);
}
