#include <stdlib.h>
#include "libc/cdefs.h"

void *bsearch(const void *key, const void *base_, size_t nbre, size_t size, __compar_fn_t compar)
{
	const char *base = base_;

	while (nbre > 0) {
		const char *e;
		size_t i;
		int res;

		// split in [0 .. | nbre/2 | .. nbre-1]
		i = nbre / 2;
		e = base + (i * size);
		res = compar(key, e);
		if (__unlikely(res == 0))
			return (void *)e;
		else if (res < 0) {
			nbre = i;
		} else {
			base = e + size;
			nbre -= i + 1;
		}
	}
	// not found

	return NULL;
}
