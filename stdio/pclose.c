#include "libc/stdio.h"
#include <stdlib.h>			// for free()
#include <unistd.h>			// for close()
#include <sys/wait.h>			// for waitpid()
#include <errno.h>
#include "libc/cdefs.h"

int pclose(FILE * S)
{

	__stdio_flshbuf(S);

	if (!(S->flags & SF_USERBUF))
		free(S->base);

	if (!(S->flags & SF_STDFILE)) {
		remove_entry(S);
		free(S);
	}

	if (close(S->fd) < 0)
		return -1;

	// wait after child exit status
	while (1) {
		int status;
		int rc;

		rc = waitpid(S->pid, &status, 0);
		if (rc != -1)
			return status;
		if (errno != EINTR)
			return -1;
	}
}
