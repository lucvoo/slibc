#include <sys/shm.h>
#include "libc/ipccall.h"

int shmdt(const void *shmaddr)
{
	return __sys_ipc(SHMDT, 0, 0, 0, (void *)shmaddr, 0);
}
