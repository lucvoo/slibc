#include <stdlib.h>
#include <string.h>
#include "libc/setenv.h"
#include <unistd.h>			// for __environ

static
int environ_reallocated;

// 'string' is the whole "name=value" string
// 'len' is the lenght of the "name=" part
int __libc_setenv(char *string, size_t len, int overwrite)
{
	size_t n;
	char **envp;
	char **new;

	// look if the name already exists
	for (envp = __environ; *envp; envp++) {
		if (memcmp(string, *envp, len) == 0) {	// found the name
			if (overwrite == 0)
				free(string);	// the whole string from setenv
			else
				*envp = string;	// replace it
			return 0;
		}
	}

	// the name doesn't already exists
	// add it to the environment
	n = envp - __environ;
	if (environ_reallocated == 0)	// first enlargment
	{
		new = malloc((n + 2) * sizeof(char *));
		if (!new)
			return -1;
		memcpy(new, __environ, n * sizeof(char *));
	} else {
		new = realloc(__environ, (n + 2) * sizeof(char *));
		if (!new)
			return -1;
	}

	new[n] = string;
	new[n + 1] = NULL;
	__environ = new;

	return 0;
}
