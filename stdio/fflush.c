#include "libc/stdio.h"
#include "libc/cdefs.h"

int fflush(FILE * S)
{
	int rc;

	if (__unlikely(!S)) {
		rc = __stdio_flush_stdin();
		rc |= __stdio_flush_stdout();
		rc |= __stdio_flush_stderr();
		for_each_file(S)
			rc |= __stdio_flshbuf(S);

		return rc;
	}

	return __stdio_flshbuf(S);
}
