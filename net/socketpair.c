#include <sys/socket.h>
#include "libc/socketcall.h"

int socketpair(int domain, int type, int protocol, int sv[2])
{
	long args[] = { domain, type, protocol, (long)sv };

	return __sys_socketcall(SYS_SOCKETPAIR, args);
}
