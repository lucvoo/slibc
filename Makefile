LIBS := \
	libc/	\
	libm/	\

all: $(LIBS)

####
include Makefile.cfg


all: $(LIBS)

$(LIBS): %/: FORCE
	$(Q)$(MAKE) -f Makefile.libs subdir=$(dir $@) __build

tests/: FORCE
	$(Q)$(MAKE) -f tests/Makefile subdir=$(dir $@) __build

tests/%: FORCE
	$(Q)$(MAKE) -f tests/Makefile subdir=$(dir $@) $@

%/: FORCE
	$(Q)$(MAKE) -f Makefile.build subdir=$(dir $@) __build

%.s: FORCE
	$(Q)$(MAKE) -f Makefile.cfg -f Makefile.rules $@

.PHONY: FORCE
FORCE:
