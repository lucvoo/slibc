#include <string.h>
#include "libc/errno.h"
#include "libc/string.h"

int strerror_r(int errnum, char *buf, size_t size)
{
	const char *msg;

	msg = __strerror(errnum);
	__safe_strcpy(buf, msg, size);

	return 0;
}
