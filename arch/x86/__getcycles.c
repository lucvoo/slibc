#include "libc/getcycles.h"

uint64_t __getcycles(void)
{
	uint64_t cycles = 0;

	__asm__ __volatile__( "rdtsc" : "=A" (cycles));

	return cycles;
}
