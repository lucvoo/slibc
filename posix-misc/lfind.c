#include <search.h>
#include <values/NULL.h>

void *lfind(const void *key, const void *base,
	    size_t * nelp, size_t width, int (*compar) (const void *, const void *))
{
	const void *ptr = base;
	size_t max = *nelp;

	for (; max > 0; max--) {
		if (compar(key, ptr) == 0)
			return (void *)ptr;

		ptr += width;
	}

	return NULL;
}
