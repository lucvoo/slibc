#include "_proto.h"
#include <values/NULL.h>

// FIXME: split in 3 files?

static parse_state_t state;

void setprotoent(int stayopen)
{
	(void)stayopen;			// FIXME: correct ???

	if (state.buf)
		state.ptr = state.buf;
	else
		__libc_parse_start(_PATH_PROTOCOLS, &state);
}

void endprotoent(void)
{
	__libc_parse_finish(&state);
}

struct protoent *getprotoent(void)
{
	static char buf[PROTOBUF_SIZE];
	static struct protoent srv;

	if (!state.buf)
		if (__libc_parse_start(_PATH_PROTOCOLS, &state))
			return NULL;

	if (__libc_getprotoent(&srv, buf, sizeof(buf), &state))
		return NULL;

	return &srv;
}
