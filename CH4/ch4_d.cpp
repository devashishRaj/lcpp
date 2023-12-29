// if statement(not statements , blocks is convered in CH8)
#include <iostream>

// returns true if x and y are equal, false otherwise
bool isEqual(int x, int y) {
	return (x == y); // operator== returns true if x equals y, and false otherwise
}

// early return
int abs(int x) {
	if (x < 0)
		return -x; // early return (only when x < 0)

	return x;
}

int main() {
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	std::cout << "Enter another integer: ";
	int y{};
	std::cin >> y;

	if (isEqual(x, y))
		std::cout << x << " and " << y << " are equal\n";
	else
		std::cout << x << " and " << y << " are not equal\n";

	// Non-Boolean conditionals
	if (4) // nonsensical, but for the sake of example...
		std::cout << "hi\n";
	else
		std::cout << "bye\n";

	std::cout << abs(4) << '\n';  // prints 4
	std::cout << abs(-3) << '\n'; // prints 3

	return 0;
}