#include "libc/stdio.h"
#include "libc/prototypes.h"		// for __writen(3)
#include "libc/cdefs.h"			// for __likely

int __stdio_flshbuf(FILE * S)
{
	ssize_t count;

	if (!(S->flags & SF_WR))	// FIXME: update stream in reading !
		return 0;

// FIXME: ??? ungotten char ???

	count = S->ptr - S->base;
	if (__likely(count > 0)) {
		ssize_t n;
		n = __writen(S->fd, S->base, count);
		if (n != count) {
			S->flags |= SF_ERROR;
			return EOF;
		}
		S->ptr = S->base;
	}

	return 0;
}
