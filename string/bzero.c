#include <strings.h>

void bzero(void *dest, size_t size)
{
	char *d = dest;

	while (size--)
		*d++ = 0;
}

#include "libc/link_warning.h"
warn_legacy(bzero, "memset");
