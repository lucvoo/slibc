#include <grp.h>
#include "libc/syscall.h"
#include "libc/config.h"

syscall2(int, setgroups, size_t, const gid_t *)
