#include <iostream>
int main() {

	// Prefer direct list initialization (or value initialization)

	// initializing your variables.
	int a = 5, b = 6; // copy initialization
	int c(7), d(8);	  // direct initialization

	// Copy and direct initialization would simply drop the fractional part,
	int e{9}, f{10};	   // direct brace initialization
	int g = {9}, h = {10}; // copy brace initialization
	int i{}, j{};		   // value initialization , zero initialization to value 0
	int gg;				   // default initialization leaves a variable with an indeterminate
						   // value

	//  the compiler will likely optimize these variables out of the program
	[[maybe_unused]] double pi{3.14159};

	std::cout << 5 << a; // literal value 5 is compiled directly into the program while
						 //  value of a is  fetched from memory(locaiton of 'a') during execution.

	// Expressions involving operators with side effects are a little more tricky:
	int x = 5;		// x = 5 has side effect of assigning 5 to x, evaluates to x
	x = 2 + 3;		// has side effect of assigning 5 to x, evaluates to x
	std::cout << x; // has side effect of printing value of x to console, evaluates to std::cout
    // also std::cout << x is an expresion statement (hint binary << operator.)
	// Statements are used when we want the program to perform an action. Expressions are used when
	// we want the program to calculate a value

}