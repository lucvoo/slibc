#include "libc/stdio.h"
#include <sys/cdefs.h>
#include "libc/symbols.h"

int fputc(int c, FILE * S)
{
	*S->ptr++ = (unsigned char)c;

	if ((S->ptr == S->endw) || ((c == '\n') && (S->flags & SF_BUFLINE)))
		return __stdio_flshbuf(S);
	else
		return c;
}

strong_alias(fputc, putc);
