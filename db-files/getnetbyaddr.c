#include "_net.h"
#include <values/NULL.h>

struct netent *getnetbyaddr(uint32_t addr, int type)
{
	static char buf[NETBUF_SIZE];
	static struct netent ent;

	if (__libc_getnetaddr(&ent, buf, sizeof(buf), addr, type))
		return NULL;

	return &ent;
}
