// A multi-file example
// open terminal and go to ch2 folder and run the following line if you are using llvm(clang)
// clang++ -std=c++20 -Wall -g -glldb CH2/ch2_g.cpp CH2/add.cpp -o bin/test
// then run " ./bin/test "
#include <iostream>
int add(int x, int y);
int main() {
	//:: symbol is an operator called the scope resolution operator
	// BESTPRACTICE:Use explicit namespace prefixes to access identifiers defined in a namespace.
	std::cout << add(3, 5) << '\n';
}

// Warning:Avoid using-directives (such as using namespace std;) at the top of your program or in
// header files. They violate the reason why namespaces were added in the first place.

/*
Most naming collisions occur in two cases:

- Two (or more) identically named functions (or global variables) are introduced into separate
files belonging to the same program. This will result in a linker error, as shown above.

- Two (or more) identically named functions (or global variables) are introduced into the same file.
This will result in a compiler error
*/