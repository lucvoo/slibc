#include <sys/epoll.h>
#include "libc/syscall.h"

#ifdef __NR_epoll_ctl
syscall4(int, epoll_ctl, int, int, int, struct epoll_event *)
#endif
