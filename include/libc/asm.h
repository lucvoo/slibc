#ifndef _LIBC_ASM_H
#define _LIBC_ASM_H

#define ENTRY(symbol)		\
.global	symbol;			\
	.type symbol, @function

#define END(symbol)		\
	.size symbol, . - symbol

#endif
