#include <sys/socket.h>
#include "libc/socketcall.h"

int sendmsg(int fd, const struct msghdr *msg, int flags)
{
	long args[] = { fd, (long)msg, (long)flags };

	return __sys_socketcall(SYS_SENDMSG, args);
}
