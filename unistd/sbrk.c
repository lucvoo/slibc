#include <unistd.h>
#include <errno.h>
#include "libc/brk.h"

void *sbrk(ptrdiff_t inc)
{
	char *new_brk;
	char *old_brk;

	old_brk = __cur_brk;
	new_brk = __cur_brk + inc;
	__cur_brk = __sys_brk(new_brk);
	if (__cur_brk != new_brk) {
		errno = ENOMEM;
		return (void *)-1;
	} else
		return old_brk;
}

// FIXME: sbrk(0) should not do a syscall ?
