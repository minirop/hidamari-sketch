#include "functions.h"

asm u32 func_02007f04()
{
    mrs r0,cpsr
    bic r1,r0,#0x80
    msr cpsr_c,r1
    and r0,r0,#0x80
    bx  lr
}

asm u32 func_02007f18()
{
    mrs r0,cpsr
    orr r1,r0,#0x80
    msr cpsr_c,r1
    and r0,r0,#0x80
    bx  lr
}

asm u32 func_02007f2c()
{
    mrs r1,cpsr
    bic r2,r1,#0x80
    orr r2,r2,r0
    msr cpsr_c,r2
    and r0,r1,#0x80
    bx  lr
}

asm u32 func_02007f44()
{
    mrs r0,cpsr
    orr r1,r0,#0xc0
    msr cpsr_c,r1
    and r0,r0,#0xc0
    bx  lr
}

asm u32 func_02007f58()
{
    mrs r1,cpsr
    bic r2,r1,#0xc0
    orr r2,r2,r0
    msr cpsr_c,r2
    and r0,r1,#0xc0
    bx  lr
}

asm u32 func_02007f70()
{
    mrs r0,cpsr
    and r0,r0,#0x80
    bx  lr
}

asm u32 func_02007f7c()
{
    mrs r0,cpsr
    and r0,r0,#0x1f
    bx  lr
}
