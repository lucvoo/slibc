#ifndef _RAND48_H_
#define _RAND48_H

#include <stdint.h>

// FIXME: only works if sizeof(short) == 16 !!!

#define RAND48_A	0x5deece66duLL
#define RAND48_C	0xB

struct rand48 {
	uint64_t		a;
	uint16_t		c;
	uint16_t		x[3];
	uint16_t		oldx[3];
};

extern struct rand48 __libc_rand48_state;

static inline uint64_t __libc_rand48_mk64(uint16_t x2, uint16_t x1, uint16_t x0)
{
	return (uint64_t) x2 << 32 | (uint32_t) x1 << 16 | x0;
}

void __libc_rand48_iter(uint16_t buf[3]);

#endif
