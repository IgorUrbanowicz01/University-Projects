FLAGS := -g -Wall -std=gnu99 -ggdb

SOURCES = $(wildcard *.c)
HEADERS = $(wildcard *.h)
OBJECTS = $(SOURCES:.c=.o)

.PHONY = all clean cleanall


all: executable

executable: $(OBJECTS)
	gcc $(FLAGS) -o $@ $(OBJECTS)

clean:
	rm -f $(OBJECTS)

cleanall:
	rm -f $(OBJECTS) executable