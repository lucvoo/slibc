#ifndef _SYS_FSUID_H
#define _SYS_FSUID_H

#include "types/gid_t.h"
#include "types/uid_t.h"

int setfsgid(gid_t fsgid);
int setfsuid(uid_t fsuid);

#endif
