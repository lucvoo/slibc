#include <linux/reboot.h>
#include "libc/syscall.h"

#define __NR___sys_reboot	__NR_reboot

syscall4(int, __sys_reboot, int, int, int, void *)
