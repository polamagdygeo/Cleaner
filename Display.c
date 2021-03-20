
#include "Display.h"
#include "LED.h"
#include "SSD.h"
#include "VC.h"

void Display_Init(void)
{

    
}
void Display_Update(void)
{   
    tVC_Speed speed = VC_GetSpeedLevel();
    tVC_DustBagState dust_bag_state = VC_GetDustState();
    
   LED_SetState(LED_DUST_INDICATOR,dust_bag_state);
   
   switch(speed)
   {
        case VC_LOW_SPEED:
             SSD_SetSymbol(SSD_LEFT,SSD_ONE_DASH);
             SSD_SetSymbol(SSD_CENTER,SSD_NO_DASH);
             SSD_SetSymbol(SSD_RIGHT,SSD_NO_DASH);
        break;
        case VC_MID_SPEED:
            SSD_SetSymbol(SSD_LEFT,SSD_ONE_DASH);
            SSD_SetSymbol(SSD_CENTER,SSD_TWO_DASH);
            SSD_SetSymbol(SSD_RIGHT,SSD_NO_DASH);
        break;
        
        case VC_HIGH_SPEED:
            SSD_SetSymbol(SSD_LEFT,SSD_ONE_DASH);
            SSD_SetSymbol(SSD_CENTER,SSD_TWO_DASH);
            SSD_SetSymbol(SSD_RIGHT,SSD_THREE_DASH);
        break;
        default:
           
        break;
   }
}