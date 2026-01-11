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
