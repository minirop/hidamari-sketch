#include "functions.h"

extern s32 data_02149238;
extern s32 data_02149244;

void func_0200d6c8(callback* ptr)
{
    func_0200d60c(&data_02149238, ptr);
}

void func_0200d6e0(callback* ptr)
{
    func_0200d5f8(&data_02149238, ptr);
}

void func_0200d6f8(callback* ptr)
{
    func_0200d60c(&data_02149244, ptr);
}

void func_0200d710(callback* ptr)
{
    func_0200d658(&data_02149238, ptr);
}

void func_0200d728(callback* ptr)
{
    func_0200d658(&data_02149244, ptr);
}

typedef struct struct_data_02149298 {
    u16 unk_00;
    STRUCT_PAD(0x02, 0x0c);
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    STRUCT_PAD(0x1c, 0x28);
    s32 unk_28;
} struct_data_02149298;
extern struct_data_02149298 data_02149298;

void func_0200d860(s32, s32, s32);

void func_0200d740()
{
    if (data_02149298.unk_00)
    {
        return;
    }

    data_02149298.unk_00 = 1;
    data_02149298.unk_0c = 0;
    data_02149298.unk_10 = 0;
    data_02149298.unk_28 = 0;
    data_02149298.unk_14 = 0;
    data_02149298.unk_18 = 0;

    func_0200a174();

    while (func_0200a2cc(5, 1) == 0)
    {
        // wait
    }

    func_0200a280(5, func_0200d860);
}
