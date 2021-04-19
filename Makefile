
SRC_FILES = ./prime_number.c

all: $(SRC_FILES)
	gcc -o prime_number $^
#-Wall
#clean:
	rm -f *.o
