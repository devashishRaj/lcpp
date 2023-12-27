// funciton header

#include <iostream>
// funciton prototype
//// Do not forget the semicolon on the end, since these are statements.
int add(int x, int y);
// A forward declaration allows us to tell the compiler about the existence
// of an identifier before actually defining the identifier.

int main() { add(3, 5); }

int add(int x, int y) { return x + y; } // implement the funciton here .

/*
The one definition rule (ODR)

The one definition rule (or ODR for short) is a well-known rule in C++. The ODR has three parts:

- Within a file, each function, variable, type, or template can only have one definition.
Definitions occurring in different scopes (e.g. local variables defined inside different functions,
or functions defined inside different namespaces) do not violate this rule.

-Within a program, each function or variable can only have one definition. This rule exists because
programs can have more than one file (we’ll cover this in the next lesson). Functions and variables
not visible to the linker are excluded from this rule (discussed further in lesson 7.6 -- Internal
linkage).

- Types, templates, inline functions, and inline variables are allowed to have duplicate
definitions in different files, so long as each definition is identical. We haven’t covered what
most of these things are yet, so don’t worry about this for now -- we’ll bring it back up when it’s
relevant.

-Violating part 1 of the ODR will cause the compiler to issue a redefinition error.
-Violating ODR part 2 will cause the linker to issue a redefinition error.
-Violating ODR part 3 will cause undefined behavior.The one definition rule (ODR).

*/