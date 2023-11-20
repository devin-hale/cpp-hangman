# cpp-hangman
Hangman in the console, written in C++.  Uses NCURSES.

## Purpose
The general purpose of this program is for me to apply what I've learned so far about CPP, and get better at architecture/design using a simple program.  You'll find random bad comments througout the code.  These are not necessarily comments I would leave in a real codebase, but more for my own understanding/learning.

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

### Word Generator
- Takes vector of words, generates random int between 0 and vector.size() - 1.  Returns index of the randomly generated integer.

### WordState Class
- Holds generated word, and display version of that word.
- Constructor generates word.
- Private function that takes char, determines if it exists in hiddenWord non case sensitive
- Update function that takes a vector of guessed chars, and updates display vector based on that.
- Public function that compares display and hidden word, returns bool.
- Public function that takes entire string and compares to hidden word.

### PlayerState Class
- Holds current guesses vector and number of guesses int.
- Getters for each member.
- Add guess to guesses vector.
- Increment number of guesses.
