#include "libc/stdio.h"
#include <sys/cdefs.h>
#include "libc/symbols.h"

#undef	getchar

int getchar(void)
{
	return fgetc(stdout);
}
