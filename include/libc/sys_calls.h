#ifndef _LIBC_SYS_CALLS_H
#define _LIBC_SYS_CALLS_H

int __sys_reboot(int magic, int magic2, int cmd, void *arg);
void __sys_syslog(int, const char *, int);
int __sys_tgkill(int, int, int);
int __sys_set_tid_address(int *);

#endif
