#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "../playerState/playerState.h"
#include "../wordState/wordState.h"
#include "../userInput/userInput.h"
#include <string>

class GameState {
  private:
    PlayerState m_playerState{};
    WordState m_wordState{};
	UserInput m_userInput{};

  public:
    GameState();

    const PlayerState& getPlayerState() const { return m_playerState; };

    const WordState& getWordState() const { return m_wordState; };

	void printGameState();

	void resetGameState();

	bool takeTurn();

	bool playAgain(bool);

};

#endif
