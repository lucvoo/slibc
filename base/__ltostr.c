#include "libc/stdlib.h"
#include "libc/cdefs.h"

// ARGS:        size:   number of byte available in the buffer
// RETURN:      number of digit written,
//              0 if not enough place was available
int __ltostr(char *buf, unsigned size, unsigned long num)
{
	unsigned n;
	unsigned long nbr;

	// count the size needed
	n = 0;
	nbr = num;
	do {
		nbr = nbr / 10;
		n++;
	} while (nbr);

	// check for overflow
	if (__unlikely(n >= size))
		return 0;

	// output the number
	size = n;
	buf[n] = '\0';
	do {
		unsigned char dig;

		dig = num % 10;
		num = num / 10;
		buf[--n] = dig + '0';
	} while (num);

	return size;
}
