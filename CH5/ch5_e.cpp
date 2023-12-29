// Inline functions and variables
// Inline expansion is a process where a function call is replaced by the code from the called
// function’s definition, inline expansion can also allow the compiler to optimize the resulting
// code more efficiently

// one downside of using a function is that every time a function is called, there is a certain
// amount of performance overhead that occurs:
/*
the CPU must store the address of the current instruction it is executing (so it knows where to
return to later) along with the values of various CPU registers (so they can be restored upon
returning). Then parameters of called function must be instantiated and then initialized.
Then the execution path has to jump to the code in the called function.
When the function ends, the program has to jump back to the location of the function call, and the
return value has to be copied so it can be output. This has to be done for each function call.
*/

// the overhead costs can be larger than the time needed to actually execute the function’s code!

// Modern optimizing compilers make the decision about when functions should be expanded inline.

#include <iostream>

// in modern C++, the inline keyword is no longer used to request that a function be expanded inline

// Using inline to request inline expansion is a form of premature optimization, and misuse could
// actually harm performance.

// The inline keyword is just a hint -- the compiler is completely free to ignore a request to
// inline a function

// inline expansion is actually determined per function call.
inline int min(int x, int y) // inline keyword means this function is an inline function
{
	return (x < y) ? x : y;
}

// NOTE:In modern C++, the term inline has evolved to mean “multiple definitions are allowed”.
// Header-only libraries are popular because there are no source files that need to be added to a
// project to use them and nothing that needs to be linked.
#include "pi.h" // will include a copy of pi() here

double circumference(double radius); // forward declaration

int main() {
	std::cout << min(5, 6) << '\n';
	std::cout << min(3, 2) << '\n';

	std::cout << pi() << '\n';
	std::cout << circumference(2.0) << '\n';
	return 0;
}