#include "_net.h"
#include <values/NULL.h>

// FIXME: split in 3 files?

static parse_state_t state;

void setnetent(int stayopen)
{
	(void)stayopen;			// FIXME: correct ???

	if (state.buf)
		state.ptr = state.buf;
	else
		__libc_parse_start(_PATH_NETWORKS, &state);
}

void endnetent(void)
{
	__libc_parse_finish(&state);
}

struct netent *getnetent(void)
{
	static char buf[NETBUF_SIZE];
	static struct netent ent;

	if (!state.buf)
		if (__libc_parse_start(_PATH_NETWORKS, &state))
			return NULL;

	if (__libc_getnetent(&ent, buf, sizeof(buf), &state))
		return NULL;

	return &ent;
}
