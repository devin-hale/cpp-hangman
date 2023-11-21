#include "generateWord.h"
#include "random.h"

namespace GenerateWord {
std::vector<std::string_view> words{
    "octopus",    "firefighter",   "mario",   "platypus",  "square",
    "lovelace",   "qualification", "marsh",   "loki",      "helicopter",
    "watermelon", "apple",         "buffalo", "blue",      "jupiter",
    "asteroid",   "nintendo",      "sony",    "microsoft", "facebook",
    "twitter",    "chicken",       "empire",  "samus",     "link",
    "blizzard",   "arthas"};

std::string_view generateWord() {
    int random{Random::get<int>(0, static_cast<int>(words.size()) - 1)};

    return words[random];
};
} // namespace GenerateWord
