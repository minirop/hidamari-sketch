#include "functions.h"

extern struct_data_0214a748 data_0214a748;

void func_020153e4(struct_data_0214a748* param_1, struct_data_02153964* param_2)
{
    struct_unk_HTNU_HPXE_format ** array = ((struct_unk_HTNU_HPXE_format**)(((u8*)param_2) + param_1->unk_0a));
    if (array[0] == 0)
    {
        param_1->unk_00 = array[1];
    }
    else
    {
        // fake match
        ((struct_unk_HTNU_HPXE_format*)(((u8*)array) + param_1->unk_0a))->unk_04 = array[1];
    }

    if (array[1] == 0)
    {
        param_1->unk_04 = array[0];
    }
    else
    {
        // fake match
        *((struct_unk_HTNU_HPXE_format**)(((u8*)array[1]) + param_1->unk_0a)) = array[0];
    }

    array[0] = 0;
    array[1] = 0;
    param_1->unk_08--;
}

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

struct_unk_HTNU_HPXE_format* func_02015470(struct_data_0214a748* param_1, struct_data_02153964* param_2)
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

struct_data_0214a748* func_020154d8(struct_data_02153964* param)
{
    struct_data_0214a748* ptr = &data_0214a748;
    struct_unk_HTNU_HPXE_format* format = func_02015470(&data_0214a748, param);
    if (format != 0)
    {
        ptr = &format->unk_0c;
    }

    return ptr;
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

void func_0201557c(struct_data_02153964* param)
{
    struct_data_0214a748* uVar1 = func_020154d8(param);
    func_020153e4(uVar1, param);
}

struct_unk_HTNU_HPXE_format* func_02015594(struct_data_02153964* param)
{
    return func_02015470(&data_0214a748, param);
}

void func_020155ac(u32* param_1, struct_temp_02015b18* param_2)
{
    param_1[0] = (param_2->unk_02 >> 8) & 0x7f;
    param_1[1] = *(param_2->unk_10 + param_2->unk_04);
}

// another sort of linked list?
struct_temp_02015b18_08_0c* func_020155d8(struct_temp_02015b18_08_0c** param_1, struct_temp_02015b18* param_2)
{
    struct_temp_02015b18_08_0c* r2 = param_2->unk_08;
    struct_temp_02015b18_08_0c* r1 = param_2->unk_0c;

    if (r2)
    {
        r2->unk_0c = r1;
    }
    else
    {
        param_1[0] = r1;
    }

    if (r1)
    {
        r1->unk_08 = r2;
    }
    else
    {
        param_1[1] = r2;
    }

    return r2;
}
