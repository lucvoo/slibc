#include <linux/module.h>
#include "libc/syscall.h"

syscall2(int, init_module, const char *, struct module *)
