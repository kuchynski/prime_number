
SRC_FILES_C = ./prime_number.c
SRC_FILES_CPP = ./prime_number.cpp

c: $(SRC_FILES_C)
	gcc -o prime_number $^
#-Wall
#clean:
	rm -f *.o

cpp: $(SRC_FILES_CPP)
	g++ -std=c++17 -o prime_number_cpp $^
