#include <sys/msg.h>
#include "libc/ipccall.h"
#include <values/NULL.h>

int msgget(key_t key, int flag)
{
	return __sys_ipc(MSGGET, key, flag, 0, NULL, 0);
}
