#include "wordState/wordState.h"
#include <iostream>
#include <ncurses.h>

void initialize() {
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
};

int main() {
	WordState word{};

	std::cout << word.getDisplay() << '\n';

	word.updateDisplay({'a', 'b', 'c', 'd'});

	std::cout << word.getDisplay() << '\n';
    return 0;
};
