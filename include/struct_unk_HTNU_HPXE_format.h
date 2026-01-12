#ifndef STRUCT_UNK_HTNU_HPXE_FORMAT_H
#define STRUCT_UNK_HTNU_HPXE_FORMAT_H

#include "global.h"
#include "struct_data_0214a748.h"

typedef struct struct_unk_HTNU_HPXE_format {
    u32 magic;
    struct struct_unk_HTNU_HPXE_format* unk_04;
    STRUCT_PAD(0x08, 0x0c);
    struct struct_data_0214a748 unk_0c;
    struct_data_02153964* unk_18;
    struct_data_02153964* unk_1c;
    STRUCT_PAD(0x20, 0x24);
    struct_data_02153964* unk_24;
    STRUCT_PAD(0x28, 0x2c);
    u32 unk_2c[2];
} struct_unk_HTNU_HPXE_format;

#endif
