#include "arch/libc/config.h"

#ifndef HAVE_ARCH_STRCAT
#include <string.h>

char *strcat(char *dst, const char *src)
{
	char *ptr = dst;

	while (*ptr)
		ptr++;
	while ((*ptr++ = *src++)) ;

	return dst;
}

#endif
