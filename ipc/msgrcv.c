#include <sys/msg.h>
#include "libc/ipccall.h"

ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg)
{
	return __sys_ipc(MSGRCV, msqid, msgsz, msgflg, msgp, msgtyp);
}
