#include <sys/socket.h>
#include "libc/socketcall.h"

int getsockname(int fd, struct sockaddr *restrict addr, socklen_t * restrict addrlen)
{
	long args[] = { fd, (long)addr, (long)addrlen };

	return __sys_socketcall(SYS_GETSOCKNAME, args);
}
