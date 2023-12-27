# INSIGHT and NOTES

- A **statement** is a type of instruction that causes the program to perform some
  action. They are the smallest independent unit of computation in the C++ language.

- A **function** is a collection of statements that get executed sequentially (in
  order, from top to bottom).

- The name of a function (or object, type, template, etc…) is called its
  **identifier**.
- The rules that govern how sentences are constructed in a language are called
  **syntax**.

- The compiler is responsible for making sure your program follows the basic
  syntax of the C++ language.

- A **syntax error** is a compiler error that occurs at compile-time when your
  program violates the grammar rules of the C++ language.

- In computing, **data** is any information that can be moved, processed, or
  stored by a computer.
- **Programs** are collections of instructions that manipulate data to produce a
  desired result.
- A program can acquire data to work with in many ways: from a file or database,
  over a network, from the user providing input on a keyboard, or from the
  programmer putting data directly into the source code of the program itself.

- A single piece of data is called a **value**.

- The main memory in a computer is called **Random Access Memory (often called
  RAM for short)**. Common uses for this memory are to store values entered by
  the user, to store data read in from a file or network, or to store values
  calculated while the program is running (e.g. the sum of two values) so they
  can be used again later.

- An **object** is a region of storage (usually memory) that can store a value.
  An object with a name is called a **variable**.

- **Instantiation** is a fancy word that means the object will be created and
  assigned a memory address. An instantiated object is sometimes called an
  **instance**.
- The `=` operator is called the **assignment operator**.

- **Initialization** gives a variable an initial value at the point when it is
  created. **Assignment** gives a variable a value at some point after the
  variable is created.

- **Default initialization** is when a variable initialization has no initializer
  (e.g. `int x;`). In most cases, the variable is left with an indeterminate
  value.

- **Value initialization** is when a variable initialization has an empty brace
  (e.g. `int x{};`). In most cases, this will perform zero-initialization.

- The **insertion operator (`<<`)** can be used multiple times in a single
  statement to concatenate (link together) multiple pieces of output. Similarly,
  the extraction operator (`>>`) can be used multiple times to concatenate
  multiple pieces of input.
- `std::cout` is buffered. This also means that if your program crashes,
  aborts, or is paused (e.g. for debugging purposes) before the buffer is
  flushed, any output still waiting in the buffer will not be displayed.

- Writing data to a buffer is typically fast, whereas transferring a batch of
  data to an output device is comparatively slow. Buffering can significantly
  increase performance by minimizing the number of slow transfers that need to
  be performed when there are multiple output requests.

- **Initialized** = The object is given a known value at the point of definition.
  **Assignment** = The object is given a known value beyond the point of
  definition.
  **Uninitialized** = The object has not been given a known value yet.

- **Undefined behavior** is like a box of chocolates. You never know what you’re
  going to get!
- **Implementation-defined behavior** means the behavior of some syntax is left up
  to the implementation (the compiler) to define.

- Literals are values that are inserted directly into the source code.  
These values usually appear directly in the executable code (unless they are optimized out).

- Objects and variables represent memory locations that hold values.  
These values can be fetched on demand.

- an operation is a process involving zero or more input values (called operands)  
that produces a new value (called an output value). The specific operation to be performed is  
denoted by a symbol called an operator.
 number of operands that an operator takes as input is called the operator’s arity.

- -5 produces return value -5 and 2 + 3 produces return value 5
-  when x = 5 is evaluated, the assignment operator has the side effect of assigning the  
value 5 to variable x
- std::cout << 5 has the side effect of printing 5 to the console
- operator= and operator<< (when used to output values to the console) return their left operand.  
Thus, x = 5 returns x
- std::cout << 5 returns std::cout. This is done so that these operators can be chained.
- std::cout << "Hello " << "world" evaluates as (std::cout << "Hello ") << "world!".  
This first prints "Hello " to the console. This operation returns std::cout, which can then be  
used to print "world!" to the console as well.

- An expression is a combination of literals, variables, operators, and function calls that  
calculates a single value. The process of executing an expression is called evaluation, and the  
single value produced is called the result of the expression

- Function calls are part of an expression, so this is an expression statement.



---

# RULE

- Every C++ program must have a special function named **main** (all lowercase
  letters). When the program is run, the statements inside of main are executed
  in sequential order.

- Write comments for
  - At the library, program, or function level, use comments to describe what.
  - Inside the library, program, or function, use comments to describe how.
  - At the statement level, use comments to describe why.
  - NOT What

- In C++, the type of a variable must be known at compile-time. A type tells the
  program how to interpret a value in memory.

- Take care to avoid all situations that result in undefined behavior, such as
  using uninitialized variables. Avoid implementation-defined and unspecified
  behavior whenever possible, as they may cause your program to malfunction on
  other implementations.

- Avoid abbreviations (unless they are common/unambiguous).

- **Whitespace** is a term that refers to characters that are used for formatting
  purposes. In C++, this refers primarily to spaces, tabs, and newlines.

---

# BestPractice

- Although the language allows you to do so, avoid defining multiple variables
  of the same type in a single statement. Instead, define each variable in a
  separate statement on its own line (and then use a single-line comment to
  document what it is used for).

- **Initialize your variable upon creation**.

- Output a newline whenever a line of output is complete.

- Prefer ‘\n’ over `std::endl` when outputting text to the console, `endl`
  flushes the output buffer.
- When working in an existing program, use the conventions of that program (even
  if they don’t conform to
