#include "arch/libc/config.h"

#ifndef HAVE_ARCH_STRNLEN
#include <string.h>

size_t strnlen(const char *src, size_t n)
{
	const char *ptr = src;

	for (; n-- && *ptr; ++ptr) ;

	return ptr - src;
}

#endif
