#include "functions.h"

// must be the last function otherwise the call to func_0200810c
// becomes a relative jump: "bl 8"
void func_020080fc()
{
    while (1)
    {
        func_02007f18();
        func_0200810c();
    }
}
