#include "_grp.h"
#include <values/NULL.h>

struct group *getgrnam(const char *name)
{
	static char buf[GRPBUF_SIZE];
	static struct group grp;

	if (__libc_getgrnam(&grp, buf, sizeof(buf), name))
		return NULL;

	return &grp;
}
