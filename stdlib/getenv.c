#include <stdlib.h>
#include <string.h>			// for strlen()
#include <unistd.h>			// for environ

char *getenv(const char *name)
{
	size_t len;
	char **envp;
	char *env;

	if (!environ || !name)
		return NULL;

	len = strlen(name);
	for (envp = environ; (env = *envp); envp++) {
		int res;

		res = memcmp(name, env, len);
		if ((res == 0) && (env[len] == '='))
			return env + len + 1;
	}

	return NULL;
}
