#include "libc/stdio.h"
#include <unistd.h>			// for isatty()

static char buffer[BUFSIZ];
static FILE __stdout = {.fd = 1,
	.flags = 0,
	.ptr = buffer,
	.base = buffer,
	.endr = buffer,
	.endw = buffer + sizeof(buffer),
	.size = sizeof(buffer),
	.pushbuf = 0,
	.pushed = 0,
	.next = NULL,
	.pid = 0,
};

FILE *stdout = &__stdout;

static void init_stdout(void) __attribute((constructor));
	 static void init_stdout(void)
{
	if (isatty(1))
		__stdout.flags = SF_WR | SF_BUFLINE | SF_USERBUF | SF_STDFILE;
	else
		__stdout.flags = SF_WR | SF_BUFBLCK | SF_USERBUF | SF_STDFILE;
}

int __stdio_flush_stdout(void)
{
	return __stdio_flshbuf(stdout);
}
