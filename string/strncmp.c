#include "arch/libc/config.h"

#ifndef HAVE_ARCH_STRNCMP
#include <string.h>

int strncmp(const char *s1, const char *s2, size_t n)
{
	int rc = 0;

	while (n--) {
		int c1 = *s1++;
		int c2 = *s2++;

		if ((rc = c1 - c2) || !c1)
			break;
	}

	return rc;
}

#endif
