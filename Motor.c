#include "Motor.h"
#include "GPIO.h"
#include "Port.h"
#include "Time.h"
#include "Timer.h"

typedef enum{
    MOTOR_SOFT_SWITCHING,
    MOTOR_HARMONIC_REDUCTION
}tMotor_State;

static tMotor_State Current_Motor_State=MOTOR_SOFT_SWITCHING;

static tMotor_TargetAngle Target_Angle;
static u8 Actual_Angle=MOTOR_ANGLE_170;
static u8 Harmonic_Angle;
static u8 OutputAngle=MOTOR_ANGLE_170;

void Motor_SetTargetAngle(tMotor_TargetAngle target_angle)
{
    Target_Angle=target_angle;
}

void Motor_Init(tMotor_TargetAngle initial_target_angle)
{
    GPIO_InitPin(MOTOR_PORT,MOTOR_PIN,GPIO_OUTPUT_DIR);

    GPIO_SetPinState(MOTOR_PORT,MOTOR_PIN,GPIO_LOW);

    Motor_SetTargetAngle(initial_target_angle);
}
void Motor_SoftSwitchingUpdate(void)
{
    if(Current_Motor_State == MOTOR_SOFT_SWITCHING)
    {
        if(Actual_Angle == Target_Angle)
        {
            Current_Motor_State=MOTOR_HARMONIC_REDUCTION;
            Harmonic_Angle=Actual_Angle+HARMONIC_REDUCTION_DELTA;
        }
        else
        {
            if(Actual_Angle > Target_Angle)
            {
                Actual_Angle--;
            }
            else
            {
                Actual_Angle++;
            }

             OutputAngle=Actual_Angle;
        }

    }

}

void Motor_HarmonicReductionUpdate(void)
{
    if(Current_Motor_State == MOTOR_HARMONIC_REDUCTION)
    {
        if(Actual_Angle != Target_Angle)
        {
            Current_Motor_State=MOTOR_SOFT_SWITCHING;
        }
        else if(Target_Angle-HARMONIC_REDUCTION_DELTA >= 10 &&
                Target_Angle+HARMONIC_REDUCTION_DELTA <= 170)
        {
            if(Harmonic_Angle > Target_Angle)
            {
                Harmonic_Angle-=HARMONIC_REDUCTION_DELTA*2;
            }
            else if(Harmonic_Angle < Target_Angle)
            {
                Harmonic_Angle+=HARMONIC_REDUCTION_DELTA*2;
            }

            OutputAngle=Harmonic_Angle;
        }
    }
}

void Motor_OutputUpdate(void)
{
    u16 Bias_Time_US=(55*(OutputAngle-10));

    TIME_TriggerDelayUS(Bias_Time_US);

    GPIO_SetPinState(MOTOR_PORT,MOTOR_PIN,GPIO_HIGH);

    TIME_TriggerDelayUS(100);

    GPIO_SetPinState(MOTOR_PORT,MOTOR_PIN,GPIO_LOW);

    TIME_TriggerDelayUS((55*160)-Bias_Time_US);
}
