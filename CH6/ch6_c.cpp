
#include <iostream>

int add(int x, int y) {
	return x + y;
}

int main() {
	// Increment/decrement operators, and side effects
	// Favor the prefix versions, as they are more performant and less likely to cause surprises.
	int x{5};
	int y{5};
	std::cout << x << ' ' << y << '\n';
	std::cout << ++x << ' ' << --y << '\n'; // prefix
	std::cout << x << ' ' << y << '\n';
	std::cout << x++ << ' ' << y-- << '\n'; // postfix
	std::cout << x << ' ' << y << '\n';
	x = 5;
	int value{add(x, ++x)}; // undefined behavior: is this 5 + 6, or 6 + 6?
	// It depends on what order your compiler evaluates the function arguments in

	std::cout << value
			  << '\n'; // value could be 11 or 12, depending on how the above line evaluates!
	// The C++ standard intentionally does not define these things so that compilers can do whatever
	// is most natural (and thus most performant) for a given architecture.

	// the expression x + ++x is unspecified behavior. When x is initialized to 1, Visual Studio and
	// GCC evaluate this as 2 + 2, and Clang evaluates it as 1 + 2! This is due to differences in
	// when the compilers apply the side effect of incrementing x.

	// The comma operator
	// The comma operator evaluates the left operand, then the right operand, and then returns the
	// result of the right operand.
	std::cout << (++x, ++y) << '\n'; // increment x and y, evaluates to the right operand

	// Note:comma has the lowest precedence of all the operators
	/*
	z = (a, b); // evaluate (a, b) first to get result of b, then assign that value to variable z.
	z = a, b; // evaluates as "(z = a), b", so z gets assigned the value of a, and b is evaluated
	and discarded.
	*/
	return 0;
}

//BestPractice:Avoid using the comma operator, except within for loops and  as a separator