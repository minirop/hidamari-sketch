#include "functions.h"

void func_0202f774(struct_data_021539b8_41c* param_1, u32 param_2, u32 param_3)
{
    if (param_1->unk_14)
    {
        if (param_1->unk_14)
        {
            param_1->unk_14->unk_00->unk_04();
        }

        param_1->unk_14 = 0;
    }

    if (param_1->unk_10b4)
    {
        func_0202fa10(param_1);
    }

    param_1->unk_10 = param_1->unk_04;
    param_1->unk_04 = param_2;

    switch (param_2)
    {
    case 5:
    {
        struct_data_021539b8_41c_14* iVar3 = func_02033c4c(0x41AC);
        if (iVar3 != 0) {
            iVar3 = func_0202ffa4();
        }
        param_1->unk_14 = iVar3;
        break;
    }
    case 10:
    {
        struct_data_021539b8_41c_14* iVar3 = func_02033c4c(0x610);
        if (iVar3 != 0) {
            iVar3 = func_02031254();
        }
        param_1->unk_14 = iVar3;
        break;
    }
    case 1:
    {
        struct_data_021539b8_41c_14* iVar3 = func_02033c4c(0x1cc);
        if (iVar3 != 0) {
            iVar3 = func_0202faac();
        }
        param_1->unk_14 = iVar3;
        break;
    }
    case 2:
    {
        struct_data_021539b8_41c_14* iVar3 = func_02033c4c(0x36c);
        if (iVar3 != 0) {
            iVar3 = func_0203c500();
        }
        param_1->unk_14 = iVar3;
        break;
    }
    case 3:
    {
        struct_data_021539b8_41c_14* iVar3 = func_02033c4c(0x1228);
        if (iVar3 != 0) {
            iVar3 = func_020a1c5c();
        }
        param_1->unk_14 = iVar3;
        break;
    }
    case 4:
    {
        struct_data_021539b8_41c_14* iVar3 = func_02033c4c(0x15F4);
        if (iVar3 != 0) {
            iVar3 = func_0203fd64();
        }
        param_1->unk_14 = iVar3;
        break;
    }
    case 6:
    {
        param_1->unk_14 = func_0204cf30();
        break;
    }
    case 11:
    {
        struct_data_021539b8_41c_14* iVar3 = func_02033c4c(0x6a00);
        if (iVar3 != 0) {
            iVar3 = func_0208d7a4();
        }
        param_1->unk_14 = iVar3;
        break;
    }
    case 13:
    {
        struct_data_021539b8_41c_14* iVar3 = func_02033c4c(0x1144);
        if (iVar3 != 0) {
            iVar3 = func_020a8450();
        }
        param_1->unk_14 = iVar3;
        break;
    }
    case 7:
    {
        struct_data_021539b8_41c_14* iVar3 = func_02033c4c(0x1A60);
        if (iVar3 != 0) {
            iVar3 = func_020a6b4c();
        }
        param_1->unk_14 = iVar3;
        break;
    }
    case 0:
    {
        struct_data_021539b8_41c_14* iVar3 = func_02033c4c(4);
        if (iVar3 != 0) {
            iVar3 = func_0203c4c8(iVar3);
        }
        param_1->unk_14 = iVar3;
        break;
    }
    case 8:
    case 9:
    case 12:
    default:
        func_020080fc();
        break;
    }

    param_1->unk_14->unk_00->unk_08(param_1->unk_14, param_3);
}

asm void func_0202f964()
{
    str        r1,[r0,#0x8]
    str        r2,[r0,#0xc]
    bx         lr
}

asm void func_0202f970()
{
    add        r0,r0,#0x1000
    strb       r1,[r0,#0x1a8]
    bx         lr
}

void func_0202f9a0();

asm void func_0202f97c()
{
    stmdb      sp!,{r3,lr}
    cmp        r1,#0x1
    bne        LAB_0202f994
    mov        r1,#0x1
    bl         func_0202f9a0
    ldmia      sp!,{r3,pc}
LAB_0202f994:
    mov        r1,#0x5
    bl         func_0202f9a0
    ldmia      sp!,{r3,pc}
}

void func_020332d8();
void func_02039cbc();
void func_02039cd0();
void func_02039fa8();
asm void func_0202f9a0()
{
    stmdb      sp!,{r3,r4,r5,r6,r7,lr}
    mov        r6,r1
    mov        r7,r0
    mov        r0,r6
    mov        r5,r2
    bl         func_020332d8
    cmp        r0,#0x1
    addeq      r0,r7,#0x39c
    addeq      r4,r0,#0x400
    add        r0,r7,#0x108
    add        r2,r7,#0xd8
    add        r12,r0,#0x1000
    addne      r4,r7,#0x7b0
    mov        r0,r4
    mov        r1,r6
    add        r2,r2,#0x1000
    mov        r3,#0x0
    str        r12,[sp,#0x0]
    bl         func_02039cbc
    mov        r1,#0x1
    mov        r0,r4
    mov        r3,r1
    mov        r2,#0x0
    bl         func_02039cd0
    mov        r0,r4
    mov        r1,r5
    bl         func_02039fa8
    ldmia      sp!,{r3,r4,r5,r6,r7,pc}
}

void func_0202fa10(struct_data_021539b8_41c* param)
{
    func_0202d3d4(&param->unk_10d8);
    func_0202d08c(&param->unk_1108);
    func_02039c5c(&param->unk_79c);
    func_02039c5c(&param->unk_7b0);
}
