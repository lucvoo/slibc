#include "libc/stdio.h"
#include <unistd.h>			// for read(2)

size_t fread(void *restrict ptr, size_t esiz, size_t enbr, FILE * restrict S)
{
	size_t n = esiz * enbr;		// number of char still to be read
	size_t nbuf;			// number of char in the buffer
	unsigned char *dest;

	if (__unlikely(n == 0))
		return 0;

	dest = ptr;

	if (__unlikely(S->pushed)) {
		S->pushed = 0;
		*dest++ = S->pushbuf;
		n--;
	}

read_from_buffer:
	// first read the buffer if any
	nbuf = S->endr - S->ptr;
	if (nbuf > n)
		nbuf = n;

	if (nbuf > 0) {
		__builtin_memcpy(dest, S->ptr, nbuf);
		S->ptr += nbuf;
		n -= nbuf;
	}

	if (n == 0)
		return enbr;

	// if necessary read the remaining
	if (n > S->size) {		// read directely from fd without filling the buffer
		ssize_t nr;

		nr = read(S->fd, ptr, n);
		if (nr == -1) {
			S->flags |= SF_ERROR;
			goto end;
		}
		if (nr == 0) {
			S->flags |= SF_EOF;
			goto end;
		}

		return enbr;
	} else {			// refill the buffer
		if (__stdio_fillbuf(S))
			goto end;

		goto read_from_buffer;
	}

end:
	return (esiz * enbr - n) / esiz;
}
