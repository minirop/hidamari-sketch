#ifndef STRUCT_DATA_021539B8_H
#define STRUCT_DATA_021539B8_H

#include "global.h"
#include "struct_data_02153964.h"

typedef struct struct_data_021539b8_30 {
    s32 unk_00;
    u64 unk_04;
    s32 unk_0c;
    s32 unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1c;
    s32 unk_20;
    s32 unk_24;
} struct_data_021539b8_30;

typedef struct struct_data_021539b8_58 {
    STRUCT_PAD(0x00, 0x124);
    u8 unk_124;
    u8 unk_125;
    u8 unk_126;
    u8 unk_127;
} struct_data_021539b8_58;

typedef struct struct_data_021539b8_32c {
    u32 pad;
} struct_data_021539b8_32c;

typedef struct struct_data_021539b8_404 {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    s32 unk_04;
    s32 unk_08;
    u8 unk_0c;
    u8 unk_0d;
    u8 unk_0e;
    u8 unk_0f;
    s32 unk_10;
    s32 unk_14;
} struct_data_021539b8_404;

typedef struct struct_func_0202c138 {
    u32 unk_00;
} struct_func_0202c138;

typedef struct struct_func_02039c5c {
    s32 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0c;
    s32 unk_10;
} struct_func_02039c5c;

typedef struct struct_data_021539b8_41c_14 struct_data_021539b8_41c_14;

typedef struct struct_data_021539b8_41c_14_00 {
    STRUCT_PAD(0x00, 0x04);
    callback unk_04;
    void (*unk_08)(struct struct_data_021539b8_41c_14*, u32);
    callback unk_0c;
    callback unk_10;
} struct_data_021539b8_41c_14_00;

struct struct_data_021539b8_41c_14 {
    struct_data_021539b8_41c_14_00* unk_00;
};

typedef struct struct_data_021539b8_41c_7c4 {
    u32 unk_00;
} struct_data_021539b8_41c_7c4;

typedef struct struct_data_021539b8_41c {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    struct_data_021539b8_41c_14* unk_14;
    STRUCT_PAD(0x18, 0xfc);
    u32 unk_fc;
    STRUCT_PAD(0x100, 0x32c);
    struct_func_0202c138* unk_32c;
    STRUCT_PAD(0x330, 0x79c);
    struct_func_0202c138 unk_79c;
    STRUCT_PAD_SIZED(0x79c, 0x7b0, struct_func_0202c138);
    struct_func_0202c138 unk_7b0;
    STRUCT_PAD_SIZED(0x7b0, 0x7c4, struct_func_0202c138);
    struct_data_021539b8_41c_7c4 unk_7c4;
    STRUCT_PAD_SIZED(0x7c4, 0x10b4, struct_data_021539b8_41c_7c4);
    u8 unk_10b4;
    u8 unk_10b5;
    u8 unk_10b6;
    u8 unk_10b7;
    struct_func_0202c138* unk_10b8;
    STRUCT_PAD(0x10bc, 0x10d8);
    struct_func_0202c138* unk_10d8;
    STRUCT_PAD(0x10dc, 0x1108);
    struct_func_0202c138* unk_1108;
    STRUCT_PAD(0x110c, 0x1148);
    struct_func_0202c138* unk_1148;
    STRUCT_PAD(0x114c, 0x11a8);
    u8 unk_11a8;
    u8 unk_11a9;
    u8 unk_11aa;
    u8 unk_11ab;
} struct_data_021539b8_41c;

typedef struct struct_data_021539b8_callback {
    callback unk_00;
    s32 unk_04;
    struct struct_data_021539b8_callback* unk_08;
} struct_data_021539b8_callback;

// because of func_0200d60c (name is random)
typedef struct struct_data_021539b8_callback_list {
    struct_data_021539b8_callback* unk_00;
} struct_data_021539b8_callback_list;

typedef struct struct_data_021539b8 {
    s32 unk_00;
    struct_data_02153964* unk_04;
    STRUCT_PAD(0x08, 0x30);
    struct_data_021539b8_30 unk_30;
    struct_data_021539b8_58 unk_58;
    STRUCT_PAD_SIZED(0x58, 0x2e4, struct_data_021539b8_58);
    s32 unk_2e4;
    STRUCT_PAD(0x2e8, 0x404);
    struct_data_021539b8_404 unk_404;
    struct_data_021539b8_41c unk_41c;
    STRUCT_PAD_SIZED(0x41c, 0x1e20, struct_data_021539b8_41c);
    s8 unk_1e20;
    s8 unk_1e21;
    s8 unk_1e22;
    s8 unk_1e23;
    struct_data_021539b8_callback unk_1e24;
    struct_data_021539b8_callback unk_1e30;
} struct_data_021539b8;

#endif
