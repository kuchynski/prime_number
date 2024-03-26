
SRC_FILES_C = ./prime_number.c
SRC_FILES_CPP = ./prime_number.cpp
SRC_FILES_CPP_DYNAMIC = ./prime_number_dynamic.cpp

c: $(SRC_FILES_C)
	gcc -o prime_number $^
#-Wall
#clean:
	rm -f *.o

cpp: $(SRC_FILES_CPP)
	g++ -std=c++2a -fconcepts -o prime_number_cpp $^

cpp_dynamic: $(SRC_FILES_CPP_DYNAMIC)
	g++ -std=c++2a -fconcepts -o prime_number_cpp_dynamic $^
