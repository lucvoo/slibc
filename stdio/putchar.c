#include "libc/stdio.h"
#include <sys/cdefs.h>
#include "libc/symbols.h"

#undef	putchar

int putchar(int c)
{
	return fputc(c, stdout);
}
