#include "SSD.h"
#include "GPIO.h"
#include "Port.h"

static tSSD_Symbol Segments_Symbols_Array[3]=
{
    SSD_NO_DASH,
    SSD_NO_DASH,
    SSD_NO_DASH
};

static const u8 Symbol_Code_Array[4]={
                                0,
                                1<<3,
                                1<<3|1<<6,
                                1<<3|1<<6|1<<0};

void SSD_Init(tSSD ssd,tSSD_Symbol intial_symbol)
{
    GPIO_InitPort(SSD_PORT,SSD_PINS_MASK,GPIO_OUTPUT_DIR);
    GPIO_InitPin(SSD_PORT,SSD_DOT_PIN,GPIO_OUTPUT_DIR);

    switch(ssd)
    {
        case SSD_LEFT:
            GPIO_InitPin(SSD_LEFT_CTRL_PORT,SSD_LEFT_CTRL_PIN,GPIO_OUTPUT_DIR);
            GPIO_SetPinState(SSD_LEFT_CTRL_PORT,SSD_LEFT_CTRL_PIN,GPIO_LOW);
        break;
        case SSD_CENTER:
             GPIO_InitPin(SSD_CENTER_CTRL_PORT,SSD_CENTER_CTRL_PIN,GPIO_OUTPUT_DIR);
             GPIO_SetPinState(SSD_CENTER_CTRL_PORT,SSD_CENTER_CTRL_PIN,GPIO_LOW);
        break;
        case SSD_RIGHT:
            GPIO_InitPin(SSD_RIGHT_CTRL_PORT,SSD_RIGHT_CTRL_PIN,GPIO_OUTPUT_DIR);
            GPIO_SetPinState(SSD_RIGHT_CTRL_PORT,SSD_RIGHT_CTRL_PIN,GPIO_LOW);
        break;
        default:
            break;
    }

    SSD_SetSymbol(ssd,intial_symbol);
}
void SSD_SetSymbol(tSSD ssd,tSSD_Symbol symbol)
{
    Segments_Symbols_Array[ssd]=symbol;
}
void SSD_SetCtrlLine(tSSD ssd,u8 state)
{
    switch(ssd)
    {
        case SSD_LEFT:
            GPIO_SetPinState(SSD_LEFT_CTRL_PORT,SSD_LEFT_CTRL_PIN,state);
        break;
        case SSD_CENTER:
            GPIO_SetPinState(SSD_CENTER_CTRL_PORT,SSD_CENTER_CTRL_PIN,state);
        break;
        case SSD_RIGHT:
            GPIO_SetPinState(SSD_RIGHT_CTRL_PORT,SSD_RIGHT_CTRL_PIN,state);
        break;
        default:

            break;
    }
}

void SSD_Update(void)
{
    static tSSD Curr_Active_SSD=SSD_LEFT;

    tSSD_Symbol Current_Symbol=Segments_Symbols_Array[Curr_Active_SSD];

    SSD_SetCtrlLine(SSD_LEFT,0);
    SSD_SetCtrlLine(SSD_CENTER,0);
    SSD_SetCtrlLine(SSD_RIGHT,0);

    GPIO_SetPortState(SSD_PORT,SSD_PINS_MASK,Symbol_Code_Array[Current_Symbol]);

    SSD_SetCtrlLine(Curr_Active_SSD,1);

    if(Curr_Active_SSD < SSD_RIGHT)
    {
        Curr_Active_SSD++;
    }
    else
    {
        Curr_Active_SSD=SSD_LEFT;
    }
}
