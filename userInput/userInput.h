#ifndef USERINPUT_H
#define USERINPUT_H

#include "../playerState/playerState.h"
#include <curses.h>
#include <string>

class UserInput {
  public:
    enum InputType { ch, string, empty };

  private:
    char m_char{};
    std::string m_string{""};
	InputType m_inputType{InputType::empty};

  public:
	char getChar(){return m_char;};

    InputType promptInputType();

    char getCharInput();

    std::string getStringInput();

    bool validateCharInput(char);

    bool validateStringInput(std::string);

    void passInput(PlayerState&);
};

#endif
