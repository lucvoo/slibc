#include <unistd.h>
#include "libc/syscall.h"
#include "libc/config.h"

syscall2(int, setregid, gid_t, gid_t)
