#include "arch/libc/config.h"

#ifndef HAVE_ARCH_MEMCMP
#include <string.h>
#include "libc/cdefs.h"

int memcmp(const void *ptra, const void *ptrb, size_t count)
{
	unsigned char *a = (unsigned char *)ptra;
	unsigned char *b = (unsigned char *)ptrb;
	int d = 0;

	while (count--) {
		d = *a++ - *b++;

		if (__unlikely(d != 0))
			break;

	}

	return d;
}
#endif
