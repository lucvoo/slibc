#ifndef _TYPES_STACK_T_H
#define _TYPES_STACK_T_H

#include "types/size_t.h"

struct __sigaltstack {
	void		*ss_sp;
	int		ss_flags;
	size_t		ss_size;
};
typedef struct __sigaltstack stack_t;

#endif
