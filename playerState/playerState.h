#ifndef PLAYERSTATE_H
#define PLAYERSTATE_H

#include <vector>
#include <string>

class PlayerState {
  private:
    std::vector<char> m_currentGuesses{};
	std::string_view m_stringGuess{};
	int m_guessLimit{6};
    int m_guessNo{0};
	bool m_win{false};

  public:
    std::vector<char>& getCurrentGuesses() { return m_currentGuesses; };

	std::string_view getStringGuess() const {return m_stringGuess;};

	int getGuessLimit() const {return m_guessLimit;};

    void addGuess(char);
	void addGuess(std::string_view);

    int getGuessNo() const { return m_guessNo; };

    void incrementGuessNo() { ++m_guessNo; };

	void resetPlayerState();
};

#endif
