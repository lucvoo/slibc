#include "_grp.h"
#include <values/NULL.h>

struct group *getgrgid(gid_t gid)
{
	static char buf[GRPBUF_SIZE];
	static struct group grp;

	if (__libc_getgrgid(&grp, buf, sizeof(buf), gid))
		return NULL;

	return &grp;
}
