#include "_pwd.h"
#include <string.h>			// for strcmp()
#include <paths.h>			// for _PATH_PASSWD

// FIXME: can be optimized

int __libc_getpwnam(struct passwd *pwd, char *buf, size_t size, const char *name)
{
	parse_state_t state;
	int notfound = 1;

	if (__libc_parse_start(_PATH_PASSWD, &state))
		return notfound;

	while (__libc_getpwent(pwd, buf, size, &state) == 0) {
		if (strcmp(pwd->pw_name, name) == 0) {
			notfound = 0;
			break;
		}
	}

	__libc_parse_finish(&state);
	return notfound;
}
