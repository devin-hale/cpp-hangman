#include "window.h"
#include <curses.h>

Window::Window(Window::Type type) : m_type(type) {
    int width, height, startx, starty;
    switch (type) {
    case Window::Type::user:
        width = COLS;
        height = 5;
        startx = 0;
        starty = 22;
        break;
    case Window::Type::display:
        width = COLS;
        height = 20;
        startx = 0;
        starty = 0;
        break;
    default:
        width = COLS - 1;
        height = 20;
        startx = 0;
        starty = 31;
        break;
    };
    m_window = newwin(height, width, starty, startx);
};

void Window::m_refresh(){
	mvwprintw(m_window, 1, 1, "Words");
	box(m_window, 0, 0);
	wrefresh(m_window);
	refresh();
};
