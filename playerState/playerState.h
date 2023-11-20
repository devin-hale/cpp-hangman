#ifndef PLAYERSTATE_H
#define PLAYERSTATE_H

#include <vector>

class PlayerState {
  private:
    std::vector<char> m_currentGuesses{};
    int m_guessNo{0};

  public:
    std::vector<char>& getCurrentGuesses() { return m_currentGuesses; };

    void addGuess(char);

    int getGuessNo() { return m_guessNo; };

    void incrementGuessNo() { ++m_guessNo; };
};

#endif
