#include <sys/msg.h>
#include "libc/ipccall.h"

int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg)
{
	return __sys_ipc(MSGSND, msqid, msgsz, msgflg, (void *)msgp, 0);
}
