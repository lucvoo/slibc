.text
.global _start
_start:
	movl	%esp, %eax		// ELF arguments array

	// set up a false stack frame for gdb
	xorl	%ebp, %ebp
	push	%ebp
	push	%ebp

	push	%edx			// atexit() function
	push	%eax			// ELF array
	pushl	%eax
	call	__libc_init
	hlt				// avoid pblms is return ???

	.size	 _start,.Lstart-_start
