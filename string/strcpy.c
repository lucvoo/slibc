#include "arch/libc/config.h"

#ifndef HAVE_ARCH_STRCPY
#include <string.h>

char *strcpy(char *restrict dest, const char *restrict src)
{
	char *orig;

	orig = dest;

	while ((*dest++ = *src++)) ;

	return orig;
}
#endif
