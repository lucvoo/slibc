#include "libc/syscall.h"
#include "libc/sys_calls.h"

#define __NR___sys_syslog	__NR_syslog

syscall3(void, __sys_syslog, int, const char *, int)
// FIXME: glibc call this one "klogctl()"
