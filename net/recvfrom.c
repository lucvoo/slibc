#include <sys/socket.h>
#include "libc/socketcall.h"

int recvfrom(int fd, void *buf, size_t len, int flags,
	     struct sockaddr *restrict addr, socklen_t * restrict addrlen)
{
	long args[] = { fd, (long)buf, len, flags, (long)addr, (long)addrlen };

	return __sys_socketcall(SYS_RECVFROM, args);
}
