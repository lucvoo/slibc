#include <unistd.h>			// for execve & environ
#include <paths.h>			// for _PATH_BSHELL
#include "libc/unistd.h"		// for __libc_execsh()

int __libc_execsh(const char *file, size_t n, char *const argv[])
{
	const char **nargv;
	int rc;

	nargv = __builtin_alloca((n + 1) * sizeof(char *));

	nargv[0] = _PATH_BSHELL;
	nargv[1] = file;
	__builtin_memcpy(&nargv[2], &argv[1], (n - 1) * sizeof(char *));

	// Should never return
	rc = execve("/bin/sh", (char **)nargv, environ);
	return rc;
}
