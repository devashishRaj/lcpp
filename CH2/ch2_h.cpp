// Conditional compilation
// Macros only cause text substitution for non-preprocessor commands.
// Directives are resolved before compilation, from top to bottom on a file-by-file basis.
// final output of the preprocessor contains no directives at all -- they are all resolved/stripped
// out before compilation, because the compiler wouldn’t know what to do with them.
// the scope is only in the file that they are declared. Preporcessor does not understand {} etc.

#include <iostream>

#define PRINT_JOE

int main() {
#ifdef PRINT_JOE
	std::cout << "PRINT JOE" << '\n'; // will be compiled since PRINT_JOE is defined
#endif
#ifdef PRINT_BOB
	std::cout << "PRINT BOB" << '\n'; // will be excluded since PRINT_BOB is not defined
#endif

// #ifndef is the opposite of #ifdef,
#ifndef PRINT_ROB
	std::cout << "PRINT ROB" << '\n';
#endif
// This provides a convenient way to “comment out” code that contains multi-line comments (which
// can’t be commented out using another multi-line comment due to multi-line comments being
// non-nestable):
#if 0  // Don't compile anything starting here
    std::cout << "Bob\n";
    /* Some
     * multi-line
     * comment here
     */
    std::cout << "Steve\n";
#endif // until this point

#if 1 // always true, so the following code will be compiled
	std::cout << "Bob\n";
	/* Some
	 * multi-line
	 * comment here
	 */
	std::cout << "Steve\n";
#endif
}