#ifndef MATRIX_H
#define MATRIX_H

#include "global.h"

typedef struct Matrix33 {
	s32 data[9];
} Matrix33;

typedef struct Matrix43 {
	s32 data[12];
} Matrix43;

typedef struct Matrix44 {
	s32 data[16];
} Matrix44;

#endif
