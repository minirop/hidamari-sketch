#include "functions.h"

extern struct_data_0214a748 data_0214a748;

struct_unk_HTNU_HPXE_format* func_02015444(struct_data_0214a748* param_1, struct_unk_HTNU_HPXE_format* param_2)
{
    if (param_2 == 0)
    {
        return param_1->unk_00;
    }
    else
    {
        u16 unk_0a = param_1->unk_0a;
        // fake match
        return ((struct_unk_HTNU_HPXE_format*)(((u8*)param_2) + unk_0a))->unk_04;
    }
}

asm void func_0201545c()
{
    cmp        r1,#0x0
    ldreq      r0,[r0,#0x4]
    ldrneh     r0,[r0,#0xa]
    ldrne      r0,[r1,r0]
    bx         lr
}

struct_unk_HTNU_HPXE_format* func_02015470(struct_data_0214a748* param_1, struct_data_021539b8_04* param_2)
{
    struct_unk_HTNU_HPXE_format* uVar1 = func_02015444(param_1, 0);
    while (uVar1 != 0)
    {
        if (uVar1->unk_18 <= param_2 && param_2 < uVar1->unk_1c)
        {
            struct_unk_HTNU_HPXE_format* uVar2 = func_02015470(&uVar1->unk_0c, param_2);
            if (uVar2 == 0)
            {
                uVar2 = uVar1;
            }
            return uVar2;
        }

        uVar1 = func_02015444(param_1, uVar1);
    }

    return 0;
}

// on hold
asm void func_020154d8()
{
    stmdb      sp!,{r4,lr}
    ldr        r4,=data_0214a748
    mov        r1,r0
    mov        r0,r4
    bl         func_02015470
    cmp        r0,#0x0
    addne      r4,r0,#0xc
    mov        r0,r4
    ldmia      sp!,{r4,pc}
}

// on hold
extern int data_0214a744;
void func_020152dc();
void func_02015298();
asm void func_02015500()
{
    stmdb      sp!,{r4,lr}
    mov        r4,r0
    ldrh       r0,[sp,#0x8]
    str        r1,[r4,#0x0]
    mov        r12,#0x0
    str        r2,[r4,#0x18]
    bic        r1,r12,#0xff
    and        r0,r0,#0xff
    orr        r2,r1,r0
    str        r3,[r4,#0x1c]
    add        r0,r4,#0xc
    mov        r1,#0x4
    str        r2,[r4,#0x20]
    bl         func_02015298
    ldr        r0,=data_0214a744
    ldr        r0,[r0,#0x0]
    cmp        r0,#0x0
    bne        LAB_02015560
    ldr        r0,=data_0214a748
    mov        r1,#0x4
    bl         func_02015298
    ldr        r0,=data_0214a744
    mov        r1,#0x1
    str        r1,[r0,#0x0]
LAB_02015560:
    mov        r0,r4
    bl         func_020154d8
    mov        r1,r4
    bl         func_020152dc
    ldmia      sp!,{r4,pc}
}

// on hold
void func_020153e4();
asm void func_0201557c(s32 param_1)
{
    stmdb      sp!,{r4,lr}
    mov        r4,r0
    bl         func_020154d8
    mov        r1,r4
    bl         func_020153e4
    ldmia      sp!,{r4,pc}
}

struct_unk_HTNU_HPXE_format* func_02015594(struct_data_021539b8_04* param)
{
    return func_02015470(&data_0214a748, param);
}
