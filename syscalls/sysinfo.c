#include <sys/sysinfo.h>
#include "libc/syscall.h"

syscall1(int, sysinfo, struct sysinfo *)
