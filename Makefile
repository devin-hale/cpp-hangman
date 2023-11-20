flags=-std=c++23 -g -Wall -Werror -Wextra -pedantic -Wconversion

all: main.o
	g++ $(flags) -o main main.o -lncurses

clean:
	rm *.o main

main.o: main.cpp
	g++ $(flags) -c main.cpp 

