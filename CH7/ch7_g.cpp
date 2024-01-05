#include <iostream>

// static duration, which means they are created when the program starts and destroyed when the
// program ends.

// static keyword gives a global identifier internal linkage, which means the identifier can only be
// used in the file in which it is defined

// static keyword when applied to a local variable:
void incrementAndPrint() {
    static int s_value{1};
    // static duration via static keyword.  This initializer is only executed once.
    // NOTE:Static local variables with a non-constexpr initializer are reinitialized the first time
    // the variable definition is encountered.
    ++s_value;
    std::cout << s_value << '\n';
}
// s_value is not destroyed here, but becomes inaccessible because it goes out of scope
// it’s common to use “s_” to prefix static (static duration) local variables.
// One of the most common uses for static duration local variables is for unique ID generators
int main() {
    incrementAndPrint();
    incrementAndPrint();
    incrementAndPrint();

    return 0;
}

// BestPractice:Initialize your static local variables. Static local variables are only initialized
// the first time the code is executed, not on subsequent calls.

//Avoid static local variables unless the variable never needs to be reset.