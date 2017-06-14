PROGS:=$(patsubst %.c,%,$(wildcard *.c))

.PHONY: all
all: $(PROGS)
	@:

bitmap : bitmap.h
random : bitmap.h

% : %.c
	gcc -Wall -O3 -std=gnu11 -o $@ $<

.PHONY: clean
clean:
	rm -vf $(PROGS) *~ *.o

