#include "userInput/userInput.h"
#include "wordState/wordState.h"
#include <curses.h>
#include <iostream>
#include <ncurses.h>
#include "window/window.h"

void initialize() {
    initscr();
    cbreak();
	noecho();
};

int main() {
	initialize();
	Window w{Window::Type::display};
	Window ui{Window::Type::user};
	
    UserInput usin{ui.getWindow()};
    usin.promptInputType();



	getch();
	endwin();
    return 0;
};
