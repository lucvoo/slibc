#include "arch/libc/config.h"

#ifndef HAVE_ARCH_STPNCPY
#include <string.h>

char *stpncpy(char *restrict dst, const char *restrict src, size_t n)
{
	const char *end = dst + n;

	// copy loop
	while (dst < end) {
		if ((*dst++ = *src++) == '\0')
			break;
	}

	// padding loop
	while (dst < end) {
		*dst++ = '\0';
	}

	return dst - 1;
}

#endif
