#include "libc/stdio.h"
#include <string.h>			// for memccpy(3)
#include "libc/cdefs.h"			// for __likely

char *fgets(char *restrict s, int n, FILE * restrict S)
{
	char *start = s;

	n--;				// leave 1 place for the trailing null
	while (n > 0) {
		int size;
		char *found;

		size = (S->endr - S->ptr);
		if (__unlikely(size == 0))	// refill the buffer
		{
			if (__stdio_fillbuf(S) == EOF)
				return NULL;

			size = S->endr - S->ptr;
		}
		if (size > n)
			size = n;

		found = memccpy(s, S->ptr, '\n', size);
		if (found) {
			S->ptr += found - s;
			s = found;
			break;
		} else {
			S->ptr += size;
			s += size;
			n -= size;
		}
	}
	// we have filled all the buffer and not found a newline

	*s = '\0';
	return start;
}
