#ifndef _LIBC_NET_H
#define _LIBC_NET_H

#include <netdb.h>
#include "db-files.h"

#define HOSTBUF_SIZE	1024		// FIXME: CONFIG_...

int __libc_gethostent(struct hostent *, char *, size_t, parse_state_t *);

#endif
