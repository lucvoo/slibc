#include "arch/libc/config.h"

#ifndef HAVE_ARCH_STRCHR
#include <string.h>
#include "libc/cdefs.h"

char *strchr(const char *s, int c)
{
	int val;

	while (1) {
		val = *s++;
		if ((val == c) || (val == '\0'))
			break;
	}

	if (val == '\0')
		return NULL;
	else
		return (char *)--s;
}

#include "libc/symbols.h"
char *index(const char *, int) __alias(strchr);

#endif
