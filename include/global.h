#ifndef GLOBAL_H
#define GLOBAL_H

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long s32;

typedef unsigned long long int u64;
typedef signed long long int s64;

typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile u64 vu64;

typedef volatile s8 vs8;
typedef volatile s16 vs16;
typedef volatile s32 vs32;
typedef volatile s64 vs64;

typedef float f32;
typedef volatile f32 vf32;

typedef s32 bool;
#define true 1
#define false 0

#define STRUCT_PAD(from, to) unsigned char _pad_ ## from[(to) - (from)]
#define STRUCT_PAD_SIZED(from, to, name) unsigned char _pad_ ## from[(to) - (from) - sizeof(name)]

typedef void (*callback)();
typedef void (*callback_0200a280)(s32, s32, s32);

#include "hardware.h"

#endif
