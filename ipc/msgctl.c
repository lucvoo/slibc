#include <sys/msg.h>
#include "libc/ipccall.h"

int msgctl(int msqid, int cmd, struct msqid_ds *buf)
{
	return __sys_ipc(MSGCTL, msqid, cmd, 0, buf, 0);
}
