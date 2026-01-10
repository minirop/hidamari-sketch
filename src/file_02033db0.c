#include "functions.h"

void func_02033db0(struct_data_021539b8* param_1)
{
    func_02007930();
    func_02007b4c();
    func_0200282c();
    func_0200d740();
    func_02033f64(param_1);
    func_02033f40(param_1);
    func_0203222c(&param_1->unk_58);
    func_02033fdc(param_1);
    func_02033f1c(param_1);
    func_02036aec(&param_1->unk_2e4);
    func_02031b30(&param_1->unk_404);
    func_020369a0(&param_1->unk_30);
    param_1->unk_1e24.unk_00 = func_02034154;
    param_1->unk_1e24.unk_04 = 0;
    param_1->unk_1e30.unk_00 = func_02034158;
    param_1->unk_1e30.unk_04 = 0;
    func_0200d6c8(&param_1->unk_1e24);
    func_0200d6f8(&param_1->unk_1e30);
    param_1->unk_1e20 = 1;
}

void func_02033e5c(struct_data_021539b8* param_1)
{
    param_1->unk_1e20 = 0;
    func_0200d710(&param_1->unk_1e24);
    func_0200d728(&param_1->unk_1e30);
    if (param_1->unk_04 != 0)
    {
        func_02033a84(param_1->unk_04);
    }
}

void func_02033e9c(struct_data_021539b8* param_1)
{
    func_0202f3c8(&param_1->unk_41c);
    while (1)
    {
        func_02034024(param_1);
        func_0202f578(&param_1->unk_41c);
    }
}
