#include "libc/printf.h"
#include "libc/stdio.h"
#include <stdarg.h>

int vfprintf(FILE * S, const char *fmt, va_list ap)
{
	int n;
	printf_t pf = { S, (write_fn_t) __stdio_fputx, (putch_fn_t) fputc };

	n = __stdio_vxprintf(&pf, fmt, ap);

	return n;
}
