// Header files and header guards
// to use ch2_i.cpp run the following command in the terminal
// clang++ -std=c++20 -Wall -g -glldb CH2/ch2_i.cpp CH2/square.cpp -o bin/test
// then run " ./bin/test "

// When we use angled brackets, we’re telling the preprocessor that this is a header file we didn’t
// write ourselves. The preprocessor will search for the header only in the directories specified by
// the include directories
#include "square.h"
#include <iostream>
// Including header files from other directories
//  avoid following methods
// #include "headers/myHeader.h"
// #include "../moreHeaders/myOtherHeader.h"

// use include directory in cmake that will tell ide or make to look at the particular location.
//  thus if the porject location shifts , you only have to make modification in one file .

// NOTE:Each file should explicitly #include all of the header files it needs to compile. Do not
// rely on headers included transitively from other headers.

int main() {
	std::cout << "a square has " << getSquareSides() << " sides\n";
	std::cout << "a square of length 5 has perimeter length " << getSquarePerimeter(5) << '\n';

	return 0;
}

/*
If a header file without a .h extension declares names into the global namespace, avoid those names,
as they may not be available in the global namespace on other compilers. Prefer the names declared
in the std namespace instead.
*/