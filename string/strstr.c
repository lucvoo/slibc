#include "arch/libc/config.h"

#ifndef HAVE_ARCH_STRSTR
#include <string.h>

char *strstr(const char *haystack, const char *needle)
{
	size_t len;
	int c;

	len = strlen(needle);
	if (!len)
		return (char *)haystack;
	for (; (c = *haystack); haystack++) {
		if (*needle != c)
			continue;
		if (!__builtin_memcmp(haystack, needle, len))
			return (char *)haystack;
	}

	return NULL;
}

#endif
