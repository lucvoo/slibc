#include "_net.h"
#include <values/NULL.h>

struct netent *getnetbyname(const char *name)
{
	static char buf[NETBUF_SIZE];
	static struct netent ent;

	if (__libc_getnetnam(&ent, buf, sizeof(buf), name))
		return NULL;

	return &ent;
}
