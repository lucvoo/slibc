#include <sys/capability.h>
#include "libc/syscall.h"

syscall2(int, capget, cap_user_header_t, const cap_user_data_t)
