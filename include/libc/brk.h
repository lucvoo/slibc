#ifndef _LIBC_BRK_H_
#define _LIBC_BRK_H_

void *__sys_brk(void *);

extern void *__cur_brk;

#endif
