#include <sys/socket.h>
#include "libc/socketcall.h"

int send(int fd, const void *buf, size_t len, int flags)
{
	long args[] = { fd, (long)buf, len, flags };

	return __sys_socketcall(SYS_SEND, args);
}
