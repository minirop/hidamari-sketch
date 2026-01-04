#include "global.h"

void func_02000c3c(s32* param_1, s32* param_2, s32 param_3, s32 param_4);
void func_02000c94(s32 *param_1);
void func_02000cb8(s32* param_1, s32* param_2, s32 param_3, s32 param_4, s32 param_5);

void func_02000c3c(s32* param_1, s32* param_2, s32 param_3, s32 param_4)
{
	param_2[0] = param_3 * (s64)param_1[0] >> 0xC;
	param_2[1] = param_3 * (s64)param_1[1] >> 0xC;
	param_2[2] = param_4 * (s64)param_1[2] >> 0xC;
	param_2[3] = param_4 * (s64)param_1[3] >> 0xC;
}

asm void func_02000c94(s32 *param_1)
{
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
