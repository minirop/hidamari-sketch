#include "functions.h"

void func_02002330();
void func_020022d4();
void func_0200229c();

// has 2 params passed to func_02002330
void func_020021f8()
{
    func_02002330();
    func_0200229c();
}

// has 1 param passed to func_020022d4
void func_02002208()
{
    func_020022d4();
    func_0200229c();
}

// https://decomp.me/scratch/DBGU7
// has 1 param passed to func_020022d4 (but doesn't change the scratch)
asm s64 func_02002218()
{
/*
    func_020022d4(param_1);
    while (REG_DIVCNT & 0x8000)
    {
    }
    return DIV_RESULT;
*/
    stmdb      sp!,{r3,lr}
    bl         func_020022d4
    ldr        r1,=0x04000280
LAB_02002224:
    ldrh       r0,[r1,#0x0]
    tst        r0,#0x8000
    bne        LAB_02002224
    ldr        r1,=0x040002A0
    ldmia      r1,{r0,r1}
    ldmia      sp!,{r3,pc}
}

int func_02002304();

// sqrt
int func_02002244(s32 value)
{
    if (value > 0)
    {
        REG_SQRT_CNT = 1;
        REG_SQRT_PARAM_LO = 0;
        REG_SQRT_PARAM_HI = value;
        return func_02002304();
    }

    return 0;
}

asm u64 func_02002278()
{
/*
    do {
    } while ((REG_DIVCNT & 0x8000) != 0);
    return DIV_RESULT;
*/
    ldr        r1,=0x04000280
LAB_0200227c:
    ldrh       r0,[r1,#0x0]
    tst        r0,#0x8000
    bne        LAB_0200227c
    ldr        r1,=0x040002A0
    ldmia      r1,{r0,r1}
    bx         lr
}
