#include <stdio.h>
#include "libc/printf.h"
#include <string.h>

typedef struct {
	char *base;
	char *ptr;
	char *end;
} strbuf_t;

static
int strwrite(void *obj, const char *buf, size_t size)
{
	strbuf_t *str = obj;
	size_t len;

	len = str->end - str->ptr;
	if (len == 0)			// buffer is full !
		return size;

	if (size < len)
		len = size;

	memcpy(str->ptr, buf, len);
	str->ptr += len;

	return size;
}

static
int strputc(int c, void *obj)
{
	strbuf_t *str = obj;

	if (str->ptr < str->end) {
		str->ptr[0] = c;
		str->ptr += 1;
	}

	return 1;
}

int vsnprintf(char *restrict s, size_t max, const char *fmt, va_list ap)
{
	strbuf_t sbuf = { s, s, s + (max - 1) };
	printf_t pf = { &sbuf, strwrite, strputc };
	int rc;

	rc = __stdio_vxprintf(&pf, fmt, ap);
	sbuf.ptr[0] = '\0';		// null terminate the buffer

	return rc;
}
