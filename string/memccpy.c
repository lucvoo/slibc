#include "arch/libc/config.h"

#ifndef HAVE_ARCH_MEMCCPY

#include <string.h>
#include "libc/cdefs.h"

void *memccpy(void *dst, const void *src, int c, size_t count)
{
	unsigned char *d = dst;
	const unsigned char *s = src;

	while (count--) {
		int val;

		*d++ = val = *s++;
		if (__unlikely(val == c))
			return d;
	}

	return NULL;
}
#endif
