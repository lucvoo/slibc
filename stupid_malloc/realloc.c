#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "libc/brk.h"

void *realloc(void *old, size_t size)
{
	void *top;
	void *now = __cur_brk;

	size = ((size + 15) / 16) * 16;
	top = sbrk(size);
	if (top == (void *)-1)
		return NULL;

	if (old)
		memmove(now, old, size);

	return now;
}
