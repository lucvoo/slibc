#include "libc/brk.h"
#include <values/NULL.h>

void *__cur_brk;

static void init_cur_brk(void) __attribute((constructor));
	 static void init_cur_brk(void)
{
	__cur_brk = __sys_brk(NULL);
}
