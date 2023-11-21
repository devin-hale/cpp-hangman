#ifndef WINDOW_H
#define WINDOW_H

#include <curses.h>
#include "../playerState/playerState.h"
#include "../wordState/wordState.h"
#include <string>

class Window {
  public:
    enum Type { global, display, user, error, win, lose };

  private:
    WINDOW* m_window{nullptr};
    Type m_type{};


  public:
	Window() = delete;

	Window(Type type);

	void m_refresh();

	WINDOW* getWindow(){return m_window;};

	void writeText(std::string_view, int);

	void updateDisplay(WordState&, PlayerState&);

};

#endif
