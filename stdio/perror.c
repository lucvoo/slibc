#include <stdio.h>
#include <errno.h>
#include "libc/errno.h"

void perror(const char *msg)
{
	const char *err;

	err = __strerror(errno);
	if (msg || msg[0]) {
		fputs(msg, stderr);
		fputs(": ", stderr);
	}
	fputs(err, stderr);
	fputc('\n', stderr);
}
