#include <stdlib.h>
#include <string.h>			// for memset()

void *calloc(size_t nmemb, size_t size)
{
	size_t N = nmemb * size;
	void *ptr;

	ptr = malloc(N);
	if (!ptr)
		return ptr;

	memset(ptr, 0, N);

	return ptr;
}
