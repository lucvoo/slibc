#include "_proto.h"
#include <values/NULL.h>

// Format: name<ws>protocol[<ws>aliases]*[#.*]

// FIXME: Make the suppostion that db-files are correct
// FIXME: error handling

// FIXME: limit the number of aliases to ...
#define NBR_ALIASES	16

int __libc_getprotoent(struct protoent *proto, char *buf, size_t size, parse_state_t * ps)
{
	const char *pptr = ps->ptr;
	const char *pend = ps->end;
	char *bptr = buf;
	const char *bend = buf + size - 1;
	const char **list;
	const char **lend;

	// strip comment lines
	while (*pptr == '#' || *pptr == '\n') {
		do
			pptr++;
		while (*pptr != '\n');
		pptr++;
	}

	COPYstr_ws(proto->p_name);
	COPYul_ws(proto->p_proto);

	proto->p_aliases = (char **)(list = (void *)bptr);
	bptr += (NBR_ALIASES + 1) * sizeof(char *);
	if (bptr >= bend)
		goto error;
	lend = (void *)bptr;
	while ((pptr[-1] != '\n') && (pptr[0] != '#') && (list < lend)) {
		COPYstr_ws(*list++);
	}
	*list = NULL;

	ps->ptr = pptr;
	return 0;

error:
	ps->ptr = pptr;
	return 1;
}
