#include <sys/socket.h>
#include "libc/socketcall.h"

int recvmsg(int fd, struct msghdr *msg, int flags)
{
	long args[] = { fd, (long)msg, flags };

	return __sys_socketcall(SYS_RECVMSG, args);
}
