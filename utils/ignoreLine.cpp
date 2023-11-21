#include "ignoreLine.h"
#include <iostream>
#include <limits>

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
};

