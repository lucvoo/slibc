#include "arch/libc/config.h"

#ifndef HAVE_ARCH_STRLEN
#include <string.h>

size_t strlen(const char *src)
{
	const char *ptr = src;

	while (*ptr++) ;

	return --ptr - src;
}
#endif
