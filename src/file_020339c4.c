#include "functions.h"

extern int data_02153964[];

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
