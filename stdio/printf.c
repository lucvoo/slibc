#include "libc/printf.h"
#include "libc/stdio.h"
#include <stdarg.h>

int printf(const char *fmt, ...)
{
	int n;
	va_list ap;
	printf_t pf = { stdout, (write_fn_t) __stdio_fputx, (putch_fn_t) fputc };

	va_start(ap, fmt);
	n = __stdio_vxprintf(&pf, fmt, ap);
	va_end(ap);

	return n;
}
