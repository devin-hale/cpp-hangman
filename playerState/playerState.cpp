#include "playerState.h"
#include <vector>

void PlayerState::addGuess(char ch){
	m_currentGuesses.push_back(ch);
};

void PlayerState::addGuess(std::string_view str){
	m_stringGuess = str;
}

void PlayerState::resetPlayerState(){
	m_currentGuesses = std::vector<char>{};
	m_guessNo = 0;
}
