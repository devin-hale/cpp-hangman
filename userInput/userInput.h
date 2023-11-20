#ifndef USERINPUT_H
#define USERINPUT_H

#include <curses.h>
#include <string>
#include "../playerState/playerState.h"

class UserInput {
  private:
    char m_char{};
    std::string m_string{""};
	WINDOW* m_window{};

  public:
	UserInput() = delete;

	UserInput(WINDOW*);

	void promptInputType();

	char getCharInput();

	std::string_view getStringInput();

	bool validateCharInput();

	bool validateStringInput();

	void passInput(PlayerState&);
};

#endif
