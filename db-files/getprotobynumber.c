#include "_proto.h"
#include <values/NULL.h>

struct protoent *getprotobynumber(int proto)
{
	static char buf[PROTOBUF_SIZE];
	static struct protoent ent;

	if (__libc_getprotonbr(&ent, buf, sizeof(buf), proto))
		return NULL;

	return &ent;
}
