#include <sys/shm.h>
#include "libc/ipccall.h"
#include <values/NULL.h>

int shmget(key_t key, size_t size, int shmflg)
{
	return __sys_ipc(SHMGET, key, size, shmflg, NULL, 0);
}
