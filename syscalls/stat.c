#include <sys/stat.h>
#include "libc/syscall.h"

syscall2(int, stat, const char *, struct stat *)
// FIXME: check "struct stat"
