#include "arch/libc/config.h"

#ifndef HAVE_ARCH_STPCPY
#include <string.h>

char *stpcpy(char *dest, const char *src)
{
	char *d = dest;
	const char *s = src;

	do {
		*d++ = *s;
	} while (*s++ != '\0');

	return (d - 1);
}
#endif
