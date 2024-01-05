// every time constants.h gets #included into a different code file, each of these variables is
// copied into the including code file. Therefore, if constants.h gets included into 20 different
// code files, each of these variables is duplicated 20 times. Header guards won’t stop this from
// happening, as they only prevent a header from being included more than once into a single
// including file

/*
    - Changing a single constant value would require recompiling every file that includes the
    constants header, which can lead to lengthy rebuild times for larger projects. 
    - If the constants are large in size and can’t be optimized away, this can use a lot of memory.
*/
#include "constants.h" // include a copy of each constant in this file
#include <iostream>

// Because const globals have internal linkage, each .cpp file gets an independent version of the
// global variable that the linker can’t see.

int main() {
    std::cout << "Enter a radius: ";
    double radius{};
    std::cin >> radius;

    std::cout << "The circumference is: " << 2 * radius * constants::pi << '\n';

    return 0;
}

/*
    Global constants as internal variables

    Prior to C++17, the following is the easiest and most common solution:

    Create a header file to hold these constants
    Inside this header file, define a namespace (discussed in lesson 7.2 -- User-defined namespaces
    and the scope resolution operator) Add all your constants inside the namespace (make sure
    they’re constexpr) #include the header file wherever you need it
*/