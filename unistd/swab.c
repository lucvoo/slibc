#include <unistd.h>

void swab(const void *restrict _src, void *restrict _dst, ssize_t n)
{
	const char *src = _src;
	char *dst = _dst;

	n &= ~1;			// ensure that n is even
	for (; n > 0; n -= 2) {
		unsigned char tmp;

		tmp = *src++;
		*dst++ = *src++;
		*dst++ = tmp;
	}
}
