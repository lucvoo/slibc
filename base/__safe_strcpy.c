#include "libc/string.h"
#include "libc/cdefs.h"
#include <values/NULL.h>

// like strncpy, but:
//      - always null terminate
//      - null padding at the end
//      - return a pointer to the null
char *__safe_strcpy(char *dst, const char *src, unsigned int size)
{
	char *d = dst;
	const char *s = src;

	if (__unlikely(size == 0))
		return NULL;

	while (--size) {
		*d = *s;
		if (*s == '\0')
			return d;
		d++;
		s++;
	}
	// end of buffer reached

	*d = '\0';
	return d;
}
