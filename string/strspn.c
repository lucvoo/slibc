#include "arch/libc/config.h"

#ifndef HAVE_ARCH_STRSPN
#include <string.h>

size_t strspn(const char *src, const char *charset)
{
	size_t n = 0;
	int s;

	while ((s = *src++)) {
		const char *ptr = charset;
		int c;

		while ((c = *ptr++)) {
			if (s == c)
				break;
		}
		if (!c)
			return n;

		n++;
	}

	return n;
}

#endif
