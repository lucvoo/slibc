#include <string.h>
#include "libc/errno.h"
#include "libc/string.h"

const char *__strerror(int errnum)
{
	const char *msg = NULL;

	if ((unsigned int)errnum < __sys_errsize) {
		msg = __sys_errlist[errnum];
	}
	if (!msg)
		msg = "Unknown error";

	return msg;
}
