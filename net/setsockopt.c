#include <sys/socket.h>
#include "libc/socketcall.h"

int setsockopt(int fd, int level, int optname, const void *optval, socklen_t addrlen)
{
	long args[] = { fd, level, optname, (long)optval, addrlen };

	return __sys_socketcall(SYS_SETSOCKOPT, args);
}
