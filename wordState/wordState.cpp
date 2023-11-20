#include "wordState.h"
#include "../generateWord/generateWord.h"
#include <string>
#include <vector>
#include <algorithm>

//Constructor generates random word. Sets hiddenword member. Creates displayword member based on this.
WordState::WordState() {
	std::string_view hiddenWord{GenerateWord::generateWord()};

	m_hiddenWord = hiddenWord;

	std::string displayWord{};

	//For every char in generated word, push a '_' to displayWord
	for(int i{0}; i < static_cast<int>(m_hiddenWord.size()); ++i) {
		displayWord.push_back('_');
	};

	m_displayWord = displayWord;
};

WordState& WordState::updateDisplay(const std::vector<char>& guesses) {
	//Loop through hiddenWord member to check for guesses
	for(int i{0}; i < static_cast<int>(m_hiddenWord.size()); ++i) {
		//std::find from <algorithm> to check if element is in guesses
		if(std::find(guesses.begin(), guesses.end(), m_hiddenWord[i]) != guesses.end()) {
			//if found
			m_displayWord[i] = m_hiddenWord[i];
		};
	};
	//Returns ref to class instance for method chaining
	return *this;
};

bool WordState::compare() {
	return m_hiddenWord == m_displayWord;
};
