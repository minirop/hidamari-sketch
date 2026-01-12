#include "functions.h"

struct_temp_02015b18_08_0c* func_020155d8(struct_temp_02015b18_08_0c**, struct_temp_02015b18_08_0c*);
s32 func_020159b4(struct_temp_02015b18_08_0c** param_1, struct_temp_02015b18_08_0c** param_2)
{
    struct_temp_02015b18_08_0c* local_18 = param_2[0];
    struct_temp_02015b18_08_0c* local_14 = param_2[1];

    struct_temp_02015b18_08_0c* ptr2 = 0;
    if (param_1[0])
    {
        ptr2 = param_1[0];
        while (param_1[0]->unk_0c)
        {
            if (param_2[0] != 0)
            {
                if (param_2[0] != param_2[1])
                {
                    param_1[0]->unk_04;
                    func_020155d8(param_1, 0);
                }

                break;
            }
        }
    }

    if (ptr2 != 0)
    {
        ptr2 = func_020155d8(param_1, ptr2);
    }

    if (0xf < local_14 - local_18) {
        struct_temp_02015b18_08_0c* uVar3 = func_02015630(&local_18, 0x4652);
        func_02015600(param_1, uVar3, ptr2);
        return 1;
    }

    return 0;
}
