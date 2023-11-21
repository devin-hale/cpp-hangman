#ifndef WORDSTATE_H
#define WORDSTATE_H

#include <string>
#include <vector>

class WordState {
	private:
		//String view because once generated, the word does not need to be updated.
		std::string_view m_hiddenWord{""};
		//String because the display word will need to be updated. Can pass as string view where needed.
		std::string m_displayWord{""};

	public:
		WordState();

		std::string_view getHidden()const{return m_hiddenWord;};
		
		std::string_view getDisplay(){return m_displayWord;};
		
		void updateDisplay(const std::vector<char>&);

		bool compare() const;

		bool compare(std::string_view) const;

		bool contains(char) const;

		void resetWordState();
};

#endif
