#ifndef _IEEE754_H
#define _IEEE754_H

#include <features.h>
#include <endian.h>

#if __BYTE_ORDER == __BIG_ENDIAN

struct __ieee_f {
	unsigned int negative:1;
	unsigned int exponent:8;
	unsigned int mantissa:23;
};

struct __ieee_f_nan {
	unsigned int negative:1;
	unsigned int exponent:8;
	unsigned int quiet_nan:1;
	unsigned int mantissa:22;
};

struct __ieee_d {
	unsigned int negative:1;
	unsigned int exponent:11;
	unsigned int mantissa0:20;
	unsigned int mantissa1:32;
};

struct __ieee_d_nan {
	unsigned int negative:1;
	unsigned int exponent:11;
	unsigned int quiet_nan:1;
	unsigned int mantissa0:19;
	unsigned int mantissa1:32;
};

struct __ieee_ld {
	unsigned int negative:1;
	unsigned int exponent:15;
	unsigned int empty:16;
	unsigned int mantissa0:32;
	unsigned int mantissa1:32;
};

struct __ieee_ld_nan {
	unsigned int negative:1;
	unsigned int exponent:15;
	unsigned int empty:16;
	unsigned int one:1;
	unsigned int quiet_nan:1;
	unsigned int mantissa0:30;
	unsigned int mantissa1:32;
};

#elif	__BYTE_ORDER == __LITTLE_ENDIAN

struct __ieee_f {
	unsigned int mantissa:23;
	unsigned int exponent:8;
	unsigned int negative:1;
};

struct __ieee_f_nan {
	unsigned int mantissa:22;
	unsigned int quiet_nan:1;
	unsigned int exponent:8;
	unsigned int negative:1;
};

#if __FLOAT_WORD_ORDER == __BIG_ENDIAN

struct __ieee_d {
	unsigned int mantissa0:20;
	unsigned int exponent:11;
	unsigned int negative:1;
	unsigned int mantissa1:32;
};

struct __ieee_d_nan {
	unsigned int mantissa0:19;
	unsigned int quiet_nan:1;
	unsigned int exponent:11;
	unsigned int negative:1;
	unsigned int mantissa1:32;
};

struct __ieee_ld {
	unsigned int exponent:15;
	unsigned int negative:1;
	unsigned int empty:16;
	unsigned int mantissa0:32;
	unsigned int mantissa1:32;
};

struct __ieee_ld_nan {
	unsigned int exponent:15;
	unsigned int negative:1;
	unsigned int empty:16;
	unsigned int mantissa0:30;
	unsigned int quiet_nan:1;
	unsigned int one:1;
	unsigned int mantissa1:32;
};

#elif	__FLOAT_WORD_ORDER == __LITTLE_ENDIAN

struct __ieee_d {
	unsigned int mantissa1:32;
	unsigned int mantissa0:20;
	unsigned int exponent:11;
	unsigned int negative:1;
};

struct __ieee_d_nan {
	unsigned int mantissa1:32;
	unsigned int mantissa0:19;
	unsigned int quiet_nan:1;
	unsigned int exponent:11;
	unsigned int negative:1;
};

struct __ieee_ld {
	unsigned int mantissa1:32;
	unsigned int mantissa0:32;
	unsigned int exponent:15;
	unsigned int negative:1;
	unsigned int empty:16;
};

struct __ieee_ld_nan {
	unsigned int mantissa1:32;
	unsigned int mantissa0:30;
	unsigned int quiet_nan:1;
	unsigned int one:1;
	unsigned int exponent:15;
	unsigned int negative:1;
	unsigned int empty:16;
};

#endif
#endif

union ieee754_float {
	float			f;
	struct __ieee_f		ieee;
	struct __ieee_f_nan	ieee_nan;
};
#define IEEE754_FLOAT_BIAS	0x7f

union ieee754_double {
	double			d;
	struct __ieee_d		ieee;
	struct __ieee_d_nan	ieee_nan;
};
#define IEEE754_DOUBLE_BIAS	0x3ff

union ieee854_long_double {
	long double		d;
	struct __ieee_ld	ieee;
	struct __ieee_ld_nan	ieee_nan;
};
#define IEEE854_LONG_DOUBLE_BIAS 0x3fff

#endif
