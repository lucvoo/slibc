#include "arch/libc/config.h"

#ifndef HAVE_ARCH_STRNCAT
#include <string.h>

char *strncat(char *dst, const char *src, size_t n)
{
	char *ori = dst;

	if (!n)
		return ori;

	while (*dst)
		dst++;
	while ((*dst++ = *src++)) {
		if (--n == 0) {
			*dst = '\0';
			break;
		}
	}

	return ori;
}
#endif
