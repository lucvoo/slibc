#include "_pwd.h"
#include <paths.h>			// for _PATH_PASSWD

// FIXME: can be optimized

int __libc_getpwuid(struct passwd *pwd, char *buf, size_t size, uid_t uid)
{
	parse_state_t state;
	int notfound = 1;

	if (__libc_parse_start(_PATH_PASSWD, &state))
		return notfound;

	while (__libc_getpwent(pwd, buf, size, &state) == 0) {
		if (pwd->pw_uid == uid) {
			notfound = 0;
			break;
		}
	}

	__libc_parse_finish(&state);
	return notfound;
}
