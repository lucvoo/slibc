#include "_net.h"
#include "libc/cdefs.h"
#include <values/NULL.h>

// Format: name<ws>addr[<ws>aliases]*[#.*]

// FIXME: Make the suppostion that db-files are correct
// FIXME: error handling

// FIXME: limit the number of aliases to ...
#define NBR_ALIASES	16

int __libc_getnetent(struct netent *ent, char *buf, size_t size, parse_state_t * ps)
{
	const char *pptr = ps->ptr;
	const char *pend = ps->end;
	char *bptr = buf;
	const char *bend = buf + size - 1;
	const char **list;
	const char **lend;
	char *addr_buf;
	struct in_addr addr;

	// strip comment lines
	while (*pptr == '#') {
		do
			pptr++;
		while (*pptr != '\n');
		pptr++;
	}

	COPYstr_ws(ent->n_name);
	COPYstr_ws(addr_buf);
	if (__unlikely(inet_aton(addr_buf, &addr) == 0))
		goto error;
	else {
		ent->n_net = addr.s_addr;
		ent->n_addrtype = AF_INET;
	}

	ent->n_aliases = (char **)(list = (void *)bptr);
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
