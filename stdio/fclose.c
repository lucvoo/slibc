#include "libc/stdio.h"
#include <unistd.h>			// for close(2)
#include <stdlib.h>			// for free(2)

int fclose(FILE * S)
{
	int rc;

	// FIXME: unify with pclose ?
	rc = __stdio_flshbuf(S);
	rc |= close(S->fd);

	if (!(S->flags & SF_USERBUF))
		free(S->base);

	if (!(S->flags & SF_STDFILE)) {
		remove_entry(S);
		free(S);
	}

	return rc;
}
