#include "Motor.h"
#include "GPIO.h"
#include "Port.h"
#include "Time.h"
#include "Timer.h"

typedef enum{
    MOTOR_SOFT_SWITCHING,
    MOTOR_HARMONIC_REDUCTION
}tMotor_State;

static tMotor_State motor_current_state = MOTOR_SOFT_SWITCHING;

static tMotor_TargetAngle motor_set_angle;
static u8 motor_current_angle = MOTOR_ANGLE_170;
static u8 motor_harmonic_angle;
static u8 motor_actual_output_angle = MOTOR_ANGLE_170;

void Motor_SetTargetAngle(tMotor_TargetAngle target_angle)
{
    motor_set_angle = target_angle;
}

void Motor_Init(tMotor_TargetAngle initial_target_angle)
{
    GPIO_InitPin(MOTOR_PORT,MOTOR_PIN,GPIO_OUTPUT_DIR);

    GPIO_SetPinState(MOTOR_PORT,MOTOR_PIN,GPIO_LOW);

    Motor_SetTargetAngle(initial_target_angle);
}

void Motor_SoftSwitchingUpdate(void)
{
    if(motor_current_state == MOTOR_SOFT_SWITCHING)
    {
        if(motor_current_angle == motor_set_angle)
        {
            motor_current_state = MOTOR_HARMONIC_REDUCTION;
            motor_harmonic_angle = motor_current_angle+HARMONIC_REDUCTION_DELTA;
        }
        else
        {
            if(motor_current_angle > motor_set_angle)
            {
                motor_current_angle--;
            }
            else
            {
                motor_current_angle++;
            }

             motor_actual_output_angle = motor_current_angle;
        }

    }

}

void Motor_HarmonicReductionUpdate(void)
{
    if(motor_current_state == MOTOR_HARMONIC_REDUCTION)
    {
        if(motor_current_angle != motor_set_angle)
        {
            motor_current_state = MOTOR_SOFT_SWITCHING;
        }
        else if((motor_set_angle - HARMONIC_REDUCTION_DELTA) >= 10 &&
                ((motor_set_angle + HARMONIC_REDUCTION_DELTA) <= 170))
        {
            if(motor_harmonic_angle > motor_set_angle)
            {
                motor_harmonic_angle -= (HARMONIC_REDUCTION_DELTA * 2);
            }
            else if(motor_harmonic_angle < motor_set_angle)
            {
                motor_harmonic_angle += (HARMONIC_REDUCTION_DELTA * 2);
            }

            motor_actual_output_angle = motor_harmonic_angle;
        }
    }
}

void Motor_OutputUpdate(void)
{
    u16 bias_time_us = (55 * (motor_actual_output_angle - 10));

    TIME_TriggerDelayUS(bias_time_us);

    GPIO_SetPinState(MOTOR_PORT,MOTOR_PIN,GPIO_HIGH);

    TIME_TriggerDelayUS(100);

    GPIO_SetPinState(MOTOR_PORT,MOTOR_PIN,GPIO_LOW);

    TIME_TriggerDelayUS((55*160) - bias_time_us);
}
