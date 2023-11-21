#include "wordState.h"
#include "../generateWord/generateWord.h"
#include <algorithm>
#include <string>
#include <vector>

// Constructor generates random word. Sets hiddenword member. Creates
// displayword member based on this.
WordState::WordState() {
    m_hiddenWord = GenerateWord::generateWord();

    std::string displayWord{};

    // For every char in generated word, push a '_' to displayWord
    for (int i{0}; i < static_cast<int>(m_hiddenWord.size()); ++i) {
        displayWord.push_back('_');
    };

    m_displayWord = displayWord;
};

void WordState::updateDisplay(const std::vector<char>& guesses) {
    // Loop through hiddenWord member to check for guesses
    for (int i{0}; i < static_cast<int>(m_hiddenWord.size()); ++i) {
        // std::find from <algorithm> to check if element is in guesses
        if (std::find(guesses.begin(), guesses.end(), m_hiddenWord[i]) !=
            guesses.end()) {
            // if found
            m_displayWord[i] = m_hiddenWord[i];
        };
    };
};

bool WordState::compare() const { return m_hiddenWord == m_displayWord; };

bool WordState::compare(std::string_view string) const {
    return m_hiddenWord == string;
};

void WordState::resetWordState() {
    m_hiddenWord = GenerateWord::generateWord();

    std::string displayWord{};

    // For every char in generated word, push a '_' to displayWord
    for (int i{0}; i < static_cast<int>(m_hiddenWord.size()); ++i) {
        displayWord.push_back('_');
    };

    m_displayWord = displayWord;
};

bool WordState::contains(char ch) const {
	return static_cast<int>(m_hiddenWord.find(ch)) >= 0;
};
