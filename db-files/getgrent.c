#include "_grp.h"
#include <paths.h>			// for _PATH_GROUP
#include <values/NULL.h>

// FIXME: split in 3 files?

static parse_state_t state;

void setgrent(void)
{
	if (state.buf)
		state.ptr = state.buf;
	else
		__libc_parse_start(_PATH_GROUP, &state);
}

void endgrent(void)
{
	__libc_parse_finish(&state);
}

struct group *getgrent(void)
{
	static char buf[GRPBUF_SIZE];
	static struct group grp;

	if (!state.buf)
		if (__libc_parse_start(_PATH_GROUP, &state))
			return NULL;

	if (__libc_getgrent(&grp, buf, sizeof(buf), &state))
		return NULL;

	return &grp;
}
