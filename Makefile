flags=-std=c++23 -g -Wall -Werror -Wextra -pedantic -Wconversion
objects=main.o generateWord.o wordState.o playerState.o userInput.o window.o ignoreLine.o gameState.o

all: $(objects)
	g++ $(flags) $(objects) -o main -lncurses

clean:
	rm *.o main

main.o: main.cpp
	g++ $(flags) -c main.cpp

generateWord.o:
	g++ $(flags) -c ./generateWord/generateWord.cpp

wordState.o:
	g++ $(flags) -c ./wordState/wordState.cpp

playerState.o:
	g++ $(flags) -c ./playerState/playerState.cpp

userInput.o:
	g++ $(flags) -c ./userInput/userInput.cpp

window.o:
	g++ $(flags) -c ./window/window.cpp

ignoreLine.o:
	g++ $(flags) -c ./utils/ignoreLine.cpp

gameState.o:
	g++ $(flags) -c ./gameState/gameState.cpp
