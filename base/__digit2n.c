#include "libc/stdlib.h"

unsigned int __libc_digit2n(unsigned int c)
{
	if ('a' <= c && c <= 'z')
		return c - ('a' - 10);
	if ('A' <= c && c <= 'Z')
		return c - ('A' - 10);
	if ('0' <= c && c <= '9')
		return c - '0';

	return -1;
}
