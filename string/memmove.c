#include "arch/libc/config.h"

#ifndef HAVE_ARCH_MEMMOVE
#include <string.h>

void *memmove(void *dst, const void *src, size_t n)
{
	const char *s = src;
	char *d = dst;

	if (dst <= src) {
		while (n--)
			*d++ = *s++;
	} else {
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}

	return dst;
}

#endif
