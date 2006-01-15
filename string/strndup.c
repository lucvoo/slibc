#include <string.h>
#include <stdlib.h>
#include "libc/cdefs.h"

char *strndup(const char *str, size_t size)
{
	char *buf;
	size_t len;

	len = strlen(str);
	if (len > size)
		len = size;
	buf = malloc(len + 1);
	if (__unlikely(!buf))
		return NULL;

	memcpy(buf, str, len);
	buf[len] = '\0';

	return buf;
}
