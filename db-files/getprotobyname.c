#include "_proto.h"
#include <values/NULL.h>

struct protoent *getprotobyname(const char *name)
{
	static char buf[PROTOBUF_SIZE];
	static struct protoent ent;

	if (__libc_getprotonam(&ent, buf, sizeof(buf), name))
		return NULL;

	return &ent;
}
