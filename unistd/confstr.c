#include <unistd.h>
#include <errno.h>
#include "libc/string.h"

#define CS_PATH	"/bin:/usr/bin"

size_t confstr(int name, char *buf, size_t len)
{
	const char *str;
	size_t rlen;

	switch (name) {
	case _CS_PATH:
		str = CS_PATH;
		rlen = sizeof(CS_PATH);
		break;

// FIXME: should support _CS_POSIX_V6_*

	default:
		errno = EINVAL;
		return 0;
	}

	__safe_strcpy(buf, str, len);

	return rlen;
}
