#include "_serv.h"
#include <values/NULL.h>

struct servent *getservbyname(const char *name, const char *proto)
{
	static char buf[SERVBUF_SIZE];
	static struct servent ent;

	if (__libc_getservnam(&ent, buf, sizeof(buf), name, proto))
		return NULL;

	return &ent;
}
