#include <sys/shm.h>
#include "libc/ipccall.h"

int shmctl(int shmid, int cmd, struct shmid_ds *buf)
{
	return __sys_ipc(SHMCTL, shmid, cmd, 0, buf, 0);
}
