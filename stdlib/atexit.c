#include <stdlib.h>
#include <limits.h>
#include "libc/atexit.h"
#include "libc/cdefs.h"

typedef void (*exit_fn_t) (void);

static exit_fn_t fn_tab[ATEXIT_MAX];
static size_t fn_cnt;

int atexit(exit_fn_t fun)
{
	if (__unlikely(fn_cnt >= ATEXIT_MAX))
		return -1;

	fn_tab[fn_cnt++] = fun;

	return 0;
}

int __libc_atexit_cleanup(void)
{
	size_t n;

	for (n = fn_cnt; n--;) {
		exit_fn_t f;

		f = fn_tab[n];
		f();
	}

	return 0;
}
