#ifndef _LIBC_SRV_H
#define _LIBC_SRV_H

#include <netdb.h>
#include "db-files.h"

#define SERVBUF_SIZE	256		// FIXME: CONFIG_...

int __libc_getservent(struct servent *, char *, size_t, parse_state_t *);
int __libc_getservnam(struct servent *, char *, size_t, const char *name, const char *proto);
int __libc_getservport(struct servent *, char *, size_t, int port, const char *proto);

#endif
