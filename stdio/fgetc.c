#include "libc/stdio.h"
#include "libc/cdefs.h"			// for __likely
#include "libc/symbols.h"
#include <unistd.h>			// for read(2)

int fgetc(FILE * S)
{
	int rc;

	// first try the ungetc buffer
	if (__unlikely(S->pushed)) {
		S->pushed = 0;
		return S->pushbuf;
	}
	// if buffer is not empty: use it
	if (__likely(S->ptr < S->endr))
		return *S->ptr++;

	// otherwise we must first fill the buffer
	if ((rc = __stdio_fillbuf(S)))
		return rc;

	return *S->ptr++;
}

strong_alias(fgetc, getc);
