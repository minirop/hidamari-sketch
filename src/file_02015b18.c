#include "functions.h"

void func_02015b18(struct_unk_HTNU_HPXE_format* format, struct_data_02153964* param_2)
{
    u32 auStack_18[2];
    // fake match
    struct_temp_02015b18* sub4 = (struct_temp_02015b18*)(param_2 - 4);
    func_020155ac(auStack_18, sub4);
    func_020155d8(format->unk_2c, sub4);
    func_020159b4(&format->unk_24, auStack_18);
}
