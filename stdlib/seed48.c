#include <stdlib.h>
#include "libc/rand48.h"

unsigned short *seed48(unsigned short buf[3])
{
	__libc_rand48_state.oldx[0] = __libc_rand48_state.x[0];
	__libc_rand48_state.x[0] = buf[0];
	__libc_rand48_state.oldx[1] = __libc_rand48_state.x[1];
	__libc_rand48_state.x[1] = buf[1];
	__libc_rand48_state.oldx[2] = __libc_rand48_state.x[2];
	__libc_rand48_state.x[2] = buf[2];
	__libc_rand48_state.a = RAND48_A;
	__libc_rand48_state.c = RAND48_C;

	return __libc_rand48_state.oldx;
}
