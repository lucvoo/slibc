#include <sys/timex.h>
#include "libc/syscall.h"

syscall1(int, adjtimex, struct timex *)
 strong_alias(adjtimex, ntp_adjtime);
