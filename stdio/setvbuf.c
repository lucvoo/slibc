#include "libc/stdio.h"
#include <stdlib.h>			// for malloc() & free()

// FIXME: use an internal function and reuse it with f*open !

int setvbuf(FILE * restrict S, char *restrict buf, int type, size_t size)
{
	unsigned int buffering;

	// check if type is valid
	switch (type) {
	case _IOFBF:
		buffering = SF_BUFBLCK;
		break;
	case _IOLBF:
		buffering = SF_BUFLINE;
		break;
	case _IONBF:
		buffering = SF_BUFNONE;
		break;
	default:
		// FIXME: set errno to EINVAL ???
		return -1;
	}

	// allocate a new buffer if necessary
	if (!buf) {
		if (!size)
			return -1;	// FIXME: errno = EINVAL ??
		if (!(buf = malloc(size)))
			return -1;
	}

	if (!(S->flags & SF_USERBUF))
		free(S->base);

	S->size = size;
	S->base = buf;
	S->ptr = buf;
	S->endr = buf;
	S->endw = buf + size;

	S->flags &= ~(SF_BUFMSK);
	S->flags |= buffering;

	return 0;
}
