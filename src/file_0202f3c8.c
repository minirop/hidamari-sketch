#include "functions.h"

extern struct_data_021539b8 data_021539b8;

struct_data_021539b8_404* func_020340ec(struct_data_021539b8*);
struct_func_0202c138* func_020340e4(struct_data_021539b8*);

extern u16 data_027fffa8;

void func_0202f3c8(struct_data_021539b8_41c *param_1)
{
    struct_data_021539b8_404* piVar3;
    struct_func_0202c138* piVar2;
    bool bVar;
    u32 uVar2;
    s64 lVar1;
    u32 uVar4;
    int sp10[3], sp04[3];
    func_0202c138(&param_1->unk_10b8, "Font/HSfont.NFTR", 1, 1);
    func_0202c138(&param_1->unk_10d8, "Font/HSfont.NSCR", 1, 1);
    func_0202c138(&param_1->unk_1108, "Font/HSfont.NCLR", 1, 1);
    func_0202c138(&param_1->unk_1148, "Font/HSfont.NCLR", 1, 1);
    func_0200d828(sp10, sp04);

    uVar4 = sp10[2] +
            sp10[1] * 0x3c +
            sp10[0] * 0xe10 +
            sp04[2] * 0x15180 +
            sp04[1] * 0x278D00 +
            sp04[0] * 0x1DA9C00;

    lVar1 = (0x80008001 * uVar4 >> 0x2f) * 0x0000FFFF;
    func_020337bc(uVar4 - lVar1, lVar1 >> 0x20);
    uVar2 = func_020337e4(0);
    func_02033848(uVar2, 0);

    param_1->unk_11a8 = 1;

    piVar3 = func_020340ec(&data_021539b8);
    func_0202edd0(&param_1->unk_fc, piVar3);
    func_0203b4bc(&param_1->unk_7c4, 0, 0x80, 0, 0x80);

    piVar2 = func_020340e4(&data_021539b8);
    func_020364f8(piVar2, "SOUND/sound_data.sdat", 1);

    piVar2 = func_020340e4(&data_021539b8);
    func_020365b4(piVar2, 0);
    func_020340e4(&data_021539b8);
    func_020365fc();

    param_1->unk_08 = 0;
    param_1->unk_04 = 0;
    param_1->unk_10 = 0;

    func_0202f964(param_1, 1);
    func_020340cc(&data_021539b8);
    func_02036b88();
}

#define RAM_027FFFA8 (*(vu16*)0x027fffa8)

void func_0202f578(struct_data_021539b8_41c *param_1)
{
    s32 lVar3;

    func_02004314();
    if (param_1->unk_08 != param_1->unk_04) {
        func_0202f774(param_1, param_1->unk_08, param_1->unk_0c);
        func_02034024(&data_021539b8);
        func_02034094(&data_021539b8);
        param_1->unk_14->unk_00->unk_10();
        func_02034024(&data_021539b8);
    }

    param_1->unk_14->unk_00->unk_0c();

    if (param_1->unk_11a8 != 0)
    {
        struct_data_021539b8_58* tmp = func_020340dc(&data_021539b8);
        if (tmp->unk_124 != 0)
        {
            GFX_FIFO_SWAP = 0;
        }
        else
        {
            GFX_FIFO_SWAP = 1;
        }
    }

    func_02034094(&data_021539b8);
    func_02026d6c();
    param_1->unk_14->unk_00->unk_10();
    func_0203b868(&param_1->unk_7c4);

    lVar3 = ((s32)(RAM_027FFFA8 & 0x8000)) >> 0xf;

    if (lVar3 != 0)
    {
        if (param_1->unk_11a9 != 0)
        {
            func_0203415c(&data_021539b8);
        }
    }
}
