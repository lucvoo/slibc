#include <sys/time.h>
#include "libc/syscall.h"

syscall2(int, settimeofday, const struct timeval *, const struct timezone *)
