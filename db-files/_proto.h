#ifndef _LIBC_PROTO_H
#define _LIBC_PROTO_H

#include <netdb.h>
#include "db-files.h"

#define PROTOBUF_SIZE	256		// FIXME: CONFIG_...

int __libc_getprotoent(struct protoent *, char *, size_t, parse_state_t *);
int __libc_getprotonam(struct protoent *, char *, size_t, const char *);
int __libc_getprotonbr(struct protoent *, char *, size_t, int proto);

#endif
