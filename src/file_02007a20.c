#include "functions.h"

extern u32 data_02147520;
extern u32 data_02147524;

u64 func_02007a20()
{
    u32 t, x, y;
    u64 a, b;

    func_02007f18();

    t = REG_TIM0CNT_L;
    x = data_02147520 & (0xFFFF - 0x10000);
    y = data_02147524 & 0xFFFF;

    if ((REG_IF & 8) != 0)
    {
        u32 b = (0xfffffffe < x);
        x++;
        y += b;
    }

    func_02007f2c();

    a = (x << 16) | (y >> 16);
    b = (y << 16) | (t >> 16);
    return (a << 32) | b;
}
