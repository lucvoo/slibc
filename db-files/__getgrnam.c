#include "_grp.h"
#include <paths.h>			// for _PATH_GROUP
#include <string.h>			// for strcmp()

// FIXME: can be optimized

int __libc_getgrnam(struct group *grp, char *buf, size_t size, const char *name)
{
	parse_state_t state;
	int notfound = 1;

	if (__libc_parse_start(_PATH_GROUP, &state))
		return notfound;

	while (__libc_getgrent(grp, buf, size, &state) == 0) {
		if (strcmp(grp->gr_name, name) == 0) {
			notfound = 0;
			break;
		}
	}

	__libc_parse_finish(&state);
	return notfound;
}
