#include "libc/stdio.h"
#include <stdlib.h>			// for malloc

FILE *__stdio_new(void)
{
	FILE *S;
	size_t size;
	char *buf;

	S = malloc(sizeof(FILE));
	if (!S)
		return S;

	size = BUFSIZ;			// FIXME: use stat.st_... ???
	buf = malloc(size);
	if (!buf) {
		free(S);
		return NULL;
	}

	S->base = buf;
	S->ptr = buf;
	S->endr = buf;
	S->endw = buf + size;
	S->size = size;
	S->pushed = 0;

	return S;
}

FILE *__stdio_flist = NULL;

void __stdio_cleanup(void)
{
	FILE *S;

	for_each_file(S) {
		__stdio_flshbuf(S);
	}
}
