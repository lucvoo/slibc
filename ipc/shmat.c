#include <sys/shm.h>
#include "libc/ipccall.h"

void *shmat(int shmid, const void *shmaddr, int shmflg)
{
	void *raddr;
	void *res;

	res = (void *)__sys_ipc(SHMAT, shmid, shmflg, (int)&raddr, (void *)shmaddr, 0);
	if ((unsigned long)res <= -(8196UL))
		res = raddr;		// FIXME:   ^^^^ : check values SHMLBA/SHM_RND

	return res;
}
