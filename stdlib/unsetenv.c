#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>			// for __environ

int unsetenv(const char *name)
{
	size_t len;
	char **envp;
	char **last;
	const char *env;

	if (!name)
		goto error;

	len = strlen(name);
	if (len == 0)
		goto error;

	if (memchr(name, '=', len))
		goto error;

	for (envp = __environ; (env = *envp); envp++) {
		int res;

		res = memcmp(env, name, len);
		if ((res == 0) && (env[len] == '='))
			goto found;
	}
	// name not found
	return 0;

found:
	// replace this env with the last one
	for (last = envp; last[1]; last++)	// search the last
		;
	*envp = *last;
	*last = NULL;

	return 0;

error:
	errno = EINVAL;
	return -1;
}
