#include "arch/libc/config.h"

#ifndef HAVE_ARCH_STRPBRK
#include <string.h>

char *strpbrk(const char *s1, const char *s2)
{
	int c1;

	for (; (c1 = *s1); ++s1) {
		const char *ptr2 = s2;
		int c2;

		while ((c2 = *ptr2++)) {
			if (c1 == c2)
				return (char *)s1;
		}
	}

	return NULL;
}

#endif
