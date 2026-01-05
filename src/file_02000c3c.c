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
asm void func_02000c94(struct Matrix33 *matrix)
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
void func_02000cb8(struct Matrix33* param_1, struct Matrix33* param_2, s32 param_3, s32 param_4, s32 param_5)
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
void func_02000d78(struct Matrix33* matrix, s32 sin_theta, s32 cos_theta)
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
asm void func_02000d94(struct Matrix33* matrix, s32 sin_theta, s32 cos_theta)
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
asm void func_02000db0(struct Matrix33* matrix, s32 sin_theta, s32 cos_theta)
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
asm void func_02000dc8(struct Matrix33 *param_1, struct Matrix33 *param_2, struct Matrix33 *param_3)
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

// set matrix 4x3 identity
asm void func_02000fe8(struct Matrix43* matrix)
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

asm void func_02001010(struct Matrix43* source, struct Matrix44* dest)
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
