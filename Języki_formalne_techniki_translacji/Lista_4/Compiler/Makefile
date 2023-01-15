FLAGS := -g -Wall -std=gnu99

SOURCES = $(wildcard *.c)
HEADERS = $(wildcard *.h)
OBJECTS = $(SOURCES:.c=.o)

.PHONY = all clean cleanall

gramar: parser.bison scanner.flex
	bison -Wcounterexamples -v -d -o parser.c -d parser.bison
	flex -o scanner.c scanner.flex

all: $(OBJECTS)
	gcc $(FLAGS) -c -o $@ $<


%.o: %.c $(HEADERS)
    gcc $(FLAGS) -c -o $@ $<

clean:
	@rm -f *.o
	@rm -f *.gch
	@rm -f parser.c scanner.c
	@rm -f parse.output
	@rm -f *_tests/*_tests/*.out
	