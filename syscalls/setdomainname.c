#include <unistd.h>
#include "libc/syscall.h"

syscall2(int, setdomainname, const char *, size_t)
