#ifndef _LIBC_STDLIB_H
#define _LIBC_STDLIB_H

static inline long __atol(const char *str)
{
	long l;
	int sign;

	if (*str == '-') {
		str++;
		sign = 1;
	} else
		sign = 0;

	for (l = 0; ('0' <= *str) && (*str <= '9'); str++)
		l = l * 10 + *str - '0';

	if (sign)
		return -l;
	else
		return l;
}

static inline unsigned long __atoul(const char *str)
{
	unsigned long l;

	for (l = 0; ('0' <= *str) && (*str <= '9'); str++)
		l = l * 10 + *str - '0';

	return l;
}

int __ltostr(char *buf, unsigned size, unsigned long num);
unsigned __libc_digit2n(unsigned int);

#endif
