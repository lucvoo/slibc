#include "arch/libc/config.h"

#ifndef HAVE_ARCH_STRSEP
#include <string.h>

char *strsep(char **nxt, const char *delim)
{
	char *str = *nxt;
	char *end;

	if (!str)
		return NULL;

	end = strpbrk(str, delim);
	if (end)
		*end++ = '\0';
	*nxt = end;
	return str;
}

#endif
