#include <unistd.h>
#include <errno.h>
#include "libc/syscall.h"
#include "libc/sys_calls.h"

#define __NR___sys_getcwd	__NR_getcwd
#undef	__syscall_return
#define __syscall_return(type, res)	return (type) (res)

static inline syscall2(long, __sys_getcwd, char *, size_t)

	 char *getcwd(char *buf, size_t size)
{
	int rc;

	rc = __sys_getcwd(buf, size);
	if (rc < 0) {
		errno = -rc;
		return NULL;
	}

	return buf;
}
