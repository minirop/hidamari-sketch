#include "functions.h"

asm void func_0200810c()
{
    mov r0, #0x0
    mcr p15, 0, r0, c7, c0, 4
    bx  lr
}

void func_02008118(u8 data)
{
    REG_WRAM_CNT = data;
}
