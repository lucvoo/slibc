#ifndef _LIBC_PWD_H
#define _LIBC_PWD_H

#include <pwd.h>
#include "db-files.h"

#define PWDBUF_SIZE	256		// FIXME: CONFIG_...

int __libc_getpwent(struct passwd *, char *, size_t, parse_state_t *);
int __libc_getpwnam(struct passwd *, char *, size_t, const char *);
int __libc_getpwuid(struct passwd *, char *, size_t, uid_t);

#endif
