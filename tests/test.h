#ifndef _TEST_H
#define _TEST_H

#include <stdio.h>

void die(const char *msg) __attribute__ ((noreturn));
void die(const char *msg)
{
	perror(msg);
	exit(1);
}

#endif
