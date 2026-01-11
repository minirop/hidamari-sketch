#ifndef HARDWARE_H
#define HARDWARE_H

#include "global.h"

#define REG_KEYINPUT (*(vu16 *)0x04000130)
#define REG_EXMEM_CNT (*(vu16 *)0x04000204)
#define REG_IME (*(vu16 *)0x04000208)
#define REG_DIVCNT (*(vu16 *)0x04000280)
#define DIV_RESULT (*(vs64 *)0x040002A0)
#define REG_POWER_CNT (*(vu16 *)0x04000304)
#define REG_DISPCNT_SUB (*(vu32 *)0x04001000)
#define REG_SQRT_CNT (*(vu16 *)0x040002b0)
#define REG_SQRT_RESULT (*(vu32 *)0x040002b4)
#define REG_SQRT_PARAM_LO (*(vu32 *)0x040002b8)
#define REG_SQRT_PARAM_HI (*(vu32 *)0x040002bc)
#define GFX_FIFO_SWAP (*(vu32 *)0x04000540)
#define REG_TIM0CNT_L (*(vu16 *)0x04000100)
#define REG_TIM0CNT_H (*(vu16 *)0x04000102)
#define REG_TIM1CNT_L (*(vu16 *)0x04000104)
#define REG_TIM1CNT_H (*(vu16 *)0x04000106)
#define REG_IF (*(vu32 *)0x04000214)
#define REG_WRAM_CNT (*(vu8 *)0x04000247)

#endif
