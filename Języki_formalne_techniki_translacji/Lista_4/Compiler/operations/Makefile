FLAGS := -g -Wall -std=gnu99 -ggdb

SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

.PHONY = all clean cleanall

all: test.c
	gcc  $(FLAGS) -o main $(SOURCES) ../codeGen/code.c ../codeGen/registerHandler.c

clean:
	@rm -f *.o
	@rm -f *.gch
	@rm -f parser.c scanner.c
	@rm -f parse.output
	@rm -f *_tests/*_tests/*.out
	@rm -f main