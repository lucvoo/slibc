#include "arch/libc/config.h"

#ifndef HAVE_ARCH_MEMSET
#include <string.h>

void *memset(void *dest, int c, size_t size)
{
	char *d = dest;

	while (size--)
		*d++ = c;

	return dest;
}
#endif
