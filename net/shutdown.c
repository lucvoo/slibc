#include <sys/socket.h>
#include "libc/socketcall.h"

int shutdown(int fd, int how)
{
	long args[] = { fd, how };

	return __sys_socketcall(SYS_SHUTDOWN, args);
}
