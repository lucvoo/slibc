#include "_grp.h"
#include <ctype.h>			// for isdigit()
#include <limits.h>			// for NGROUPS_MAX
#include <values/NULL.h>

// Format: group_name:passwd:GID:user_list

// FIXME: Make the suppostion that db-files are correct
// FIXME: error handling
// FIXME: alignment problem in bptr => list !!!
#include <assert.h>

int __libc_getgrent(struct group *grp, char *buf, size_t size, parse_state_t * ps)
{
	const char *pptr = ps->ptr;
	const char *pend = ps->end;
	char *bptr = buf;
	const char *bend = buf + size - 1;
	const char **list;
	const char **lend;

	COPYstr(grp->gr_name, ':');
	COPYstr(grp->gr_passwd, ':');
	COPYul(grp->gr_gid, ':');

#if 0
//@@ ALIGNMENT @@@    grp->gr_mem = (char**) list = (void*) bptr;
	assert((((unsigned long)bptr) & (sizeof(char *) - 1)) == 0);
	grp->gr_mem = (char **)list = (void *)bptr;
	bptr += (NGROUPS_MAX + 1) * sizeof(char *);
	if (bptr >= bend)
		goto error;
	lend = (void *)bptr;
#else
	SET_ALIGN(grp->gr_mem, bptr);
	list = (const char **)grp->gr_mem;
	lend = list + (NGROUPS_MAX + 1);
	if ((void *)lend >= (void *)bend)
		goto error;
	bptr = (char *)lend;
#endif
	while ((pptr[-1] != '\n') && (list < lend)) {
		COPYstr(*list++, ',');
	}
	*list = NULL;

	ps->ptr = pptr;
	return 0;

error:
	ps->ptr = pptr;
	return 1;
}
