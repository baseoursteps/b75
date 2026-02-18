CC=g++
CFLAGS=-Wall -Wextra -ggdb3 -O0
SOURCES=$(wildcard *.cc)
OBJECTS=$(SOURCES:.cc=.out)

.SUFFIXES: .out .cc

all: $(OBJECTS)

.cc.out:
	$(CC) $(CFLAGS) $(@:.out=.cc) -o $@


.PHONY: clean
clean:
	rm -f -- *.out
