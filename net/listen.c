#include <sys/socket.h>
#include "libc/socketcall.h"

int listen(int fd, int backlog)
{
	long args[] = { fd, backlog };

	return __sys_socketcall(SYS_LISTEN, args);
}
