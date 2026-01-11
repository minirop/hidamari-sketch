#include "functions.h"

extern struct_data_02153964* data_02153964[];

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

struct_data_021539b8_41c_14* func_02033a40(u32 param_1, s32 param_2)
{
    if (param_1 <= 32)
    {
        struct_data_021539b8_41c_14* ptr = func_02015ec4(data_02153964[2]);
        if (ptr != 0)
        {
            return ptr;
        }
    }

    return func_02015ae8(data_02153964[1], param_1, param_2);
}

void func_02033a84(struct_data_02153964* param_1)
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
