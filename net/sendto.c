#include <sys/socket.h>
#include "libc/socketcall.h"

int sendto(int fd, const void *buf, size_t len, int flags, const struct sockaddr *addr,
	   socklen_t addrlen)
{
	long args[] = { fd, (long)buf, len, flags, (long)addr, addrlen };

	return __sys_socketcall(SYS_SENDTO, args);
}
