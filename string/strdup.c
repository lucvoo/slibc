#include <string.h>
#include <stdlib.h>
#include "libc/cdefs.h"

char *strdup(const char *str)
{
	char *buf;
	char *res;
	size_t len;

	len = strlen(str);
	buf = malloc(len + 1);
	if (__unlikely(!buf))
		return NULL;

	res = strcpy(buf, str);

	return res;
}
