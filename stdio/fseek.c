#include "libc/stdio.h"
#include <unistd.h>			// for lseek
#include "libc/cdefs.h"			// for __likely

int fseek(FILE * S, long offset, int whence)
{
	off_t rc;

#if 0					// FIXME
	__stdio_flsh(S);
	S->bm = 0;
	stream->bs = 0;
#endif

	S->flags &= ~SF_EOF;
	S->pushed = 0;

	rc = lseek(S->fd, offset, whence);
	if (__unlikely(rc == (off_t) - 1))
		return -1;
	else
		return 0;
}
