#include <sys/resource.h>
#include "libc/syscall.h"
#include <errno.h>

#define get_real_value(res)	(20 - res)

#define __NR__getpriority	__NR_getpriority
#undef	__syscall_return
#define __syscall_return(type, res)	\
	return (type) (res)

static inline syscall2(int, _getpriority, int, int)

	 int getpriority(int which, id_t who)
{
	int res;

	res = _getpriority(which, who);
	if (__likely(res >= 0))
		return 20 - res;
	else
		return __syscall_error(res);
}
