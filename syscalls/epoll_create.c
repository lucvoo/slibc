#include <sys/epoll.h>
#include "libc/syscall.h"

#ifdef __NR_epoll_create
syscall1(int, epoll_create, int)
#endif
