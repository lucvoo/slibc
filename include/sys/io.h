#ifndef _SYS_IO_H
#define _SYS_IO_H

int ioperm(unsigned long from, unsigned long num, int turn_on);
int iopl(int level);

#endif
