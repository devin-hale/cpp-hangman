#include "window.h"
#include <curses.h>
#include <stdexcept>

Window::Window(Window::Type type) : m_type(type) {
    int width, height, startx, starty;
    switch (type) {
    case Window::Type::user:
        width = 20;
        height = 5;
        startx = 0;
        starty = 22;
        break;
    case Window::Type::display:
        width = 20;
        height = 10;
        startx = 1;
        starty = 1;
        break;
    default:
        width = 20;
        height = 20;
        startx = 0;
        starty = 31;
        break;
    };
    m_window = newwin(height, width, starty, startx);

    if (m_window == nullptr) {
        throw std::runtime_error("Failed to create window");
    }
};

void Window::m_refresh() {
    if (mvwprintw(m_window, 1, 1, "Words") == ERR) {
        // Handle mvwprintw error
        throw std::runtime_error("Failed to create window");
    }

    if (box(m_window, 0, 0) == ERR) {
        // Handle box error
        throw std::runtime_error("Failed to create window");
    }

    if (wrefresh(m_window) == ERR) {
        // Handle wrefresh error
        throw std::runtime_error("Failed to create window");
    }
};
