#ifndef MATRIX_H
#define MATRIX_H

#include "global.h"

struct Matrix33 {
	s32 data[9];
};

struct Matrix43 {
	s32 data[12];
};

struct Matrix44 {
	s32 data[16];
};

void func_02000d78(struct Matrix33* matrix, s32 sin_theta, s32 cos_theta);

#endif
