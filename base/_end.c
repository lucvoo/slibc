#include <values/NULL.h>

typedef void (*fn_t) (void);

fn_t __CTOR_END__[1] __attribute__ ((section(".ctors"), unused)) = {
NULL};
