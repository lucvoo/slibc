#include <sys/sem.h>
#include "libc/ipccall.h"

int semop(int semid, struct sembuf *sops, size_t nsops)
{
	return __sys_ipc(SEMOP, semid, nsops, 0, sops, 0);
}
