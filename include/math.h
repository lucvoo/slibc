#ifndef _MATH_H
#define _MATH_H

// FIXME

#define HUGE_VAL (__extension__ ((union {	unsigned __l __attribute__((__mode__(__DI__))); double __d; }) { __l: 0x000000007ff00000ULL }).__d)

#define M_LN10l	   2.3025850929940456840179914546843642L	// log_e(10)
#define M_LOG2_10l 3.3219280948873623478703194294893902L	// log_2(10)

long double expl(long double);
long double exp2l(long double);

#endif
