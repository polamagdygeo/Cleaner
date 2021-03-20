#ifndef SSD_H_INCLUDED
#define SSD_H_INCLUDED

#include "Main.h"

#define SSD_PERIOD_MS                       10UL

typedef enum{
    SSD_LEFT,
    SSD_CENTER,
    SSD_RIGHT.
    SSD_COUNT
}tSSD;

typedef enum{
    SSD_NO_DASH,
    SSD_ONE_DASH,
    SSD_TWO_DASH,
    SSD_THREE_DASH,
    SSD_SYMBOL_COUNT
}tSSD_Symbol;

void SSD_Init(tSSD ssd,tSSD_Symbol intial_symbol);
void SSD_SetSymbol(tSSD ssd,tSSD_Symbol symbol);
void SSD_SetCtrlLine(tSSD ssd,u8 state);
void SSD_Update(void);


#endif // SSD_H_INCLUDED
