#include <sys/socket.h>
#include "libc/socketcall.h"

int bind(int fd, const struct sockaddr *addr, socklen_t addrlen)
{
	long args[] = { fd, (long)addr, (long)addrlen };

	return __sys_socketcall(SYS_BIND, args);
}
