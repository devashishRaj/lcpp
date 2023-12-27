/*
When a function is called, all of the parameters of the function are created as variables, and the
value of each of the arguments is copied into the matching parameter (using copy initialization).
This process is called pass by value. Function parameters that utilize pass by value are called
value parameters.
*/

#include <iostream>

int add(int x, int y) { return x + y; }

int mutliply(int x, int y) { return x * y; }
// The Google C++ style guide recommends using a comment to document what the unnamed parameter was:
void doSomething(int /*count*/) // warning: unreferenced parameter count
{
	// This function used to do something with count but it is not used any longer
}

int main() {
	doSomething(4);
	std::cout << add(5, 4) << '\n';
	std::cout << add(5 + 3, 2 * 9) << '\n';
	int x{5};
	std::cout << add(x, x) << '\n';
	std::cout << add(2, mutliply(2, 5)) << '\n';
	std::cout << add(56, add(2, 5)) << '\n';
}