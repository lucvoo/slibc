#include "libc/getcycles.h"

uint64_t __getcycles(void)
{
	uint64_t cycles;

	__asm__ __volatile__(
		"mftbu	%0\n\t"
		"mftb	%L0"
		: "=r" (cycles));

	return cycles;
}
