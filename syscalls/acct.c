#include <sys/acct.h>
#include "libc/syscall.h"

syscall1(int, acct, const char *)
