#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "libc/setenv.h"

int setenv(const char *name, const char *value, int overwrite)
{
	char *str;
	size_t nlen, vlen;

	if (!name || name[0] == '\0' || strchr(name, '=')) {	// FIXME: should check for 'value == NULL' ???
		errno = EINVAL;
		return -1;
	}

	nlen = strlen(name);
	vlen = strlen(value) + 1;
	str = malloc(nlen + 1 + vlen);
	if (!str)
		return -1;

	memcpy(str, name, nlen);
	nlen++;
	str[nlen] = '=';
	memcpy(str + nlen, value, vlen);

	return __libc_setenv(str, nlen, overwrite);
}
