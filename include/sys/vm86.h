#ifndef _SYS_VM86_H
#define _SYS_VM86_H

struct vm86plus_struct;

int vm86(unsigned long fn, struct vm86plus_struct *v86);

#endif
