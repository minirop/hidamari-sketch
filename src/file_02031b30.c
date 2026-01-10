#include "functions.h"

void func_02031b30(struct_data_021539b8_404* param)
{
    func_02031e58(param);
    func_02031b48(param);
}

s32 func_0200609c();
s32 func_0200e248();
s32 func_0200e950(s32);
void func_0200e2a4(u16);
void func_02006104(u16);
void func_0200e294(u16);
bool func_02031b48(struct_data_021539b8_404* param)
{
    bool ret = false;
    s32 tmp, tmp2;

    param->unk_04 = -3;
    param->unk_08 = 0;

    tmp = func_0200609c();

    if (tmp != -3)
    {
        func_0200e294(tmp);
        tmp2 = func_0200e950(0x0d01);

        if (tmp2 == 1)
        {
            ret = true;
        }
        else
        {
            param->unk_08 = func_0200e248();
        }

        func_0200e2a4(tmp);
        func_02006104(tmp);
    }

    return ret;
}
