PROGS:=$(patsubst %.c,%,$(wildcard *.c))

.PHONY: all
all: $(PROGS)
	@:

random missing: bitmap.h

% : %.c
	gcc -Wall -O3 -std=c99 -o $@ $<

.PHONY: clean
clean:
	rm -vf $(PROGS) *~ *.o

