#include <sys/socket.h>
#include "libc/socketcall.h"

int socket(int domain, int type, int protocol)
{
	long args[] = { domain, type, protocol };

	return __sys_socketcall(SYS_SOCKET, args);
}
