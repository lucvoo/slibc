#include "arch/libc/config.h"

#ifndef HAVE_ARCH_STRNCPY
#include <string.h>

char *strncpy(char *restrict dst, const char *restrict src, size_t n)
{
	const char *end = dst + n;
	char *start = dst;

	// copy loop
	while (dst < end) {
		if ((*dst++ = *src++) == '\0')
			break;
	}

	// padding loop
	while (dst < end) {
		*dst++ = '\0';
	}

	return start;
}

#endif
