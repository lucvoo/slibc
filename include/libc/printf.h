#ifndef _LIBC_PRINTF_H
#define _LIBC_PRINTF_H

#include <sys/types.h>			// for size_t
#include <sys/cdefs.h>			// for restrict
#include <stdarg.h>			// for va_list

typedef int (*write_fn_t) (void *, const char *, size_t);
typedef int (*putch_fn_t) (int c, void *);

typedef struct {
	void *dest;
	write_fn_t write;
	putch_fn_t putch;
} printf_t;

int __stdio_vxprintf(printf_t * restrict obj, const char *restrict fmt, va_list ap);

#endif
