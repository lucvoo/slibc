/* entry point: first thing in .text section
   NOTE: .init code has already been run

   r0:	contain a function pointer to be registered with `atexit'.
	=> _fini
	Only used for dynamic library

   sp:	contains the arguments and environment:
	sp[0]		argc
	sp[4]		argv[0]
	...
	sp[argc*4]	NULL
	sp[argc*4+4]	envp[0]
	...
*/

.text
.global	_start
_start:
	mov	fp, #0                  @ clear the frame pointer
	mov	r1, r0
	mov	r0, sp
	bl	__libc_init

	.size	_start,.-_start
