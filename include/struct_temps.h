#ifndef STRUCT_TEMPS_H
#define STRUCT_TEMPS_H

#include "global.h"

// structures that are meant to be temporary (because unknown)
// should be moved to their own file once "set in stone"

typedef struct struct_temp_02015b18_08_0c {
    STRUCT_PAD(0x00, 0x04);
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
} struct_temp_02015b18_08_0c;

typedef struct struct_temp_02015b18 {
    u16 unk_00;
    u16 unk_02;
    u32 unk_04;
    struct_temp_02015b18_08_0c* unk_08;
    struct_temp_02015b18_08_0c* unk_0c;
    u32* unk_10;
} struct_temp_02015b18;

#endif
