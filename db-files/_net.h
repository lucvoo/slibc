#ifndef _LIBC_NET_H
#define _LIBC_NET_H

#include <netdb.h>
#include "db-files.h"

#define NETBUF_SIZE	256		// FIXME: CONFIG_...

int __libc_getnetent(struct netent *, char *, size_t, parse_state_t *);
int __libc_getnetnam(struct netent *, char *, size_t, const char *name);
int __libc_getnetaddr(struct netent *, char *, size_t, uint32_t addr, int type);

#endif
