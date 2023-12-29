// Booleans

// NOTE:typically bool returning functions are named starting with the word is (e.g. isEqual) or has
// (e.g. hasCommonDivisor).

#include <iostream>

int main() {
	bool b1{true};
	bool b2{false};
	b1 = false;
	bool b3{}; // default initialize to false

	bool b4{!true};	 // b1 will be initialized with the value false
	bool b5{!false}; // b2 will be initialized with the value true
	// print as 1 and 0
	std::cout << true << '\n';
	std::cout << false << '\n';

	std::cout << std::boolalpha; // print bools as true or false

	std::cout << true << '\n';
	std::cout << false << '\n';

	std::cout << std::noboolalpha;
	std::cout << true << '\n';
	std::cout << false << '\n';

	bool bFalse{0}; // okay: initialized to false
	bool bTrue{1};	// okay: initialized to true
				   // bool bNo    { 2 }; // error:narrowing conversions disallowed

	std::cout << std::boolalpha;
	bool b6 = 4; // copy initialization allows implicit conversion from int to bool
	std::cout << b6 << '\n';
	bool b7 = 0; // copy initialization allows implicit conversion from int to bool
	std::cout << b7 << '\n';

	// NOTE:std::cin only accepts two inputs for Boolean variables: 0 and 1 (not true or false). Any
	// other inputs will cause std::cin to silently fail.
	bool b{}; // default initialize to false
	std::cout << "Enter a boolean value: ";
	std::cin >> b;
	std::cout << "You entered: " << b << '\n';

	// Warning:Enabling std::boolalpha will only allow lower-cased “false” or “true” to be accepted.
	// Variations with capital letters will not be accepted.
	bool ba{};
	std::cout << "Enter a boolean value: ";
	std::cin >> std::boolalpha;
	std::cin >> ba;
	std::cout << "You entered: " << ba << '\n';
}