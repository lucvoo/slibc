#include <arch/sys/syscall.h>

.globl _exit
	.type	_exit, @function
_exit:
	movl	$1, %eax
	movl	4(%esp), %ebx	#  arg1,  arg1
	int	$0x80

	.size	_exit, .-_exit
