#include <unistd.h>
#include <errno.h>
#include "libc/symbols.h"
#include "libc/cdefs.h"
#include "libc/brk.h"

int brk(void *new_brk)
{
	__cur_brk = __sys_brk(new_brk);
	if (__unlikely(__cur_brk != new_brk)) {
		errno = ENOMEM;
		return -1;
	} else
		return 0;
}
