#include <sys/sem.h>
#include "libc/ipccall.h"
#include <stdarg.h>

int semctl(int semid, int semnum, int cmd, ...)
{
	va_list ap;
	union __semun arg;

	va_start(ap, cmd);
	arg = va_arg(ap, union __semun);
	va_end(ap);

	return __sys_ipc(SEMCTL, semid, semnum, cmd, &arg, 0);
}
