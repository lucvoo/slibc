#include "libc/stdio.h"
#include <unistd.h>			// for close()
#include <fcntl.h>			// for open()
#include "libc/errno.h"

#include <assert.h>			// FIXME: to be removed

FILE *freopen(const char *path, const char *mode, FILE * S)
{
	int fd;
	unsigned int oflags;
	unsigned int flags;

	__stdio_flshbuf(S);

	if (__stdio_getmode(mode, &oflags, &flags)) {
		errno = EINVAL;
		goto error;
	}

	fd = open(path, oflags, 0666);
	if (__unlikely(fd == -1)) {
		goto error;
	}

	fd = dup2(fd, S->fd);
	if (__unlikely(fd == -1)) {
		goto error;
	}

	if (isatty(fd))
		flags |= SF_BUFLINE;
	else
		flags |= SF_BUFBLCK;

	S->fd = fd;
	S->flags = flags;

// FIXME:
	assert(S->ptr == S->base);
	assert(S->endr == S->base);
	assert(S->endw == S->base + S->size);

	return S;

error:
	fclose(S);
	return NULL;
}
