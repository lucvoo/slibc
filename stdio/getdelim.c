#include "libc/stdio.h"
#include <string.h>			// for memccpy()
#include <errno.h>
#include <stdlib.h>			// for realloc()
#include "libc/cdefs.h"			// for __likely

ssize_t getdelim(char **restrict linep, size_t * restrict sizep, int delim, FILE * restrict S)
{
	size_t i = 0;			// nbr of char already readed into the current line
	size_t size;
	char *line;

	if (!linep || !sizep) {
		errno = EINVAL;
		return -1;
	}

	line = *linep;
	if (!line)
		size = 0;
	else
		size = *sizep;

	while (1) {
		char *found;
		int n;

		n = (S->endr - S->ptr);
		if (__unlikely(n == 0))	// refill the buffer
		{
			if (__stdio_fillbuf(S) == EOF)
				return -1;

			n = S->endr - S->ptr;
		}

		found = memchr(S->ptr, delim, n);
		if (found)
			n = found - S->ptr + 1;

		if (i + n + 1 > size) {
			size = (i + n + 1) | 0xf0;	// round up to 256-16 bytes
			line = realloc(line, size);
			if (!line)
				return -1;
			*linep = line;
			*sizep = size;
		}

		memcpy(&line[i], S->ptr, n);
		S->ptr += n;
		i += n;

		if (found)
			break;
	}

	line[i] = '\0';

	return i;
}
