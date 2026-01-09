#ifndef STRUCT_DATA_021539B8_H
#define STRUCT_DATA_021539B8_H

#include "global.h"

typedef struct struct_data_021539b8_30 {
    s32 unk_0x00;
    s32 unk_0x04; // might be
    s32 unk_0x08; // s64
    s32 unk_0x0c;
    s32 unk_0x10;
    s32 unk_0x14;
    s32 unk_0x18;
    s32 unk_0x20;
    s32 unk_0x1c;
} struct_data_021539b8_30;

typedef struct struct_data_021539b8_58 {
	u32 pad;
} struct_data_021539b8_58;

typedef struct struct_data_021539b8_404 {
	u8 unk_00;
	u8 unk_01;
	u8 unk_02;
	u8 unk_03;
	s32 unk_04;
	s32 unk_08;
	s32 unk_0C;
	s32 unk_10;
	s32 unk_14;
} struct_data_021539b8_404;

typedef struct struct_data_021539b8_41c {
	STRUCT_PAD(0x00, 0x800);
} struct_data_021539b8_41c;

typedef struct struct_data_021539b8 {
	s32 unk_00;
	s32 unk_04;
	STRUCT_PAD(0x08, 0x30);
	struct_data_021539b8_30 unk_30;
	STRUCT_PAD(0x54, 0x58);
	struct_data_021539b8_58 unk_58;
	STRUCT_PAD(0x5c, 0x2e4);
	s32 unk_2e4;
	STRUCT_PAD(0x2e8, 0x404);
	struct_data_021539b8_404 unk_404;
	struct_data_021539b8_41c unk_41c;
	STRUCT_PAD(0xc1c, 0x1e20);
	s8 unk_1e20;
	s8 unk_1e21;
	s8 unk_1e22;
	s8 unk_1e23;
	callback unk_1e24;
	s32 unk_1e28;
	s32 unk_1e2C;
	callback unk_1e30;
	s32 unk_1e34;
} struct_data_021539b8;

#endif
