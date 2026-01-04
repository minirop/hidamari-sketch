#ifndef MATRIX_H
#define MATRIX_H

#include "global.h"

struct Matrix {
	s32 data[9];
};

void func_02000d78(struct Matrix* matrix, s32 sin_theta, s32 cos_theta);

#endif
