#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>

long double ___scal10(long double, long);
long double ___exp10(long double);

long double strtold(const char *str, char **endptr)
{
	const char *ptr = str;
	long double val;
	unsigned int digit;
	int digit_seen = 0;
	int shift = 0;
	int neg = 0;

	while (isspace(*ptr))
		ptr++;

	if (*ptr == '-') {
		neg = 1;
		ptr++;
	} else if (*ptr == '+')
		ptr++;

// FIXME: how about hexadecimal float?
	val = 0;
	if ((digit = (*ptr - '0')) < 10U) {
		digit_seen = 1;

		do {
			val = val * 10 + digit;
		} while ((digit = (*++ptr - '0')) < 10U);
	}

	if (*ptr != '.')
		goto end_mantise;

	if ((digit = (*++ptr - '0')) < 10U) {
		digit_seen = 1;

		do {
			val = val * 10 + digit;
			shift--;
		} while ((digit = (*++ptr - '0')) < 10U);
	}

end_mantise:
	if (!digit_seen)
		goto error;

	if (_tolower(*ptr) == 'e')	// process exponent part
	{
		long exp;
		int neg = 0;

		digit = *++ptr;
		if (digit == '-') {
			neg = 1;
			ptr++;
		} else if (digit == '+')
			ptr++;

		if ((digit = (*ptr - '0')) >= 10U) {	// exponent seen but without digit!
			goto error;
		}

		exp = 0;
		do
			exp = exp * 10 + digit;
		while ((digit = (*++ptr - '0')) < 10U);

		if (neg)
			exp = -exp;

		shift += exp;
	}
	// do exponent scaling
	if (shift != 0)
		val = ___scal10(val, shift);

	if (endptr)
		*endptr = (char *)ptr;

	if (neg)
		val = -val;

	return val;

error:
	errno = EINVAL;
	return 0;
}
