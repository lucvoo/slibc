#include <unistd.h>
#include <paths.h>			// for _PATH_SHELLS
#include "db-files.h"

// FIXME: split in 3 files?

static parse_state_t state;

void setusershell(void)
{
	if (state.buf)
		state.ptr = state.buf;
	else
		__libc_parse_start(_PATH_SHELLS, &state);
}

void endusershell(void)
{
	__libc_parse_finish(&state);
}

// Format: shell
// FIXME: if "/etc/shells" not available; should behave as if
//        `/bin/sh' & `/bin/csh' are present!

static
int __libc_getusershell(char *buf, size_t size, parse_state_t * ps)
{
	const char *pptr = ps->ptr;
	const char *pend = ps->end;
	char *bptr = buf;
	const char *bend = buf + size - 1;

	COPYstr(buf, ':');

	ps->ptr = pptr;
	return 0;

error:
	ps->ptr = pptr;
	return 1;
}

char *getusershell(void)
{
	static char buf[256];		// FIXME: magic number

	if (!state.buf)
		if (__libc_parse_start(_PATH_SHELLS, &state))
			return NULL;

	if (__libc_getusershell(buf, sizeof(buf), &state))
		return NULL;

	return buf;
}
