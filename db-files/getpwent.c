#include "_pwd.h"
#include <paths.h>			// for _PATH_PASSWD
#include <values/NULL.h>

// FIXME: split in 3 files?

static parse_state_t state;

void setpwent(void)
{
	if (state.buf)
		state.ptr = state.buf;
	else
		__libc_parse_start(_PATH_PASSWD, &state);
}

void endpwent(void)
{
	__libc_parse_finish(&state);
}

struct passwd *getpwent(void)
{
	static char buf[PWDBUF_SIZE];
	static struct passwd pwd;

	if (!state.buf)
		if (__libc_parse_start(_PATH_PASSWD, &state))
			return NULL;

	if (__libc_getpwent(&pwd, buf, sizeof(buf), &state))
		return NULL;

	return &pwd;
}
