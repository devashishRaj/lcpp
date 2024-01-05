#include <iostream>
//NOTE:if using [-Werror,-Wshadow] , program will not compile this flags.

//BestPractice:Avoid variable shadowing.

int value{5}; // global variable

int main() {
    int value{7}; // hides the global variable value
    ++value;      // increments local value, not global value

    --(::value); // decrements global value, not local value (parenthesis added for readability)

    std::cout << "local variable value: " << value << '\n';
    std::cout << "global variable value: " << ::value << '\n';

    // outer block
    int apples{5}; // here's the outer block apples

    { // nested block
        // apples refers to outer block apples here
        std::cout << apples << '\n'; // print value of outer block apples

        int apples{0}; // define apples in the scope of the nested block

        // apples now refers to the nested block apples
        // the outer block apples is temporarily hidden

        apples = 10; // this assigns value 10 to nested block apples, not outer block apples

        std::cout << apples << '\n'; // print value of nested block apples
    }                                // nested block apples destroyed

    std::cout << apples << '\n'; // prints value of outer block apples
    return 0;
} // local value is destroyed