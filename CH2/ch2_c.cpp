#include <iostream>

void returnNothing() {
	// trying to return a  value from void function will give error.
	// return 5;
	// you can use just return; at point in void function , to use it like break in for loop
	return;
}

int returnFive() { return 5; }

int main() {
	returnFive();
	returnNothing();
	std::cout << returnFive() << '\n';
	// this will lead to compiler error as std::cout cannout send void to console .
	// std::cout << returnNothing() << '\n' ;
}