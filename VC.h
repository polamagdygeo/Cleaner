#ifndef VC_H_INCLUDED
#define VC_H_INCLUDED

#include "Main.h"

#define VC_PERIOD_MS                        20

typedef enum{
    VC_LOW_SPEED,
    VC_MID_SPEED,
    VC_HIGH_SPEED
}tVC_Speed;

typedef enum{
    VC_DUST_BAG_EMPTY,
    VC_DUST_BAG_FULL
}tVC_DustBagState;

void VC_Init(void);
tVC_Speed VC_GetSpeedLevel(void);
tVC_DustBagState VC_GetDustState(void);
void VC_Update(void);


#endif // VC_H_INCLUDED
