#include "_pwd.h"
#include <values/NULL.h>

struct passwd *getpwnam(const char *name)
{
	static char buf[PWDBUF_SIZE];
	static struct passwd pwd;

	if (__libc_getpwnam(&pwd, buf, sizeof(buf), name))
		return NULL;

	return &pwd;
}
