#include <sys/sem.h>
#include "libc/ipccall.h"
#include <values/NULL.h>

int semget(key_t key, int nsems, int semflg)
{
	return __sys_ipc(SEMGET, key, nsems, semflg, NULL, 0);
}
