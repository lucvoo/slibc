#include "_host.h"
#include "libc/cdefs.h"
#include <netinet/in.h>			// h_addr_list[] are struct in_addr
#include <values/NULL.h>

// Format: addr<ws>name[<ws>aliases]*[#.*]

// FIXME: Make the suppostion that db-files are correct
// FIXME: error handling

// FIXME: limit the number of aliases to ...
#define NBR_ALIASES     16

int __libc_gethostent(struct hostent *ent, char *buf, size_t size, parse_state_t * ps)
{
	const char *pptr = ps->ptr;
	const char *pend = ps->end;
	char *bptr = buf;
	char *tmp;
	const char *bend = buf + size - 1;
	const char **list;
	const char **lend;
	char *addr_buf;
	struct in_addr addr;
	struct in_addr *addr_p;

	// strip comment lines
	while (*pptr == '#') {
		do
			pptr++;
		while (*pptr != '\n');
		pptr++;
	}

	tmp = bptr;
	COPYstr_ws(addr_buf);
	if (__unlikely(inet_aton(addr_buf, &addr) == 0))
		goto error;
	bptr = tmp;
	SET_ALIGN(addr_p, bptr);
	lend = (void *)(addr_p + 1);
	if ((void *)lend >= (void *)bend)
		goto error;
	bptr = (void *)lend;
	*addr_p = addr;			// value for h_addr_list[0]
	ent->h_addrtype = AF_INET;

	// h_addr_list (only first entry is used)
	SET_ALIGN(ent->h_addr_list, bptr);
	list = (void *)ent->h_addr_list;
	lend = list + 2;
	if ((void *)lend >= (void *)bend)
		goto error;
	bptr = (char *)lend;
	ent->h_addr_list[0] = (char *)addr_p;
	ent->h_addr_list[1] = NULL;

	COPYstr_ws(ent->h_name);

	// h_aliases
	SET_ALIGN(ent->h_aliases, bptr);
	list = (void *)ent->h_aliases;
	lend = list + (NBR_ALIASES + 1);
	if ((void *)lend >= (void *)bend)
		goto error;
	bptr = (char *)lend;

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
