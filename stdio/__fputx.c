#include "libc/stdio.h"
#include <string.h>

int __stdio_fputx(FILE * S, const char *src, size_t size)
{

	// FIXME: optimize unbuffered streams
	if (S->flags & SF_BUFLINE) {
		while (size > 0) {
			size_t max;	// max number of char to be written
			size_t written;	// number of char effectively written
			char *found;
			int flush;

			max = (S->endw - S->ptr);
			if (size < max)
				max = size;

			found = memccpy(S->ptr, src, '\n', max);
			if (found) {
				written = found - ((char *)S->ptr);
				flush = 1;
			} else {
				written = max;
				flush = 0;
			}

			S->ptr += written;
			src += written;
			size -= written;

			if (flush || (S->ptr == S->endw))
				if (__stdio_flshbuf(S))
					return EOF;	// FIXME: to check
		}
	} else				// fully buffered
	{
		while (size > 0) {
			size_t max;	// max number of char to be written

			max = (S->endw - S->ptr);
			if (size < max)
				max = size;

			memcpy(S->ptr, src, max);
			S->ptr += max;
			src += max;
			size -= max;

			if (S->ptr == S->endw)
				if (__stdio_flshbuf(S))
					return EOF;	// FIXME: to check
		}
	}

	return 0;
}
