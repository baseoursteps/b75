CC=g++
CFLAGS=-Wall -Wextra
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.out)

.SUFFIXES: .out .cpp

all: $(OBJECTS)

.cpp.out:
	$(CC) $(CFLAGS) $(@:.out=.cpp) -o $@


.PHONY: clean
clean:
	rm -f -- *.out
