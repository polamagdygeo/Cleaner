#include "VC.h"
#include "Button.h"
#include "Motor.h"
#include "Display.h"

static tVC_Speed speed_level = VC_MID_SPEED;
static tVC_DustBagState dust_bag_state = VC_DUST_BAG_EMPTY;

void VC_Init(void)
{

}

tVC_Speed VC_GetSpeedLevel(void)
{
    return speed_level;
}

tVC_DustBagState VC_GetDustState(void)
{
    return dust_bag_state;
}

void VC_Update(void)
{
    switch(speed_level)
    {
        case VC_LOW_SPEED:
            Motor_SetTargetAngle(MOTOR_ANGLE_140);
            if(Button_GetState(BUTTON_PLUS) == BUTTON_PRE_RELEASED)
            {
                speed_level++;
            }
        break;
        case VC_MID_SPEED:
            Motor_SetTargetAngle(MOTOR_ANGLE_90);
            if(Button_GetState(BUTTON_MINUS) == BUTTON_PRE_RELEASED || 
                ((Button_GetPressingTime(BUTTON_DUST) % 30000) == 0))
            {
                speed_level--;
            }
            else if(Button_GetState(BUTTON_PLUS) == BUTTON_PRE_RELEASED)
            {
                speed_level++;
            }

        break;
        case VC_HIGH_SPEED:
            Motor_SetTargetAngle(MOTOR_ANGLE_10);
            if(Button_GetState(BUTTON_MINUS) == BUTTON_PRE_RELEASED || 
                ((Button_GetPressingTime(BUTTON_DUST) % 30000) == 0))
            {
                speed_level--;
            }
        break;
        default:
            break;
    }
    
    if(Button_GetState(BUTTON_DUST) == BUTTON_PRESSED)
    {
        dust_bag_state = VC_DUST_BAG_FULL;
    }
    else
    {
        dust_bag_state = VC_DUST_BAG_EMPTY;
    }
}