#include "arch/libc/config.h"

#ifndef HAVE_ARCH_STRRCHR
#include <string.h>

char *strrchr(const char *s, int c)
{
	const char *found = NULL;
	int v;

	do
		if ((v = *s++) == c)
			found = s - 1;
	while (v != 0) ;

	return (char *)found;
}

#include "libc/symbols.h"
char *rindex(const char *, int) __alias(strrchr);

#endif
