#include "arch/libc/config.h"

#ifndef HAVE_ARCH_MEMCPY
#include <string.h>

void *memcpy(void *dst, const void *src, size_t count)
{
	char *d = dst;
	const char *s = src;

	while (count--) {
		*d++ = *s++;
	}

	return dst;
}
#endif
