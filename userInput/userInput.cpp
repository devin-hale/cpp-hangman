#include "userInput.h"
#include "../playerState/playerState.h"
#include <curses.h>
#include <iostream>
#include <ncurses.h>
#include <string>

UserInput::UserInput(WINDOW* w) : m_window(w){};

void UserInput::promptInputType() {
    int input{};
    bool invalidInput{false};

    while (input != 49 && input != 50) {
        wclear(m_window);
        if (invalidInput) {
            wprintw(
                m_window,
                "Invalid input. Please choose from the following options:\n");
            wrefresh(m_window);
        };
        mvwprintw(m_window, 1, 1, "Press '1' to guess a single character.\n");
        mvwprintw(m_window, 2, 1, "Press '2' to guess the entire word.\n");
        box(m_window, 0, 0);
        wrefresh(m_window);
        invalidInput = true;
        input = getch();
    };

    if (input == '1') {
        getCharInput();
    } else {
        getStringInput();
    };
};

char UserInput::getCharInput() {
    m_char = 'a';
    return 'a';
};

std::string_view UserInput::getStringInput() {
    m_string = "string";
    return "string";
};

bool UserInput::validateCharInput() {
    if (m_char >= 41 && m_char <= 90) {
        m_char += 32;
    };
    return !(m_char < 97 || m_char > 122);
};

bool UserInput::validateStringInput() {
    for (int i{0}; i < static_cast<int>(m_string.size()); ++i) {
        if (m_string[i] >= 41 && m_string[i] <= 90) {
            m_string[i] += 32;
        };
		if (m_string[i] < 97 || m_string[i] > 122){
			return false;
		};
    };
	return true;
};

void UserInput::passInput(PlayerState& ps) {
	ps.addGuess(m_char);
	m_char = 0;
	m_string = "";
};
