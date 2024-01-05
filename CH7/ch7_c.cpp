#include <iostream>
// By convention, global variables are declared at the top of a file, below the includes

// Identifiers declared in the global namespace have global namespace scope (commonly called global
// scope, and sometimes informally called file scope), which means they are visible from the point
// of declaration until the end of the file in which they are declared.

// Global variables are created when the program starts, and destroyed when it ends. This is called
// static duration. Variables with static duration are sometimes called static variables.

// NOTE:variables with static duration are zero-initialized by default.

//   Non-constant global variables
int g_x;     // defines non-initialized global variable (zero initialized by default)
int g_x2{};  // defines explicitly value-initialized global variable
int g_x3{1}; // defines explicitly initialized global variable

// Const global variables
// const int g_y;           // error:const variables must be initialized
const int g_y{2}; // defines initialized global const

// Constexpr global variables
// constexpr int g_y2;       // error:constexpr variables must be initialized
constexpr int g_y2{3}; // defines initialized global constexpr

namespace Foo // Foo is defined in the global scope
{
    int g_x{}; // g_x is now inside the Foo namespace, but is still a global variable
}

void doSomething() {
    // global variables can be seen and used everywhere in the file
    Foo::g_x = 3;
    std::cout << Foo::g_x << '\n';
}
int main() { // outer block

    // BestPractice:Define variables in the most limited existing scope. Avoid creating new blocks
    // whose only purpose is to limit the scope of variables.

    //  Local variables have block scope
    //  All variable names within a scope must be unique

    // Local variables have automatic storage duration: storage duration determines what rules
    // govern when and how a variable will be created and destroyed. In most cases, a variable’s
    // storage duration directly determines its lifetime.local variables have automatic storage
    // duration, which means they are created at the point of definition and destroyed at the end of
    // the block they are defined in

    // Local variables have no linkage: which means that each declaration refers to a unique object.

    int x{5}; // x enters scope and is created here

    {             // nested block
        int y{7}; // y enters scope and is created here

        // x and y are both in scope here
        std::cout << x << " + " << y << " = " << x + y << '\n';
    } // y goes out of scope and is destroyed here

    // y can not be used here because it is out of scope in this block

    // Although the identifier g_x is now limited to the scope of namespace Foo, that name is still
    // globally accessible (via Foo::g_x), and g_x is still a global variable.
    doSomething();
    std::cout << Foo::g_x << '\n';

    // global variables can be seen and used everywhere in the file
    Foo::g_x = 5;
    std::cout << Foo::g_x << '\n';
    return 0;
} // x goes out of scope and is destroyed here

// BestPractice:

// Consider using a “g” or “g_” prefix when naming non-const global variables, to help
//  differentiate them from local variables and function parameters.

// New programmers are often tempted to use lots of global variables, because they can be used
// without having to explicitly pass them to every function that needs them. However, use of
// non-constant global variables should generally be avoided altogether!