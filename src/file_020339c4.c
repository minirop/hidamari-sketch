#include "functions.h"

extern int data_02153964[];

void func_020339c4()
{
    if (data_02153964[2] != 0)
    {
        func_02015eb8(data_02153964[2]);
        data_02153964[2] = 0;
        func_02007640(0, -1, data_02153964[3]);
        data_02153964[3] = 0;
    }

    if (data_02153964[1] != 0)
    {
        func_02015adc(data_02153964[1]);
        data_02153964[1] = 0;
        func_02007640(0, -1, data_02153964[0]);
        data_02153964[0] = 0;
    }
}

void func_02015ec4();
void func_02015ae8();
// on hold until called
asm void func_02033a40()
{
    stmdb      sp!,{r3,r4,r5,lr}
    mov        r5,r0
    mov        r4,r1
    cmp        r5,#0x20
    bhi        LAB_02033a68
    ldr        r0,=data_02153964
    ldr        r0,[r0,#0x8]
    bl         func_02015ec4
    cmp        r0,#0x0
    ldmneia    sp!,{r3,r4,r5,pc}
LAB_02033a68:
    ldr        r0,=data_02153964
    mov        r1,r5
    ldr        r0,[r0,#0x4]
    mov        r2,r4
    bl         func_02015ae8
    ldmia      sp!,{r3,r4,r5,pc}
}

void func_02033a84(int param_1)
{
    struct_unk_HTNU_HPXE_format* format;

    if (param_1 == 0) {
        return;
    }

    format = func_02015594(param_1);
    if (format->magic == 0x554E5448) // HTNU
    {
        func_02015f04(format, param_1);
    }
    else if (format->magic == 0x45585048) // HPXE
    {
        func_02015b18(format, param_1);
    }
    else
    {
        func_020080fc();
    }
}

extern int data_02153980;

int* FUN_02033ad8()
{
    return &data_02153980;
}
