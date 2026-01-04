#include "global.h"

extern "C" void func_02000c3c(s32* param_1, s32* param_2, s32 param_3, s32 param_4);

void func_02000c3c(s32* param_1, s32* param_2, s32 param_3, s32 param_4)
{
	u64 tmp = param_3;
	tmp *= param_1[0];
	param_2[0] = (tmp >> 0xC);
	tmp = param_3;
	tmp *= param_1[1];
	param_2[1] = (tmp >> 0xC);
	tmp = param_4;
	tmp *= param_1[2];
	param_2[2] = (tmp >> 0xC);
	tmp = param_4;
	tmp *= param_1[3];
	param_2[3] = (tmp >> 0xC);
}
