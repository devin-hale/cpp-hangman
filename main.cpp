#include "userInput/userInput.h"
#include "wordState/wordState.h"
#include <curses.h>
#include <iostream>
#include <ncurses.h>

void initialize() {
    initscr();
    cbreak();
	noecho();
};

int main() {
	initialize();
    WINDOW* myWin{newwin(10, 100, 0, 0)};
	refresh();
	
    UserInput usin{myWin};

    usin.promptInputType();

	getch();
	endwin();
    return 0;
};
