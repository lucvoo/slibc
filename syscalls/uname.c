#include <sys/utsname.h>
#include "libc/syscall.h"

syscall1(int, uname, struct utsname *)
