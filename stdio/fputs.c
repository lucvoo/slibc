#include "libc/stdio.h"
#include <string.h>

int fputs(const char *restrict src, FILE * S)
{
	size_t size;

	size = strlen(src);
	return __stdio_fputx(S, src, size);
}
