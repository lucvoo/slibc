#include "_host.h"
#include <paths.h>			// for _PATH_GROUP
#include <values/NULL.h>

// FIXME: split in 3 files?

static parse_state_t state;

void sethostent(int stayopen)
{
	(void)stayopen;			// FIXME: correct ???

	if (state.buf)
		state.ptr = state.buf;
	else
		__libc_parse_start(_PATH_HOSTS, &state);
}

void endhostent(void)
{
	__libc_parse_finish(&state);
}

struct hostent *gethostent(void)
{
	static char buf[HOSTBUF_SIZE];
	static struct hostent hst;

	if (!state.buf)
		if (__libc_parse_start(_PATH_HOSTS, &state))
			return NULL;

	if (__libc_gethostent(&hst, buf, sizeof(buf), &state))
		return NULL;

	return &hst;
}
