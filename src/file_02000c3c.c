#include "matrix.h"

void func_02000c3c(s32* param_1, s32* param_2, s32 param_3, s32 param_4)
{
	param_2[0] = param_3 * (s64)param_1[0] >> 0xC;
	param_2[1] = param_3 * (s64)param_1[1] >> 0xC;
	param_2[2] = param_4 * (s64)param_1[2] >> 0xC;
	param_2[3] = param_4 * (s64)param_1[3] >> 0xC;
}

// set matrix to identity
asm void func_02000c94(struct Matrix *matrix)
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

void func_02000cb8(s32* param_1, s32* param_2, s32 param_3, s32 param_4, s32 param_5)
{
	param_2[0] = param_3 * (s64)param_1[0] >> 0xC;
	param_2[1] = param_3 * (s64)param_1[1] >> 0xC;
	param_2[2] = param_3 * (s64)param_1[2] >> 0xC;
	param_2[3] = param_4 * (s64)param_1[3] >> 0xC;
	param_2[4] = param_4 * (s64)param_1[4] >> 0xC;
	param_2[5] = param_4 * (s64)param_1[5] >> 0xC;
	param_2[6] = param_5 * (s64)param_1[6] >> 0xC;
	param_2[7] = param_5 * (s64)param_1[7] >> 0xC;
	param_2[8] = param_5 * (s64)param_1[8] >> 0xC;
}

#pragma thumb on

// matrix rotation (3D along x-axis)
void func_02000d78(struct Matrix* matrix, s32 sin_theta, s32 cos_theta)
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

// matrix rotation (3D along z-axis)
asm void func_02000db0(s32* param_1, s32 param_2, s32 param_3)
{
/*
param_1[0] = param_3;
param_1[1] = param_2;
param_1[2] = 0;
param_1[3] = -param_2;
param_1[4] = param_3;
param_1[5] = 0;
param_1[6] = 0;
param_1[7] = 0;
param_1[8] = 0x1000;
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
