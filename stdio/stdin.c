#include "libc/stdio.h"

static char buffer[BUFSIZ];
static FILE __stdin = {.fd = 0,
	.flags = SF_RD | SF_BUFLINE | SF_USERBUF | SF_STDFILE,
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

FILE *stdin = &__stdin;

int __stdio_flush_stdin(void)
{
	return __stdio_flshbuf(stdin);
}
