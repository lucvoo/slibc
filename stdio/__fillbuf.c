#include "libc/stdio.h"
#include <unistd.h>			// for read(2)
#include "libc/cdefs.h"			// for __likely

// fill the buffer
int __stdio_fillbuf(FILE * S)
{
	ssize_t n;

	n = read(S->fd, S->base, S->size);
	if (__likely(n > 0))		// read succeed
	{
		S->endr = S->base + n;
		S->endw = S->base;	// FIXME: usefull?, flags |= READING ?
		S->ptr = S->base;
		return 0;
	} else if (n == 0)		// reached EOF
	{
		S->flags |= SF_EOF;
		return EOF;
	} else				// (n < 0)                     // read error
	{
		S->flags |= SF_ERROR;
		return EOF;
	}
}
