#ifndef _LIBC_ERRNO_H
#define _LIBC_ERRNO_H

#include <errno.h>

extern const char *__sys_errlist[];
extern const unsigned __sys_errsize;
const char *__strerror(int errnum);

#endif
