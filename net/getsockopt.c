#include <sys/socket.h>
#include "libc/socketcall.h"

int getsockopt(int fd, int level, int optname, void *restrict optval, socklen_t * restrict addrlen)
{
	long args[] = { fd, level, optname, (long)optval, (long)addrlen };

	return __sys_socketcall(SYS_GETSOCKOPT, args);
}
