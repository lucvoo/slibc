#include "_serv.h"
#include <values/NULL.h>

// FIXME: split in 3 files?

static parse_state_t state;

void setservent(int stayopen)
{
	(void)stayopen;			// FIXME: correct ???

	if (state.buf)
		state.ptr = state.buf;
	else
		__libc_parse_start(_PATH_SERVICES, &state);
}

void endservent(void)
{
	__libc_parse_finish(&state);
}

struct servent *getservent(void)
{
	static char buf[SERVBUF_SIZE];
	static struct servent srv;

	if (!state.buf)
		if (__libc_parse_start(_PATH_SERVICES, &state))
			return NULL;

	if (__libc_getservent(&srv, buf, sizeof(buf), &state))
		return NULL;

	return &srv;
}
