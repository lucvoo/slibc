#include "arch/libc/setjmp.h"

.text
.globl sigsetjmp
	.type	sigsetjmp,@function
sigsetjmp:

	movl 4(%esp), %eax

     	/* Save registers.  */
	movl %ebx, (JB_BX*4)(%eax)
	movl %esi, (JB_SI*4)(%eax)
	movl %edi, (JB_DI*4)(%eax)
	movl %ebp, (JB_BP*4)(%eax) // Save caller's frame pointer
	leal 4(%esp), %edx	// Save SP as it will be after we return
	movl 0(%esp), %ecx	// Save PC we are returning to now
     	movl %edx, (JB_SP*4)(%eax)
     	movl %ecx, (JB_PC*4)(%eax)

	// Make a tail call to __sigjmp_save
	jmp __libc_sigjmp_save
