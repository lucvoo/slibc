#include "libc/stdio.h"

size_t fwrite(const void *restrict ptr, size_t size, size_t n, FILE * restrict S)
{
	int w;

	if (__unlikely(!size || !n))
		return 0;

	w = __stdio_fputx(S, ptr, size * n);
	if (w == -1)
		return 0;

	return w / size;
}
