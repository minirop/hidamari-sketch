#include "matrix.h"

// 2D matrix multiplication?
void func_02000c3c(s32* param_1, s32* param_2, s32 param_3, s32 param_4)
{
    param_2[0] = param_3 * (s64)param_1[0] >> 0xC;
    param_2[1] = param_3 * (s64)param_1[1] >> 0xC;
    param_2[2] = param_4 * (s64)param_1[2] >> 0xC;
    param_2[3] = param_4 * (s64)param_1[3] >> 0xC;
}

// matrix 3x3 identity
asm void func_02000c94(Matrix33 *matrix)
{
/*
    param_1[0] = 0x1000;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0x1000;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
    param_1[8] = 0x1000;
*/
    mov        r2,#0x1000
    str        r2,[r0,#0x20]
    mov        r3,#0x0
    stmia      r0!,{r2,r3}
    mov        r1,#0x0
    stmia      r0!,{r1,r3}
    stmia      r0!,{r2,r3}
    stmia      r0!,{r1,r3}
    bx         lr
}

// matrix multiplication?
void func_02000cb8(Matrix33* param_1, Matrix33* param_2, s32 param_3, s32 param_4, s32 param_5)
{
    param_2->data[0] = param_3 * (s64)param_1->data[0] >> 0xC;
    param_2->data[1] = param_3 * (s64)param_1->data[1] >> 0xC;
    param_2->data[2] = param_3 * (s64)param_1->data[2] >> 0xC;
    param_2->data[3] = param_4 * (s64)param_1->data[3] >> 0xC;
    param_2->data[4] = param_4 * (s64)param_1->data[4] >> 0xC;
    param_2->data[5] = param_4 * (s64)param_1->data[5] >> 0xC;
    param_2->data[6] = param_5 * (s64)param_1->data[6] >> 0xC;
    param_2->data[7] = param_5 * (s64)param_1->data[7] >> 0xC;
    param_2->data[8] = param_5 * (s64)param_1->data[8] >> 0xC;
}

#pragma thumb on

// matrix 3x3 rotation (3D along x-axis)
void func_02000d78(Matrix33* matrix, s32 sin_theta, s32 cos_theta)
{
    matrix->data[0] = 0x1000;
    matrix->data[1] = 0;
    matrix->data[2] = 0;
    matrix->data[3] = 0;
    matrix->data[4] = cos_theta;
    matrix->data[5] = sin_theta;
    matrix->data[6] = 0;
    matrix->data[7] = -sin_theta;
    matrix->data[8] = cos_theta;
}

// matrix 3x3 rotation (3D along y-axis)
asm void func_02000d94(Matrix33* matrix, s32 sin_theta, s32 cos_theta)
{
/*
    matrix->data[0] = cos_theta;
    matrix->data[1] = 0;
    matrix->data[2] = -sin_theta;
    matrix->data[3] = 0;
    matrix->data[4] = 0x1000;
    matrix->data[5] = 0;
    matrix->data[6] = sin_theta;
    matrix->data[7] = 0;
    matrix->data[8] = cos_theta;
*/
    str        r2,[r0,#0x0]
    str        r2,[r0,#0x20]
    mov        r3,#0x0
    str        r3,[r0,#0x4]
    str        r3,[r0,#0xc]
    str        r3,[r0,#0x14]
    str        r3,[r0,#0x1c]
    neg        r2,r1
    mov        r3,#0x1
    lsl        r3,r3,#0xc
    str        r1,[r0,#0x18]
    str        r2,[r0,#0x8]
    str        r3,[r0,#0x10]
    bx         lr
}

// matrix 3x3 rotation (3D along z-axis)
asm void func_02000db0(Matrix33* matrix, s32 sin_theta, s32 cos_theta)
{
/*
    matrix->data[0] = cos_theta;
    matrix->data[1] = sin_theta;
    matrix->data[2] = 0;
    matrix->data[3] = -sin_theta;
    matrix->data[4] = cos_theta;
    matrix->data[5] = 0;
    matrix->data[6] = 0;
    matrix->data[7] = 0;
    matrix->data[8] = 0x1000;
*/
    stmia      r0!,{r2}
    mov        r3,#0x0
    stmia      r0!,{r1,r3}
    neg        r1,r1
    stmia      r0!,{r1,r2}
    mov        r1,#0x1
    lsl        r1,r1,#0xc
    str        r3,[r0,#0x0]
    str        r3,[r0,#0x4]
    str        r3,[r0,#0x8]
    str        r1,[r0,#0xc]
    bx         lr
}

#pragma thumb off

// some matrix multiplication?
asm void func_02000dc8(Matrix33 *param_1, Matrix33 *param_2, Matrix33 *param_3)
{
    stmdb      sp!,{r3,r4,r5,r6,r7,r8,r9,r10,r11,lr}
    sub        sp,sp,#0x40
    mov        r12,r2
    ldr        r3,[r0,#0x4]
    ldr        r2,[r1,#0xc]
    cmp        r12,r1
    smull      r7,r5,r3,r2
    ldr        r6,[r0,#0x0]
    ldr        r4,[r1,#0x0]
    addeq      r10,sp,#0x1c
    smlal      r7,r5,r6,r4
    ldr        r2,[r0,#0x8]
    ldr        r4,[r1,#0x18]
    movne      r10,r12
    smlal      r7,r5,r2,r4
    mov        r4,r7, lsr #0xc
    orr        r4,r4,r5, lsl #0x14
    str        r4,[r10,#0x0]
    ldr        r4,[r1,#0x10]
    ldr        r5,[r1,#0x4]
    smull      r8,r7,r3,r4
    smlal      r8,r7,r6,r5
    ldr        r4,[r1,#0x1c]
    smlal      r8,r7,r2,r4
    mov        r4,r8, lsr #0xc
    orr        r4,r4,r7, lsl #0x14
    str        r4,[r10,#0x4]
    ldr        r4,[r1,#0x14]
    ldr        r5,[r1,#0x8]
    smull      r8,r7,r3,r4
    smlal      r8,r7,r6,r5
    ldr        r3,[r1,#0x20]
    smlal      r8,r7,r2,r3
    mov        r2,r8, lsr #0xc
    orr        r2,r2,r7, lsl #0x14
    str        r2,[r10,#0x8]
    ldr        r9,[r0,#0x10]
    ldr        r2,[r0,#0xc]
    smull      r7,r6,r9,r4
    smlal      r7,r6,r2,r5
    ldr        r4,[r0,#0x14]
    smlal      r7,r6,r4,r3
    mov        r3,r7, lsr #0xc
    orr        r3,r3,r6, lsl #0x14
    str        r3,[r10,#0x14]
    ldr        r3,[r1,#0x10]
    ldr        r5,[r1,#0x4]
    smull      r7,r6,r9,r3
    smlal      r7,r6,r2,r5
    ldr        r5,[r1,#0x1c]
    mov        r3,r9, asr #0x1f
    smlal      r7,r6,r4,r5
    str        r3,[sp,#0x0]
    mov        r3,r7, lsr #0xc
    orr        r3,r3,r6, lsl #0x14
    str        r3,[r10,#0x10]
    mov        r3,r2, asr #0x1f
    str        r3,[sp,#0x4]
    mov        r3,r4, asr #0x1f
    ldr        r8,[r1,#0xc]
    str        r3,[sp,#0x8]
    mov        r3,r8, asr #0x1f
    str        r3,[sp,#0x18]
    ldr        r7,[r1,#0x0]
    ldr        r6,[r1,#0x18]
    mov        r3,r7, asr #0x1f
    str        r3,[sp,#0xc]
    umull      r3,r5,r4,r6
    mov        r11,r6, asr #0x1f
    str        r3,[sp,#0x10]
    mla        r5,r4,r11,r5
    ldr        r3,[sp,#0x8]
    add        lr,sp,#0x1c
    mla        r5,r3,r6,r5
    umull      r3,r4,r2,r7
    str        r3,[sp,#0x14]
    ldr        r3,[sp,#0xc]
    mla        r4,r2,r3,r4
    ldr        r2,[sp,#0x4]
    umull      r3,r11,r9,r8
    mla        r4,r2,r7,r4
    ldr        r2,[sp,#0x14]
    adds       r3,r2,r3
    ldr        r2,[sp,#0x18]
    mla        r11,r9,r2,r11
    ldr        r2,[sp,#0x0]
    mla        r11,r2,r8,r11
    adc        r4,r4,r11
    ldr        r2,[sp,#0x10]
    ldr        r11,[sp,#0x18]
    adds       r3,r2,r3
    adc        r2,r5,r4
    mov        r3,r3, lsr #0xc
    orr        r3,r3,r2, lsl #0x14
    str        r3,[r10,#0xc]
    ldr        r2,[r0,#0x1c]
    ldr        r5,[r0,#0x18]
    ldr        r4,[r0,#0x20]
    umull      r3,r0,r2,r8
    mla        r0,r2,r11,r0
    mov        r9,r2, asr #0x1f
    mla        r0,r9,r8,r0
    smlal      r3,r0,r5,r7
    smlal      r3,r0,r4,r6
    mov        r3,r3, lsr #0xc
    orr        r3,r3,r0, lsl #0x14
    str        r3,[r10,#0x18]
    ldr        r0,[r1,#0x10]
    ldr        r3,[r1,#0x4]
    smull      r7,r0,r2,r0
    cmp        r10,lr
    smlal      r7,r0,r5,r3
    ldr        r6,[r1,#0x1c]
    addne      sp,sp,#0x40
    smlal      r7,r0,r4,r6
    mov        r3,r7, lsr #0xc
    orr        r3,r3,r0, lsl #0x14
    str        r3,[r10,#0x1c]
    ldr        r0,[r1,#0x14]
    ldr        r6,[r1,#0x20]
    ldr        r3,[r1,#0x8]
    smull      r1,r0,r2,r0
    smlal      r1,r0,r5,r3
    smlal      r1,r0,r4,r6
    mov        r1,r1, lsr #0xc
    orr        r1,r1,r0, lsl #0x14
    str        r1,[r10,#0x20]
    ldmneia    sp!,{r3,r4,r5,r6,r7,r8,r9,r10,r11,pc}
    ldmia      lr!,{r0,r1,r2,r3}
    stmia      r12!,{r0,r1,r2,r3}
    ldmia      lr!,{r0,r1,r2,r3}
    stmia      r12!,{r0,r1,r2,r3}
    ldr        r0,[lr,#0x0]
    str        r0,[r12,#0x0]
    add        sp,sp,#0x40
    ldmia      sp!,{r3,r4,r5,r6,r7,r8,r9,r10,r11,pc}
}

// matrix 4x3 identity
asm void func_02000fe8(Matrix43* matrix)
{
/*
    matrix->data[0] = 0x1000;
    matrix->data[1] = 0;
    matrix->data[2] = 0;
    matrix->data[3] = 0;
    matrix->data[4] = 0x1000;
    matrix->data[5] = 0;
    matrix->data[6] = 0;
    matrix->data[7] = 0;
    matrix->data[8] = 0x1000;
    matrix->data[9] = 0;
    matrix->data[10] = 0;
    matrix->data[11] = 0;
*/
    mov        r2,#0x1000
    mov        r3,#0x0
    stmia      r0!,{r2,r3}
    mov        r1,#0x0
    stmia      r0!,{r1,r3}
    stmia      r0!,{r2,r3}
    stmia      r0!,{r1,r3}
    stmia      r0!,{r2,r3}
    stmia      r0!,{r1,r3}
    bx         lr
}

asm void func_02001010(Matrix43* source, Matrix44* dest)
{
/*
    dest->data[0] = source->data[0];
    dest->data[1] = source->data[1];
    dest->data[2] = source->data[2];
    dest->data[3] = 0;
    dest->data[4] = source->data[3];
    dest->data[5] = source->data[4];
    dest->data[6] = source->data[5];
    dest->data[7] = 0;
    dest->data[8] = source->data[6];
    dest->data[9] = source->data[7];
    dest->data[10] = source->data[8];
    dest->data[11] = 0;
    dest->data[12] = source->data[9];
    dest->data[13] = source->data[10];
    dest->data[14] = source->data[11];
    dest->data[15] = 0x1000;
*/
    stmdb      sp!,{r4}
    mov        r12,#0x0
    ldmia      r0!,{r2,r3,r4}
    stmia      r1!,{r2,r3,r4,r12}
    ldmia      r0!,{r2,r3,r4}
    stmia      r1!,{r2,r3,r4,r12}
    ldmia      r0!,{r2,r3,r4}
    stmia      r1!,{r2,r3,r4,r12}
    mov        r12,#0x1000
    ldmia      r0!,{r2,r3,r4}
    stmia      r1!,{r2,r3,r4,r12}
    ldmia      sp!,{r4}
    bx         lr
}

void func_02001044(Matrix43* source, Matrix43* dest, s32 param_3, s32 param_4, s32 param_5)
{
    func_02000cb8((Matrix33*)source, (Matrix33*)dest, param_3, param_4, param_5);
    dest->data[9] = source->data[9];
    dest->data[10] = source->data[10];
    dest->data[11] = source->data[11];
}

// temp
void func_020022d4();
void func_0200229c();
void func_02008a38();

asm void func_02001078(Matrix43* param_1, Matrix43* param_2)
{
    stmdb      sp!,{r4,r5,r6,r7,r8,r9,r10,r11,lr}
    sub        sp,sp,#0x5c
    mov        r10,r0
    ldr        r0,[r10,#0x14]
    cmp        r10,r1
    addeq      r9,sp,#0x2c
    ldr        r3,[r10,#0x18]
    ldr        r2,[r10,#0xc]
    ldr        r6,[r10,#0x20]
    str        r1,[sp,#0x0]
    movne      r9,r1
    smull      r11,r8,r2,r6
    smull      r7,r1,r0,r3
    subs       r7,r11,r7
    sbc        r12,r8,r1
    ldr        r4,[r10,#0x10]
    ldr        r5,[r10,#0x1c]
    adds       r1,r7,#0x800
    smull      r11,r8,r4,r6
    smull      r7,r6,r0,r5
    adc        r0,r12,#0x0
    subs       r7,r11,r7
    sbc        r6,r8,r6
    mov        r8,r1, lsr #0xc
    orr        r8,r8,r0, lsl #0x14
    smull      r1,r0,r2,r5
    adds       r7,r7,#0x800
    smull      r5,r3,r4,r3
    adc        r2,r6,#0x0
    mov        r7,r7, lsr #0xc
    orr        r7,r7,r2, lsl #0x14
    subs       r1,r1,r5
    sbc        r5,r0,r3
    ldr        r2,[r10,#0x0]
    adds       r6,r1,#0x800
    ldr        r11,[r10,#0x4]
    smull      r4,r3,r2,r7
    smull      r1,r0,r11,r8
    adc        r2,r5,#0x0
    mov        r6,r6, lsr #0xc
    orr        r6,r6,r2, lsl #0x14
    subs       r2,r4,r1
    ldr        r1,[r10,#0x8]
    sbc        r0,r3,r0
    smlal      r2,r0,r1,r6
    adds       r1,r2,#0x800
    adc        r2,r0,#0x0
    mov        r0,r1, lsr #0xc
    mov        r1,r8, asr #0x1f
    str        r1,[sp,#0x4]
    mov        r1,r7, asr #0x1f
    str        r1,[sp,#0x8]
    mov        r1,r6, asr #0x1f
    str        r1,[sp,#0xc]
    orrs       r0,r0,r2, lsl #0x14
    mov        r1,#0x0
    addeq      sp,sp,#0x5c
    subeq      r0,r1,#0x1
    ldmeqia    sp!,{r4,r5,r6,r7,r8,r9,r10,r11,pc}
    bl         func_020022d4
    ldr        r1,[r10,#0x8]
    ldr        r2,[r10,#0x1c]
    ldr        r11,[r10,#0x10]
    smull      r0,r4,r2,r1
    smull      r3,r2,r11,r1
    ldr        r5,[r10,#0x18]
    str        r2,[sp,#0x18]
    str        r3,[sp,#0x14]
    smull      r3,r2,r5,r1
    str        r2,[sp,#0x20]
    ldr        r2,[r10,#0x20]
    str        r3,[sp,#0x1c]
    str        r2,[sp,#0x10]
    ldr        r5,[sp,#0x10]
    ldmia      r10,{r3,lr}
    smull      r12,r5,lr,r5
    subs       r0,r12,r0
    ldr        r2,[r10,#0xc]
    sbc        r4,r5,r4
    smull      r1,r5,r2,r1
    str        r5,[sp,#0x28]
    mov        r5,r0, lsr #0xc
    ldr        r11,[r10,#0x14]
    orr        r5,r5,r4, lsl #0x14
    smull      r4,r2,lr,r11
    ldr        r0,[sp,#0x14]
    subs       r4,r4,r0
    ldr        r0,[sp,#0x18]
    mov        r4,r4, lsr #0xc
    sbc        r0,r2,r0
    orr        r4,r4,r0, lsl #0x14
    ldr        r0,[sp,#0x10]
    ldr        r2,[sp,#0x1c]
    smull      r12,r0,r3,r0
    subs       r2,r12,r2
    ldr        r12,[sp,#0x20]
    sbc        r0,r0,r12
    smull      r12,r11,r3,r11
    ldr        r3,[sp,#0x28]
    subs       r1,r12,r1
    sbc        r3,r11,r3
    mov        r11,r2, lsr #0xc
    orr        r11,r11,r0, lsl #0x14
    mov        r0,r1, lsr #0xc
    orr        r0,r0,r3, lsl #0x14
    str        r0,[sp,#0x24]
    bl         func_0200229c
    smull      r2,r1,r0,r5
    mov        r2,r2, lsr #0xc
    orr        r2,r2,r1, lsl #0x14
    rsb        lr,r2,#0x0
    smull      r2,r1,r0,r4
    mov        r4,r2, lsr #0xc
    orr        r4,r4,r1, lsl #0x14
    smull      r2,r1,r0,r11
    mov        r3,r2, lsr #0xc
    orr        r3,r3,r1, lsl #0x14
    ldr        r1,[sp,#0x24]
    umull      r11,r5,r0,r7
    smull      r2,r1,r0,r1
    mov        r2,r2, lsr #0xc
    orr        r2,r2,r1, lsl #0x14
    ldr        r1,[sp,#0x8]
    mov        r12,r0, asr #0x1f
    mla        r5,r0,r1,r5
    mla        r5,r12,r7,r5
    mov        r1,r11, lsr #0xc
    orr        r1,r1,r5, lsl #0x14
    stmia      r9,{r1,lr}
    str        r4,[r9,#0x8]
    ldr        r1,[sp,#0x4]
    umull      r5,r4,r0,r8
    mla        r4,r0,r1,r4
    mla        r4,r12,r8,r4
    mov        r1,r5, lsr #0xc
    orr        r1,r1,r4, lsl #0x14
    rsb        r1,r1,#0x0
    str        r1,[r9,#0xc]
    ldr        r1,[sp,#0xc]
    rsb        r2,r2,#0x0
    str        r3,[r9,#0x10]
    str        r2,[r9,#0x14]
    umull      r3,r2,r0,r6
    mla        r2,r0,r1,r2
    mla        r2,r12,r6,r2
    mov        r1,r3, lsr #0xc
    orr        r1,r1,r2, lsl #0x14
    str        r1,[r9,#0x18]
    ldr        r3,[r10,#0x0]
    ldr        r1,[r10,#0x1c]
    ldr        r2,[r10,#0x18]
    smull      r5,r4,r3,r1
    ldr        r1,[r10,#0x4]
    smull      r3,r1,r2,r1
    subs       r2,r5,r3
    sbc        r1,r4,r1
    mov        r2,r2, lsr #0xc
    orr        r2,r2,r1, lsl #0x14
    smull      r2,r1,r0,r2
    mov        r2,r2, lsr #0xc
    orr        r2,r2,r1, lsl #0x14
    rsb        r1,r2,#0x0
    str        r1,[r9,#0x1c]
    ldr        r4,[r10,#0x0]
    ldr        r3,[r10,#0x10]
    ldr        r2,[r10,#0xc]
    ldr        r1,[r10,#0x4]
    smull      r6,r5,r4,r3
    smull      r3,r1,r2,r1
    subs       r2,r6,r3
    sbc        r1,r5,r1
    mov        r2,r2, lsr #0xc
    orr        r2,r2,r1, lsl #0x14
    mov        r1,r2, asr #0x1f
    umull      r4,r3,r0,r2
    mla        r3,r0,r1,r3
    mla        r3,r12,r2,r3
    mov        r0,r4, lsr #0xc
    orr        r0,r0,r3, lsl #0x14
    str        r0,[r9,#0x20]
    ldr        r1,[r9,#0xc]
    ldr        r0,[r10,#0x28]
    ldr        r2,[r9,#0x0]
    smull      r5,r4,r1,r0
    ldr        r0,[r10,#0x24]
    ldr        r3,[r9,#0x18]
    smlal      r5,r4,r2,r0
    ldr        r1,[r10,#0x2c]
    add        r0,sp,#0x2c
    smlal      r5,r4,r3,r1
    mov        r1,r5, lsr #0xc
    orr        r1,r1,r4, lsl #0x14
    rsb        r1,r1,#0x0
    str        r1,[r9,#0x24]
    ldr        r2,[r9,#0x10]
    ldr        r1,[r10,#0x28]
    ldr        r3,[r9,#0x4]
    smull      r5,r4,r2,r1
    ldr        r1,[r10,#0x24]
    ldr        r2,[r9,#0x1c]
    smlal      r5,r4,r3,r1
    ldr        r1,[r10,#0x2c]
    cmp        r9,r0
    smlal      r5,r4,r2,r1
    mov        r1,r5, lsr #0xc
    orr        r1,r1,r4, lsl #0x14
    rsb        r1,r1,#0x0
    str        r1,[r9,#0x28]
    ldr        r2,[r9,#0x14]
    ldr        r1,[r10,#0x28]
    ldr        r3,[r9,#0x8]
    smull      r6,r5,r2,r1
    ldr        r1,[r10,#0x24]
    ldr        r4,[r9,#0x20]
    smlal      r6,r5,r3,r1
    ldr        r2,[r10,#0x2c]
    smlal      r6,r5,r4,r2
    mov        r1,r6, lsr #0xc
    orr        r1,r1,r5, lsl #0x14
    rsb        r1,r1,#0x0
    str        r1,[r9,#0x2c]
    bne        LAB_020013f8
    ldr        r1,[sp,#0x0]
    bl         func_02008a38
LAB_020013f8:
    mov        r0,#0x0
    add        sp,sp,#0x5c
    ldmia      sp!,{r4,r5,r6,r7,r8,r9,r10,r11,pc}
}

asm void func_02001404(Matrix43* param_1, Matrix43* param_2, Matrix43* param_3)
{
    stmdb      sp!,{r4,r5,r6,r7,r8,r9,r10,r11,lr}
    sub        sp,sp,#0x4c
    mov        r12,r2
    ldr        r2,[r0,#0x4]
    ldr        r3,[r1,#0xc]
    cmp        r12,r1
    smull      r7,r4,r2,r3
    ldr        r6,[r0,#0x0]
    ldr        r3,[r1,#0x0]
    addeq      r10,sp,#0x1c
    smlal      r7,r4,r6,r3
    ldr        r5,[r0,#0x8]
    ldr        r3,[r1,#0x18]
    movne      r10,r12
    smlal      r7,r4,r5,r3
    mov        r3,r7, lsr #0xc
    orr        r3,r3,r4, lsl #0x14
    str        r3,[r10,#0x0]
    ldr        r3,[r1,#0x10]
    ldr        r4,[r1,#0x4]
    smull      r8,r7,r2,r3
    smlal      r8,r7,r6,r4
    ldr        r3,[r1,#0x1c]
    smlal      r8,r7,r5,r3
    mov        r3,r8, lsr #0xc
    orr        r3,r3,r7, lsl #0x14
    str        r3,[r10,#0x4]
    ldr        r3,[r1,#0x14]
    ldr        r4,[r1,#0x8]
    smull      r8,r7,r2,r3
    smlal      r8,r7,r6,r4
    ldr        r2,[r1,#0x20]
    smlal      r8,r7,r5,r2
    mov        r5,r8, lsr #0xc
    orr        r5,r5,r7, lsl #0x14
    str        r5,[r10,#0x8]
    ldr        r8,[r0,#0x10]
    ldr        r9,[r0,#0xc]
    smull      r5,r3,r8,r3
    smlal      r5,r3,r9,r4
    ldr        r7,[r0,#0x14]
    mov        r6,r9, asr #0x1f
    smlal      r5,r3,r7,r2
    mov        r2,r5, lsr #0xc
    orr        r2,r2,r3, lsl #0x14
    str        r2,[r10,#0x14]
    ldr        r2,[r1,#0x10]
    ldr        r3,[r1,#0x4]
    smull      r5,r4,r8,r2
    smlal      r5,r4,r9,r3
    ldr        r3,[r1,#0x1c]
    mov        r2,r8, asr #0x1f
    smlal      r5,r4,r7,r3
    str        r2,[sp,#0x14]
    mov        r2,r5, lsr #0xc
    orr        r2,r2,r4, lsl #0x14
    str        r2,[r10,#0x10]
    mov        r2,r7, asr #0x1f
    ldr        r5,[r1,#0x0]
    str        r2,[sp,#0x0]
    ldr        r4,[r1,#0xc]
    ldr        lr,[r1,#0x18]
    mov        r2,r4, asr #0x1f
    str        r2,[sp,#0x4]
    mov        r2,r5, asr #0x1f
    str        r2,[sp,#0x8]
    umull      r2,r3,r7,lr
    mov        r11,lr, asr #0x1f
    mla        r3,r7,r11,r3
    str        r2,[sp,#0xc]
    ldr        r2,[sp,#0x0]
    ldr        r7,[sp,#0x8]
    mla        r3,r2,lr,r3
    umull      r11,r2,r9,r5
    mla        r2,r9,r7,r2
    mla        r2,r6,r5,r2
    ldr        r6,[sp,#0x4]
    umull      r9,r7,r8,r4
    mla        r7,r8,r6,r7
    ldr        r8,[sp,#0x14]
    adds       r6,r11,r9
    mla        r7,r8,r4,r7
    adc        r7,r2,r7
    ldr        r2,[sp,#0xc]
    adds       r6,r2,r6
    adc        r2,r3,r7
    mov        r3,r6, lsr #0xc
    orr        r3,r3,r2, lsl #0x14
    str        r3,[r10,#0xc]
    ldr        r3,[r0,#0x1c]
    ldr        r6,[r0,#0x18]
    smull      r7,r4,r3,r4
    smlal      r7,r4,r6,r5
    ldr        r2,[r0,#0x20]
    smlal      r7,r4,r2,lr
    mov        r5,r7, lsr #0xc
    orr        r5,r5,r4, lsl #0x14
    str        r5,[r10,#0x18]
    ldr        r4,[r1,#0x10]
    ldr        r5,[r1,#0x4]
    smull      r8,r4,r3,r4
    smlal      r8,r4,r6,r5
    ldr        r7,[r1,#0x1c]
    smlal      r8,r4,r2,r7
    mov        r5,r8, lsr #0xc
    orr        r5,r5,r4, lsl #0x14
    str        r5,[r10,#0x1c]
    ldr        r5,[r1,#0x14]
    ldr        r4,[r1,#0x8]
    smull      r8,r7,r3,r5
    smlal      r8,r7,r6,r4
    ldr        r3,[r1,#0x20]
    smlal      r8,r7,r2,r3
    mov        r2,r8, lsr #0xc
    orr        r2,r2,r7, lsl #0x14
    str        r2,[r10,#0x20]
    ldr        r2,[r0,#0x28]
    ldr        r9,[r0,#0x24]
    ldr        r7,[r0,#0x2c]
    smull      r5,r0,r2,r5
    smlal      r5,r0,r9,r4
    smlal      r5,r0,r7,r3
    mov        r3,r5, lsr #0xc
    orr        r3,r3,r0, lsl #0x14
    mov        r0,r7, asr #0x1f
    str        r0,[sp,#0x18]
    ldr        r0,[r1,#0x2c]
    mov        r11,r2, asr #0x1f
    adds       r0,r0,r3
    str        r0,[r10,#0x2c]
    ldr        r3,[r1,#0x10]
    ldr        r4,[r1,#0x4]
    smull      r6,r3,r2,r3
    smlal      r6,r3,r9,r4
    ldr        r5,[r1,#0x1c]
    ldr        r0,[r1,#0x28]
    smlal      r6,r3,r7,r5
    mov        r4,r6, lsr #0xc
    orr        r4,r4,r3, lsl #0x14
    adds       r0,r0,r4
    mov        r8,r9, asr #0x1f
    str        r0,[r10,#0x28]
    ldr        r4,[r1,#0x0]
    ldr        r3,[r1,#0xc]
    umull      r0,r5,r9,r4
    mov        lr,r4, asr #0x1f
    mla        r5,r9,lr,r5
    mov        r9,r3, asr #0x1f
    str        r0,[sp,#0x10]
    mla        r5,r8,r4,r5
    umull      r8,r0,r2,r3
    mla        r0,r2,r9,r0
    ldr        r4,[sp,#0x10]
    mla        r0,r11,r3,r0
    adds       r4,r4,r8
    adc        r2,r5,r0
    ldr        r6,[r1,#0x18]
    ldr        r8,[r1,#0x24]
    mov        r1,r6, asr #0x1f
    umull      r5,r3,r7,r6
    mla        r3,r7,r1,r3
    adds       r1,r5,r4
    ldr        r0,[sp,#0x18]
    mov        r1,r1, lsr #0xc
    mla        r3,r0,r6,r3
    adc        r0,r3,r2
    orr        r1,r1,r0, lsl #0x14
    adds       r0,r8,r1
    add        r4,sp,#0x1c
    cmp        r10,r4
    addne      sp,sp,#0x4c
    str        r0,[r10,#0x24]
    ldmneia    sp!,{r4,r5,r6,r7,r8,r9,r10,r11,pc}
    ldmia      r4!,{r0,r1,r2,r3}
    stmia      r12!,{r0,r1,r2,r3}
    ldmia      r4!,{r0,r1,r2,r3}
    stmia      r12!,{r0,r1,r2,r3}
    ldmia      r4,{r0,r1,r2,r3}
    stmia      r12,{r0,r1,r2,r3}
    add        sp,sp,#0x4c
    ldmia      sp!,{r4,r5,r6,r7,r8,r9,r10,r11,pc}
}

int func_020023d0(int*, int*);
void func_0200240c(int*, int*, int*);
void func_020024f0(int*, int*);

// https://decomp.me/scratch/TYwnN
asm void func_020016d8(int *param_1, int* param_2, int *param_3, int *param_4)
{
/*
    int tmp, tmp2;
    int x = param_1[0] - param_3[0];
    int y = param_1[1] - param_3[1];
    int z = param_1[2] - param_3[2];
    func_020024f0(&x, &x);
    func_0200240c(param_2, &x, &tmp);
    func_020024f0(&tmp, &tmp);
    func_0200240c(&x, &tmp, &tmp2);
    param_4[0] = tmp;
    param_4[1] = tmp2;
    param_4[2] = x;
    param_4[3] = 0;
    param_4[4] = 0;
    param_4[5] = y;
    param_4[6] = 0;
    param_4[7] = 0;
    param_4[8] = z;
    param_4[9] = -func_020023d0(param_1, &tmp);
    param_4[10] = -func_020023d0(param_1, &tmp2);
    param_4[11] = -func_020023d0(param_1, &x);
*/
    stmdb      sp!,{r3,r4,r5,r6,lr}
    sub sp, sp, #36
    mov r6, r0
    ldr r5, [r6]
    ldr r4, [r2]
    add r0, sp, #24
    sub r4, r5, r4
    str r4, [sp, #24]
    ldr ip, [r6, #4]
    ldr r4, [r2, #4]
    mov r5, r1
    sub r1, ip, r4
    str r1, [sp, #28]
    ldr r4, [r6, #8]
    ldr r2, [r2, #8]
    mov r1, r0
    sub r2, r4, r2
    mov r4, r3
    str r2, [sp, #32]
    bl  func_020024f0
    add r1, sp, #24
    add r2, sp, #12
    mov r0, r5
    bl  func_0200240c
    add r0, sp, #12
    mov r1, r0
    bl  func_020024f0
    add r0, sp, #24
    add r1, sp, #12
    add r2, sp, #0
    bl  func_0200240c
    ldr r1, [sp, #12]
    mov r0, r6
    str r1, [r4]
    ldr r2, [sp]
    add r1, sp, #12
    str r2, [r4, #4]
    ldr r2, [sp, #24]
    str r2, [r4, #8]
    ldr r2, [sp, #16]
    str r2, [r4, #12]
    ldr r2, [sp, #4]
    str r2, [r4, #16]
    ldr r2, [sp, #28]
    str r2, [r4, #20]
    ldr r2, [sp, #20]
    str r2, [r4, #24]
    ldr r2, [sp, #8]
    str r2, [r4, #28]
    ldr r2, [sp, #32]
    str r2, [r4, #32]
    bl  func_020023d0
    rsb r0, r0, #0
    str r0, [r4, #36]
    mov r0, r6
    add r1, sp, #0
    bl  func_020023d0
    rsb r0, r0, #0
    str r0, [r4, #40]
    mov r0, r6
    add r1, sp, #24
    bl  func_020023d0
    rsb r0, r0, #0
    str r0, [r4, #44]
    add sp, sp, #36
    ldmia      sp!,{r3,r4,r5,r6,pc}
}

// matrix 4x4 identity
asm void func_020017e0(Matrix44* matrix)
{
/*
matrix->data[0] = 0x1000;
matrix->data[1] = 0;
matrix->data[2] = 0;
matrix->data[3] = 0;
matrix->data[4] = 0;
matrix->data[5] = 0x1000;
matrix->data[6] = 0;
matrix->data[7] = 0;
matrix->data[8] = 0;
matrix->data[9] = 0;
matrix->data[10] = 0x1000;
matrix->data[11] = 0;
matrix->data[12] = 0;
matrix->data[13] = 0;
matrix->data[14] = 0;
matrix->data[15] = 0x1000;
*/
    mov        r2,#0x1000
    mov        r3,#0x0
    stmia      r0!,{r2,r3}
    mov        r1,#0x0
    stmia      r0!,{r1,r3}
    stmia      r0!,{r1,r2,r3}
    stmia      r0!,{r1,r3}
    stmia      r0!,{r1,r2,r3}
    stmia      r0!,{r1,r3}
    stmia      r0!,{r1,r2}
    bx         lr
}

// convert 4x4 to 4x3 (chop last column off)
asm void func_0200180c(Matrix44* m44, Matrix43* m43)
{
/*
m43->data[0] = m44->data[0];
m43->data[1] = m44->data[1];
m43->data[2] = m44->data[2];
m43->data[3] = m44->data[4];
m43->data[4] = m44->data[5];
m43->data[5] = m44->data[6];
m43->data[6] = m44->data[8];
m43->data[7] = m44->data[9];
m43->data[8] = m44->data[10];
m43->data[9] = m44->data[12];
m43->data[10] = m44->data[13];
m43->data[11] = m44->data[14];
*/
    ldmia      r0!,{r2,r3,r12}
    add        r0,r0,#0x4
    stmia      r1!,{r2,r3,r12}
    ldmia      r0!,{r2,r3,r12}
    add        r0,r0,#0x4
    stmia      r1!,{r2,r3,r12}
    ldmia      r0!,{r2,r3,r12}
    add        r0,r0,#0x4
    stmia      r1!,{r2,r3,r12}
    ldmia      r0!,{r2,r3,r12}
    add        r0,r0,#0x4
    stmia      r1!,{r2,r3,r12}
    bx         lr
}
