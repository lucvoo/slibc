#include "_serv.h"
#include <values/NULL.h>

struct servent *getservbyport(int port, const char *proto)
{
	static char buf[SERVBUF_SIZE];
	static struct servent ent;

	if (__libc_getservport(&ent, buf, sizeof(buf), port, proto))
		return NULL;

	return &ent;
}
