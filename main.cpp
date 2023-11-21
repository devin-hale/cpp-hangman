#include "gameState/gameState.h"
#include "userInput/userInput.h"
#include "playerState/playerState.h"
#include "wordState/wordState.h"
#include <iostream>

int main() {
    GameState gs{};
    bool gameActive{true};

    while (gameActive) {
        bool winState{gs.takeTurn()};

        if (winState || gs.getPlayerState().getGuessLimit() ==
                            gs.getPlayerState().getGuessNo()) {
            bool playAgain{gs.playAgain(winState)};
			if (!playAgain) {
				gameActive = false;
			} else {
				gs.resetGameState();
			}
        }
    };

    return 0;
};
