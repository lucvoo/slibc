#include "arch/libc/config.h"

#ifndef HAVE_ARCH_STRCMP
#include <string.h>

int strcmp(const char *s1, const char *s2)
{
	int rc;

	while (1) {
		int c1 = *s1++;
		int c2 = *s2++;
		if ((rc = c1 - c2) || !c1)
			break;
	}

	return rc;
}

#endif
