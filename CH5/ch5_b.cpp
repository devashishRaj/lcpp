
// The as-if rule says that the compiler can modify a program however it likes in order to produce
// more optimized code, so long as those modifications do not affect a program’s “observable
// behavior”.

// An expression that must be evaluated at runtime is sometimes called a runtime expression.
// A constant expression is an expression that can be evaluated by the compiler at compile-time

// A compile-time constant is a constant whose value is known at compile-time. Literals (e.g. ‘1’,
// ‘2.3’, and “Hello, world!”) are one type of compile-time constant.

// When you declare a const variable using the const keyword, the compiler will implicitly keep
// track of whether it’s a runtime or compile-time constant.

#include <iostream>

int getNumber() {
	std::cout << "Enter a number: ";
	int y{};
	std::cin >> y;

	return y;
}

int main() {
	// Making variables compile-time constants helps the compiler determine what can be optimized.
	const int x{3}; // x is a compile time constant

	const int y{getNumber()}; // y is a runtime constant

	const int z{x + y}; // x + y is a runtime expression, so z is a runtime const

	// Constexpr variables
	// A constexpr (which is short for “constant expression”) variable can ONLY be a compile-time
	// constant.
	constexpr double gravity{9.8}; // ok: 9.8 is a constant expression
	constexpr int sum{4 + 5};	   // ok: 4 + 5 is a constant expression
	constexpr int something{sum};  // ok: sum is a constant expression

	std::cout << "Enter your age: ";
	int age{};
	std::cin >> age;

	// constexpr int myAge { age };      // compile error: age is not a constant expression
	// constexpr int f { five() };       // compile error: return value of five() is not a constant
	// expression

	// NOTE:Because constexpr objects must be initialized with a compile-time constant (not a
	// runtime constant), function parameters cannot be declared as constexpr.

	// full expression std::cout << 3 + 4 << '\n' is not a constant expression but compilers can
	// optimze contant subexpressions , this optimzation process is called "Constant folding".

	// Literals
	// Literals are sometimes called literal constants because their meaning cannot be redefined (5
	// always means the integral value 5).

	// type of a literal
	// int float Boolean c-style strings char
	std::cout << 5 << '\n';	   // 5 (no suffix) is type int (by default)
	std::cout << 5L << '\n';   // 5L is type long
	std::cout << 5u << '\n';   // 5u is type unsigned int
	std::cout << 5.0 << '\n';  // 5.0 (no suffix) is type double (by default)
	std::cout << 5.0f << '\n'; // 5.0f is type float

	// float f{4.1};			   // warning:4.1 is a double literal by default, not a float
	// literal
	float f{4.1f}; // use 'f' suffix so the literal is a float and matches variable type of float
	double d{4.1}; // change variable to type double so it matches the literal type double
	double avogadro{6.02e23};		// 6.02 x 10^23 is a double literal in scientific notation
	double electronCharge{1.6e-19}; // charge on an electron is 1.6 x 10^-19

	// string literal
	//"Hello, world!" is a string literal. String literals are placed between double quotes to
	// identify them as strings
	std::cout << "Hello, world!";

	// two non-obvious things worth knowing about C-style string literals.

	// 1.All C-style string literals have an implicit null terminator , a char : '\0'
	// the string "Hello, world!" has type const char[14] rather than const char[13]

	// 2.C-style string literals are const objects that are created at the start of the program and
	// are guaranteed to exist for the entirety of the program.

	// Magic numbers: A magic number is a literal (usually a number) that either has an unclear
	// meaning or may need to be changed later.

	return 0;
}

// BestPractice:

/*
Any variable that should not be modifiable after initialization and whose initializer is known at
compile-time should be declared as constexpr.

Any variable that should not be modifiable after
initialization and whose initializer is not known at compile-time should be declared as const.
*/

// Prefer literal suffix L (upper case) over l (lower case).
//Avoid magic numbers in your code (use constexpr variables instead).