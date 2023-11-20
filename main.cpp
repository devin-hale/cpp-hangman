#include <iostream>
#include <ncurses.h>
#include "generateWord/generateWord.h"

void initialize() {
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
};

int main() {

	std::string_view word{GenerateWord::generateWord()};

	std::cout << word << '\n';

	return 0;
};
