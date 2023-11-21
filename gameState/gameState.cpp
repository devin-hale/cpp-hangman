#include "gameState.h"
#include "../playerState/playerState.h"
#include "../userInput/userInput.h"
#include "../utils/ignoreLine.h"
#include "../wordState/wordState.h"
#include <iostream>

GameState::GameState() {
    m_wordState = WordState{};
    m_playerState = PlayerState{};
    m_userInput = UserInput{};
};

void GameState::printGameState() {
    std::cout << "\n"
              << "\n--------------------------------------------------\n"
              << "Current Word: " << m_wordState.getDisplay() << "\n\n"
              << "Guesses Remaining: "
              << (m_playerState.getGuessLimit() - m_playerState.getGuessNo())
              << "\n"
              << "Previous Guesses: [";
    if (static_cast<int>(m_playerState.getCurrentGuesses().size()) > 0) {
        for (char ch : m_playerState.getCurrentGuesses()) {

            std::cout << ch << ", ";
        }
    }
    std::cout << "]\n";
    std::cout << "\n--------------------------------------------------\n";
};

void GameState::resetGameState() {
    std::cout << "\n----Game Has Been Reset----\n";
    m_playerState.resetPlayerState();
    m_wordState.resetWordState();
    m_userInput = UserInput{};
};

bool GameState::takeTurn() {
    printGameState();
    UserInput::InputType inputType{m_userInput.promptInputType()};
    bool contains{};
    if (inputType == UserInput::ch) {
        contains = m_wordState.contains(m_userInput.getChar());
    };
    m_userInput.passInput(m_playerState);
    m_wordState.updateDisplay(m_playerState.getCurrentGuesses());
    if (inputType == UserInput::InputType::ch) {
        if (!contains)
            m_playerState.incrementGuessNo();
        std::cout << "\n"
                  << (contains ? "Correct " : "Incorrect ") << "Guess!\n";
    };

    bool win{inputType == UserInput::InputType::ch
                 ? m_wordState.compare()
                 : m_wordState.compare(m_playerState.getStringGuess())};
    return win;
};

bool GameState::playAgain(bool winLose) {
    std::cout << "\n------------------------\n";
    std::cout << "You " << (winLose ? "Won!" : "Lost!") << "\n";
    if (!winLose) {
        std::cout << "The word was: " << m_wordState.getHidden() << "\n";
    }
    std::cout << "\n------------------------\n";
    char input{};
    bool invalidInput{false};
    do {
        if (invalidInput) {
            std::cout << "\nInvalid input.  Please enter 'y' or 'n'.\n";
        };
        std::cout << "Play again? (y/n)\n";
        std::cin >> input;
        if (!std::cin) {
            std::cin.clear();
            ignoreLine();
            input = 0;
        }
        invalidInput = true;
    } while (input != 'y' && input != 'n');

    return input == 'y';
};
