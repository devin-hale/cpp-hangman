flags=-std=c++23 -g -Wall -Werror -Wextra -pedantic -Wconversion
objects=main.o generateWord.o

all: $(objects)
	g++ $(flags) $(objects) -o main -lncurses

clean:
	rm *.o main

main.o: main.cpp
	g++ $(flags) -c main.cpp

generateWord.o:
	g++ $(flags) -c ./generateWord/generateWord.cpp
