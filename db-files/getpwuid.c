#include "_pwd.h"
#include <values/NULL.h>

struct passwd *getpwuid(uid_t uid)
{
	static char buf[PWDBUF_SIZE];
	static struct passwd pwd;

	if (__libc_getpwuid(&pwd, buf, sizeof(buf), uid))
		return NULL;

	return &pwd;
}
