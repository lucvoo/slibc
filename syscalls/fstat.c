#include <sys/stat.h>
#include "libc/syscall.h"

syscall2(int, fstat, int, struct stat *)
// FIXME: check "struct stat"
