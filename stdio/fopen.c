#include "libc/stdio.h"
#include <fcntl.h>
#include <stdlib.h>			// for free()
#include <errno.h>

FILE *fopen(const char *restrict file, const char *restrict mode)
{
	int fd;
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

	fd = open(file, oflags, 0666);
	if (__unlikely(fd == -1)) {
		free(S->base);
		free(S);
		return NULL;
	}

	if (isatty(fd))
		flags |= SF_BUFLINE;
	else
		flags |= SF_BUFBLCK;

	S->fd = fd;
	S->flags = flags;
	insert_entry(S);

	return S;
}
