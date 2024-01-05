#include <iostream>
// A compound statement (also called a block, or block statement) is a group of zero or more
// statements that is treated by the compiler as if it were a single statement.
// Blocks begin with a { symbol, end with a } symbol
int add(int x, int y) { // block
	return x + y;
} // end block

int main() {
	// multiple statements
	int value{};

	{ // inner/nested block
		add(3, 4);
	} // end inner/nested block

	// Using blocks to execute multiple statements conditionally
	// Block nesting levels
	//  block 1, nesting level 1
	std::cout << "Enter an integer: ";
	std::cin >> value;

	if (value > 0) {			// block 2, nesting level 2
		if ((value % 2) == 0) { // block 3, nesting level 3
			std::cout << value << " is positive and even\n";
		} else { // block 4, also nesting level 3
			std::cout << value << " is positive and odd\n";
		}
	}
	/*
		The nesting level (also called the nesting depth) of a function is the maximum number of
	   nested blocks you can be inside at any point in the function (including the outer block). In
	   the above function, there are 4 blocks, but the nesting level is 3 since in this program you
	   can never be inside more than 3 blocks at any point.
	*/

	return 0;
}

// BestPractice:Keep the nesting level of your functions to 3 or less. If your function has a need
// for more nested levels, consider refactoring your function into sub-functions.