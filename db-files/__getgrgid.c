#include "_grp.h"
#include <paths.h>			// for _PATH_GROUP

// FIXME: can be optimized

int __libc_getgrgid(struct group *grp, char *buf, size_t size, gid_t gid)
{
	parse_state_t state;
	int notfound = 1;

	if (__libc_parse_start(_PATH_GROUP, &state))
		return notfound;

	while (__libc_getgrent(grp, buf, size, &state) == 0) {
		if (grp->gr_gid == gid) {
			notfound = 0;
			break;
		}
	}

	__libc_parse_finish(&state);
	return notfound;
}
