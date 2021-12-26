CC=g++
CFLAGS=-Wall -Wextra -ggdb3 -O0
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.out)

.SUFFIXES: .out .cpp

all: $(OBJECTS)

.cpp.out:
	$(CC) $(CFLAGS) $(@:.out=.cpp) -o $@


.PHONY: clean
clean:
	rm -f -- *.out
