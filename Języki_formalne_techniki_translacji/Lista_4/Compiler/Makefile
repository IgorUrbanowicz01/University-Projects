FLAGS := -g -Wall -std=gnu99 -ggdb

SOURCES = $(wildcard *.c codeGen/*.c)
HEADERS = $(wildcard *.h)
OBJECTS = $(SOURCES:.c=.o)

.PHONY = all clean cleanall

build: gramar all

all: main.c
	gcc  $(FLAGS) -o main $(SOURCES) 


gramar: parser.bison scanner.flex
	bison -Wcounterexamples -v -d -o parser.c -d parser.bison
	flex -o scanner.c scanner.flex


clean:
	@rm -f *.o
	@rm -f *.gch
	@rm -f parser.c scanner.c
	@rm -f parse.output
	@rm -f *_tests/*_tests/*.out
	@rm -f main

	