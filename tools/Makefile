ROOT=..
include $(ROOT)/Make.cfg

CC = $(HOSTCC)
CFLAGS = -Wall -W -Wwrite-strings
CPPFLAGS = -I.

PGMS =	\
	mkheader	\


all: $(PGMS)

clean:
	rm -f $(PGMS)
	@rm -f *.o *.s *.i core.* core log log.* zz.*

-include .make
