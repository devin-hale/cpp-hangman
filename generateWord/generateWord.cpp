#include "generateWord.h"
#include "random.h"

namespace GenerateWord {
std::vector<std::string_view> words{
    "Octopus",    "Firefighter",   "Mario",   "Platypus",  "Square",
    "Lovelace",   "Qualification", "Marsh",   "Loki",      "Helicopter",
    "Watermelon", "Apple",         "Buffalo", "Blue",      "Jupiter",
    "Asteroid",   "Nintendo",      "Sony",    "Microsoft", "Facebook",
    "Twitter",    "Chicken",       "Empire",  "Samus",     "Link",
    "Blizzard",   "Arthas"};

std::string_view generateWord() {
    int random{Random::get<int>(0, static_cast<int>(words.size()) - 1)};

    return words[random];
};
} // namespace GenerateWord
