#include "functions.h"

void func_020080fc()
{
    while (1)
    {
        func_02007f18();
        func_0200810c();
    }
}

// asm void func_0200810c()
// {
//     mov r0, #0x0
//     mcr 15, 0, r0, cr7, cr0, {4}
//     bx  lr
// }
