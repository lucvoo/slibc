#include <stdlib.h>
#include "libc/rand48.h"

void srand48(long seed)
{
	__libc_rand48_state.x[0] = 0x330e;
	__libc_rand48_state.x[1] = seed & 0xffff;
	__libc_rand48_state.x[2] = (seed >> 16) & 0xffff;
	__libc_rand48_state.a = RAND48_A;
	__libc_rand48_state.c = RAND48_C;
}
