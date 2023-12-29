// In programming, a constant is a value that may not be changed during the program’s execution.

// Named constants are constant values that are associated with an identifier. These are also
// sometimes called symbolic constants, or occasionally just constants.

// A type qualifier (sometimes called a qualifier for short) is a keyword that is applied to a type
// that modifies how that type behaves.

#include <iostream>
int main() {
	// const double gravity; // error:const variables must be initialized
	// gravity = 9.9;        // error:const variables can not be changed
	const double gravity{9.8};	// preferred use of const before type
	int const sidesInSquare{4}; // "east const" style, okay but not preferred

	// Note:that const variables can be initialized from other variables (including non-const ones):
	std::cout << "Enter your age: ";
	int age{};
	std::cin >> age;
	const int constAge{age}; // initialize const variable using non-const value
	age = 5;				 // ok: age is non-const, so we can change its value
	// constAge = 6; // error:constAge is const, so we cannot change its value

	// Naming your const variables : if in a source-code you see a var like "EARTH_GRAVITY" or
	// kEarthGravity they are probably const vars .

	/*
	Prefer constant variables to preprocessor macros
	The biggest issue is that macros don’t follow normal C++ scoping rules.
	Second, it is often harder to debug code using macros. Although your source code will have the
	macro’s name, the compiler and debugger never see the macro because it has already been replaced
	before they run. Many debuggers are unable to inspect a macro’s value, and often have limited
	capabilities when working with macros.

	Third, macros substitution behaves differently than everything else in C++
	*/
}
// BestPractice:
// Place const before the type (because it is more conventional to do so).
// Don’t use const when passing by value.
// Don’t use const when returning by value.
// Prefer constant variables over object-like macros with substitution text.
