#include <sys/select.h>
#include "libc/syscall.h"

syscall5(int, select, int, fd_set *, fd_set *, fd_set *, struct timeval *)
