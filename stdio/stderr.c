#include "libc/stdio.h"

static char buffer[1];
static FILE __stderr = {.fd = 2,
	.flags = SF_WR | SF_BUFNONE | SF_USERBUF | SF_STDFILE,
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

FILE *stderr = &__stderr;

int __stdio_flush_stderr(void)
{
	return __stdio_flshbuf(stderr);
}
