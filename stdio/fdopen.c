#include "libc/cdefs.h"
#include "libc/stdio.h"
#include <fcntl.h>
#include <errno.h>

FILE *fdopen(int fd, const char *mode)
{
	unsigned int oflags;
	unsigned int flags;
	FILE *S;

	if (__stdio_getmode(mode, &oflags, &flags)) {
		errno = EINVAL;
		return NULL;
	}

	S = __stdio_new();
	if (__unlikely(!S))
		return S;

	if (isatty(fd))
		flags |= SF_BUFLINE;
	else
		flags |= SF_BUFBLCK;

	S->fd = fd;
	S->flags = flags;
	insert_entry(S);

	return S;
}
