#include <search.h>
#include <string.h>

void *lsearch(const void *key, void *base,
	      size_t * nelp, size_t width, int (*compar) (const void *, const void *))
{
	void *ptr;
	size_t nelem;

	ptr = lfind(key, base, nelp, width, compar);
	if (ptr)
		return ptr;

	// not found: insert at end
	nelem = *nelp;
	*nelp = nelem + 1;
	ptr = base + nelem * width;
	memcpy(ptr, key, width);

	return ptr;
}
