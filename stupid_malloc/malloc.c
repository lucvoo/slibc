#include <stdlib.h>
#include <unistd.h>
#include "libc/brk.h"

void *malloc(size_t size)
{
	void *top;
	void *now = __cur_brk;

	size = ((size + 15) / 16) * 16;
	top = sbrk(size);
	if (top == (void *)-1)
		return NULL;

	return now;
}
