// argc := sp[0]
// argv := sp[1]
// envp := argv + argc + 1

	.file	"_start.S"
	.text
	.global _start
	.type _start,@function
_start:
	stwu	1,-16(1)	// setup the initial stack frame
	addi	3,1,16

	mr	4,7		// r7: ptr to a termination function ?

	bl	__libc_init

	.size _start,.-_start
