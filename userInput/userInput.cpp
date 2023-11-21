#include "userInput.h"
#include "../playerState/playerState.h"
#include "../utils/ignoreLine.h"
#include <curses.h>
#include <iostream>
#include <ncurses.h>
#include <string>

UserInput::InputType UserInput::promptInputType() {
    int input{};
    bool invalidInput{false};
    std::cout << "\n";
    while (input != 1 && input != 2) {
		std::cout << "\n";
        if (invalidInput) {
            std::cout << "Invalid selection.\n";
        };
        std::cout << "Enter 1 to guess a single character.\n"
                  << "Enter 2 to guess the entire word.\n"
                  << ": ";
        std::cin >> input;
        ignoreLine();
        if (!std::cin) {
            std::cin.clear();
            ignoreLine();
        }
        invalidInput = true;
    };

    if (input == 1) {
        getCharInput();
        m_inputType = InputType::ch;
        return UserInput::InputType::ch;
    } else {
        getStringInput();
        m_inputType = InputType::string;
        return UserInput::InputType::string;
    };
};

char UserInput::getCharInput() {
    char charInput{0};
    bool invalidInput{false};
    while (!(charInput >= 41 && charInput <= 90) &&
           !(charInput >= 97 && charInput <= 122)) {
		std::cout << "\n";
        if (invalidInput) {
            std::cout << "Invalid input.\n";
        };
        std::cout << "Please enter a single character: ";

        std::cin >> charInput;
		ignoreLine();
        if (!std::cin) {
            std::cin.clear();
            ignoreLine();
        }
        if (!validateCharInput(charInput)) {
            charInput = 0;
        }
        invalidInput = true;
    };
    m_char = charInput;
    return charInput;
};

std::string UserInput::getStringInput() {
    std::string stringInput{};
    bool invalidInput{false};
    bool inputting{true};
    while (inputting) {
		stringInput = "";
		std::cout << "\n";
        if (invalidInput) {
            std::cout << "Invalid input.\n";
        };
        std::cout << "Please enter an entire word: ";

        std::getline(std::cin >> std::ws, stringInput);
        if (!std::cin) {
            std::cin.clear();
            ignoreLine();
        }
        if (!validateStringInput(stringInput)) {
            invalidInput = true;
        } else {
            inputting = false;
        }
    };
    m_string = stringInput;
    return stringInput;
};

bool UserInput::validateCharInput(char ch) {
    if (ch >= 41 && ch <= 90) {
        ch += 32;
    };
    return ch > 97 || ch < 122;
};

bool UserInput::validateStringInput(std::string string) {
    for (int i{0}; i < static_cast<int>(string.size()); ++i) {
        if (string[i] >= 41 && string[i] <= 90) {
            string[i] += 32;
        };
        if (string[i] < 97 || string[i] > 122) {
            return false;
        };
    };
    return true;
};

void UserInput::passInput(PlayerState& ps) {
    if (m_inputType == InputType::ch) {
        ps.addGuess(m_char);
        m_char = 0;
        m_string = "";
    } else {
        ps.addGuess(m_string);
        m_char = 0;
        m_string = "";
    }
    m_inputType = InputType::empty;
};
