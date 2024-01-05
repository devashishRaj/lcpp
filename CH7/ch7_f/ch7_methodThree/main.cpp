#include "constants.h"

#include <iostream>

int main() {
    std::cout << "Enter a radius: ";
    double radius{};
    std::cin >> radius;

    std::cout << "The circumference is: " << 2 * radius * constants::pi << '\n';

    return 0;
}

// This method does retain the downside of requiring every file that includes the constants header
// be recompiled if any constant value is changed.