#include "functions.h"

void func_0200d60c(struct_data_021539b8_callback_list * param_1, struct_data_021539b8_callback * param_2)
{
    struct_data_021539b8_callback* r2;

    if (param_1 == 0)
    {
        return;
    }

    r2 = param_1->unk_00;

    if (param_1->unk_00 == 0)
    {
        param_2->unk_08 = 0;
        param_1->unk_00 = param_2;
    }
    else
    {
        struct_data_021539b8_callback* r0;
        for (r0 = r2->unk_08; r0 != 0; r0 = r0->unk_08)
        {
            r2 = r0;
        }

        param_2->unk_08 = r0;
        r2->unk_08 = param_2;
    }
}
