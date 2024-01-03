// operator precedence and associativity
// Precedence level 1 is the highest precedence level, and level 17 is the lowest. Operators with a
// higher precedence level have their operands grouped first.Precedence level 1 is the highest
// precedence level, and level 17 is the lowest. Operators with a higher precedence level have their
// operands grouped first.

// BestPractice:
// Use parenthesis to make compound expressions easier to understand , Parenthesize everything,
// except addition, subtraction, multiplication, and division.

/*
x = (y + z + w);   // instead of this
x = y + z + w;     // it's okay to do this

x = ((y || z) && w); // instead of this
x = (y || z) && w;   // it's okay to do this

x = (y *= z); // expressions with multiple assignments still benefit from parenthesis
*/

#include <iostream>

int getVal() {
	int x;
	std::cin >> x;
	return x;
}

int main() {

	// if you run this program and enter inputs 1, 2, and 3, you might assume that this program
	// would calculate 1 + (2 * 3) and print 7. But that is making the assumption that the calls to
	// getValue() will evaluate in left-to-right order. The compiler may choose a different order.
	// For example, if the compiler chose a right-to-left order instead, the program would calculate
	// 3 + (2 * 1), which would print 5 for the same set of inputs.
	std::cout << getVal() + (getVal() * getVal());

	// order of eval doesn't matter now
	int a{getVal()}; // will execute first
	int b{getVal()}; // will execute second
	int c{getVal()}; // will execute third
	std::cout << a + (b * c) << '\n';

	// Integer and floating point division
	// If either (or both) of the operands are floating point values, the division operator performs
	// floating point division. Floating point division returns a floating point value, and the
	// fraction is kept. For example, 7.0 / 4 = 1.75, 7 / 4.0 = 1.75, and 7.0 / 4.0 = 1.75.
	int x{7};
	int y{4};

	std::cout << "int / int = " << x / y << '\n';
	std::cout << "double / int = " << static_cast<double>(x) / y << '\n';
	std::cout << "int / double = " << x / static_cast<double>(y) << '\n';
	std::cout << "double / double = " << static_cast<double>(x) / static_cast<double>(y) << '\n';

	// Division by ZERO
	// The result of dividing by floating point value 0.0 is implementation-defined
	// On architectures that support IEEE754 floating point format, the result will be NaN or Inf


	return 0;
}