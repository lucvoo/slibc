#include <string.h>

extern
const char *__progname_full;

const char *__progname = "";

static void init_progname(void) __attribute((constructor));
	 static void init_progname(void)
{
	const char *ptr;

	ptr = strrchr(__progname_full, '/');
	if (ptr)
		ptr++;
	else
		ptr = __progname_full;

	__progname = ptr;
}
