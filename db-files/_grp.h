#ifndef _LIBC_GRP_H
#define _LIBC_GRP_H

#include <grp.h>
#include "db-files.h"

#define GRPBUF_SIZE	256		// FIXME: CONFIG_...

int __libc_getgrent(struct group *, char *, size_t, parse_state_t *);
int __libc_getgrnam(struct group *, char *, size_t, const char *);
int __libc_getgrgid(struct group *, char *, size_t, gid_t);

#endif
