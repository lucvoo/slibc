#include "libc/rand48.h"

struct rand48 __libc_rand48_state = {.a = RAND48_A,
	.c = RAND48_C,
	.x = {0, 0, 0},
	.oldx = {0, 0, 0},
};

void __libc_rand48_iter(unsigned short buf[3])
{
	uint64_t x;

	x = __libc_rand48_mk64(buf[2], buf[1], buf[0]);
	x = __libc_rand48_state.a * x + __libc_rand48_state.c;

	buf[0] = x;
	buf[1] = x >> 16;
	buf[2] = x >> 32;
}
