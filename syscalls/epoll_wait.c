#include <sys/epoll.h>
#include "libc/syscall.h"

#ifdef __NR_epoll_wait
syscall4(int, epoll_wait, int, struct epoll_event *, int, int)
#endif
