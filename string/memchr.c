#include "arch/libc/config.h"

#ifndef HAVE_ARCH_MEMCHR
#include <string.h>

void *memchr(const void *s, int _c, size_t n)
{
	const unsigned char *p = s;
	unsigned char c = _c;

	while (n--) {
		if (c == *p)
			return (void *)p;
		p++;
	}

	return NULL;
}

#endif
