#include "VC.h"
#include "Button.h"
#include "Motor.h"
#include "Display.h"

static tVC_Speed Speed_Level=VC_MID_SPEED;
static tVC_DustBagState Dust_Bag_State=VC_DUST_BAG_EMPTY;

void VC_Init(void)
{

}
tVC_Speed VC_GetSpeedLevel(void)
{
    return Speed_Level;
}
tVC_DustBagState VC_GetDustState(void)
{
    return Dust_Bag_State;
}
void VC_Update(void)
{
    switch(Speed_Level)
    {
        case VC_LOW_SPEED:
            Motor_SetTargetAngle(MOTOR_ANGLE_140);
            if(Button_GetState(BUTTON_PLUS)==BUTTON_PRE_RELEASED)
            {
                Speed_Level++;
            }
        break;
        case VC_MID_SPEED:
            Motor_SetTargetAngle(MOTOR_ANGLE_90);
            if(Button_GetState(BUTTON_MINUS)==BUTTON_PRE_RELEASED || (Button_GetPressingTime(BUTTON_DUST)%30000==0))
            {
                Speed_Level--;
            }
            else if(Button_GetState(BUTTON_PLUS)==BUTTON_PRE_RELEASED)
            {
                Speed_Level++;
            }

        break;
        case VC_HIGH_SPEED:
            Motor_SetTargetAngle(MOTOR_ANGLE_10);
            if(Button_GetState(BUTTON_MINUS)==BUTTON_PRE_RELEASED || (Button_GetPressingTime(BUTTON_DUST)%30000==0))
            {
                Speed_Level--;
            }
        break;
        default:
            break;
    }
    
    if(Button_GetState(BUTTON_DUST)==BUTTON_PRESSED)
    {
        Dust_Bag_State=VC_DUST_BAG_FULL;
    }
    else
    {
        Dust_Bag_State=VC_DUST_BAG_EMPTY;
    }
}