TMP = \
	tst-strtod	\
	bsearch2	\
	nrand		\
	quicksort	\
	strtok		\

PGMS =	\
	a64l-l64a	\
	assert		\
	basename2	\
	child_pid	\
	chown		\
	copy		\
	ctime		\
	ctype		\
	dirname		\
	elf_aux		\
	end_brk		\
	execve		\
	ffs		\
	fork		\
	ftw		\
	getcwd		\
	getcycles	\
	getgrent	\
	getgroups	\
	gethostent	\
	getline		\
	getloadavg	\
	getmntent	\
	getprotoent	\
	getpwent	\
	getservent	\
	getusershell	\
	gmtime		\
	hello		\
	if_index	\
	if_name		\
	inet_aton	\
	inet_ntoa	\
	logger		\
	ls		\
	malloc		\
	memcmp		\
	mkfifo		\
	mktime		\
	mmap		\
	printenv	\
	printenv2	\
	printenv_stdio	\
	printf		\
	progname	\
	ptsname		\
	putenv		\
	rand48		\
	realloc		\
	ret42		\
	stdio		\
	strrchr		\
	strtol		\
	test-mkstemp	\
	ttyname		\


targets := $(PGMS:%=$(subdir)%)

__build: $(targets)

__clean:
	@rm -f $(targets:%=%.o) $(PGMS:%=$(subdir).%.o.d)
	rm -f $(targets)


include Makefile.cfg
## rules
CFLAGS	+= -fno-builtin -g
LDFLAGS += -g

$(targets): %: %.o
	@echo "LD	$@" $(OUT)
	$(Q)$(CC) $(CFLAGS) -specs=arch/$(ARCH)/gcc-specs $(LDFLAGS) $< -o $@

%.s: %.c FORCE
	$(MAKE) -f Makefile.build subdir=$(dir $@) $@
%.o: %.c
	@echo "CC	$@" $(OUT)
	$(Q)$(CC) -Wp,-MD,$(@D)/.$(@F).d $(CFLAGS) $(CPPFLAGS) -c $< -o $@
%.i: %.c FORCE
	@echo "CCP	$@" $(OUT)
	$(Q)$(CC) $(CFLAGS) $(CPPFLAGS) -E -dD $< -o $@

.PHONY: FORCE
FORCE:
-include .make
