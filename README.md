# cpp-hangman
Hangman in the console, written in C++.  Uses NCURSES.

## Purpose
The general purpose of this program is for me to apply what I've learned so far about CPP, and get better at architecture/design using a simple program.

## Design

### Abstract of Game Logic
1. Generate word.
2. Display UI with spaces, hangman, etc.
3. Take user char input.
4. Determine if user input matches any letters in the word.
5. Check win/lose condition.
6. Update UI.
7. If no win/lose, go back to 3.
8. If win/lose, update UI with win/lose screen.

### Controller
- Handles high level logic, calls other functions/components.

