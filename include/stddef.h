#ifndef _STDDEF_H
#define _STDDEF_H

#include "values/NULL.h"

// Macros definitions
#define offsetof(TYPE, MEMBER)	((size_t) &((TYPE*)0)->MEMBER)

#include "arch/types/size_t.h"
#include "arch/types/ptrdiff_t.h"

#endif
