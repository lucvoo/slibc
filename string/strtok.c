#include "arch/libc/config.h"

#ifndef HAVE_ARCH_STRTOK
#include <string.h>

static char *pos;

char *strtok(char *s, const char *delim)
{
	return strtok_r(s, delim, &pos);
}
#endif
