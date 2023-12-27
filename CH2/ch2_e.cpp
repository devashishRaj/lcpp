// Scope and lifetime
// lifetime is a runtime property, and scope is a compile-time property,
// BESTPRACTICE:Define your local variables as close to their first use as reasonable.
// In C++, any name that is not defined inside a class, function, or a namespace is considered to be
// part of an implicitly defined namespace called the global namespace (sometimes also called the
// global scope).

#include <iostream>

int add(int x, int y) // add's x and y are created and enter scope here
{
	// add's x and y are visible/usable within this function only
	return x + y;
} // add's y and x go out of scope and are destroyed , here in order opposite to creation
  //

// x is not in scope anywhere in this function
void doSomething() { std::cout << "Hello!\n"; }
int main() {
	// x is not defined here

	int x{4}; // x comes in main's scope here and can be user from now till curly close bracket
	int y{6}; // main's y is created, initialized, and enters scope here

	// main's x and y are usable within this function only
	std::cout << add(x, y) << '\n'; // calls function add() with x=5 and y=6
	doSomething();

	return 0;
} // main's y and x go out of scope and are destroyed here
  // NOTE::
  /*
   neither add nor main know that the other function has variables with the same names. Because the
   scopes don’t overlap, it’s always clear to the compiler which x and y are being referred to at any
   time. neither add nor main know that the other function has variables with the same names. Because
   the scopes don’t overlap, it’s always clear to the compiler which x and y are being referred to at
   any time.
  */

/*
**Why Use Functions:**

1. **Organization:** Functions help organize code, reducing complexity by breaking a program into
manageable chunks.

2. **Reusability:** Functions can be reused, avoiding duplicated code and minimizing errors,
promoting the "Don't Repeat Yourself" principle.

3. **Testing:** Functions reduce code redundancy, making testing more efficient, and once tested,
changes only require testing in the modified function.

4. **Extensibility:** Functions allow easy program extension by making changes in one place,
affecting every instance the function is called.

5. **Abstraction:** Using a function only requires knowledge of its name, inputs, outputs, and
location, reducing the need to understand its internal workings.

**Effectively Using Functions:**

1. **Repetition:** Group statements appearing more than once into functions, especially for
repetitive tasks like user input or output.

2. **Well-Defined Inputs and Outputs:** Code with clear inputs and outputs is ideal for functions,
even if only used once, facilitating future reuse.

3. **Single Task:** Functions should generally perform one specific task to adhere to the "one task"
rule, promoting clarity and maintainability.

4. **Refactoring:** If a function becomes too complex, refactor it by splitting into sub-functions
to maintain clarity and ease of understanding.

**Common Subtasks in C++ Programs:**

1. **Reading Inputs:** For longer programs, consider creating a separate function for reading user
inputs.

2. **Calculating Values:** Create individual functions for calculating values to follow the "one
task" rule.

3. **Printing Values:** Separate the task of printing calculated values into its own function,
adhering to the principles of good function design.

*/