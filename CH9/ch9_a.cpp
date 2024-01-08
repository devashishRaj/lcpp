#include <iostream>
#include <limits>

// NOTE:
// \error handling is designed to gracefully handle cases that could happen (however rarely) in release configurations. 
//while we are writing and debugging programs, silent(?) failures are bad, because they
// obscure real problems.

// Software testing (also called software validation) is the process of determining whether or not
// the software actually works as expected.

// Test your programs in small pieces
// tests as you develop porgram piece by piece and when each piece gets integrated

// The term code coverage is used to describe how much of the source code of a program is executed
// while testing.

// The term statement coverage refers to the percentage of statements in your code that have been
// exercised by your testing routines. While aiming for 100% statement coverage is good, it’s often
// not enough to ensure correctness.

// BestPractice:
//  Aim for 100% branch coverage of your code.
//  Use the 0, 1, 2 test to ensure your loops work correctly with different number of iterations.
//  Test different categories of input values to make sure your unit handles them properly :
/*
For integers, make sure you’ve considered how your function handles negative values, zero, and
positive values. You should also check for overflow if that’s relevant.

For floating point numbers, make sure you’ve considered how your function handles values that have
precision issues (values that are slightly larger or smaller than expected). Good double type values
to test with are 0.1 and -0.1 (to test numbers that are slightly larger than expected) and 0.6 and
-0.6 (to test numbers that are slightly smaller than expected).

For strings, make sure you’ve considered how your function handles an empty string, an alphanumeric
string, strings that have whitespace (leading, trailing, and inner), and strings that are all
whitespace.
*/
void ignoreLine();
double getDouble();
char getOpeartor();
void printResult(double x, char operation, double y);
int main() {
    double x{getDouble()};
    char operaton{getOpeartor()};
    double y{getDouble()};
    printResult(x, operaton, y);
}

void ignoreLine() {

    // clear any extraneous input : To ignore everything up to and including the next ‘\n’ character
    // std::numeric_limits<std::streamsize>::max() returns the largest value that can be stored in a
    // variable of type std::streamsize. Passing this value to std::cin.ignore() causes it to
    // disable the count check.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

double getDouble() {
    // Loop until user enters a valid input
    while (true) {
        std::cout << "Enter a decimal number : ";
        double x;
        std::cin >> x;
        // The process of checking whether user input conforms to what the program is expecting is
        // called input validation.
        //  check for failed extraction
        //  if the PREVIOUS extraction failed
        if (!std::cin) {
            // if the stream was closed
            if (std::cin.eof()) {
                // On Unix systems, entering an end-of-file (EOF) character (via ctrl-D) closes the
                // input stream. This is something that std::cin.clear() can’t fix, so std::cin
                // never leaves failure mode, which causes all subsequent input operations to fail.
                // When this happens inside an infinite loop, your program will then loop endlessly
                // until killed. so  shut down the program .
                exit(0);
            }
            // let's handle the failure
            // put the program back in normal mode
            std::cin.clear();
            // then remove the bad input via clearing the whole buffer .
            ignoreLine();
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        } else {
            // remove any extraneous input for next cin .
            ignoreLine();
            return x;
        }
    }
}

char getOpeartor() {
    while (true) {
        std::cout << "Enter one of the following + , - , * or / : ";
        char operation;
        std::cin >> operation;
        if (!std::cin) // if the previous extraction failed
        {
            if (std::cin.eof()) // if the stream was closed
            {
                exit(0); // shut down the program now
            }

            // let's handle the failure
            std::cin.clear(); // put us back in 'normal' operation mode
        }

        ignoreLine(); // remove any extraneous input
        // Check whether the user entered meaningful input switch (operation) {
        switch (operation) {
        case '+':
        case '-':
        case '*':
        case '/':
            return operation; // return it to the caller
        default:              // otherwise tell the user what went wrong
            std::cout << "Oops, that input is invalid.  Please try again.\n";
        }
        // and try again
    }
}

void printResult(double x, char operation, double y) {
    switch (operation) {
    case '+':
        std::cout << x << " + " << y << " is " << x + y << '\n';
        break;
    case '-':
        std::cout << x << " - " << y << " is " << x - y << '\n';
        break;
    case '*':
        std::cout << x << " * " << y << " is " << x * y << '\n';
        break;
    case '/':
        std::cout << x << " / " << y << " is " << x / y << '\n';
        break;
    default: // Being robust means handling unexpected parameters as well, even though getOperator()
             // guarantees operation is valid in this particular program
        std::cout << "Something went wrong: printResult() got an invalid operator.\n";
    }
}

// NOTE:
// semantic errors, which occur when you write code that does not do what you intended
// If the error is so bad that the program can not continue to operate properly, this is called a
// non-recoverable error (also called a fatal error).
// remember that std::cin stops extracting at the first non-leading whitespace character).

// An invariant is a condition that must be true while some section of code is executing. This is
// often used with loops, where the loop body will only execute so long as the invariant is true.

/*
    Use std::cout for all conventional, user-facing text.

    For an interactive program, use std::cout for normal user-facing error messages (e.g. “Your
   input was invalid”). Use std::cerr or a logfile for status and diagnostic information that may be
   helpful for diagnosing issues but probably isn’t interesting for normal users. This can include
   technical warnings and errors (e.g. bad input to function x), status updates (e.g. successfully
   opened file x, failed to connect to internet service x), percentage completion of long tasks
   (e.g. encoding 50% complete), etc ...

   For a non-interactive program (tool or service), use std::cerr
   for error output only (e.g. could not open file x). This allows errors to be displayed or parsed
   separately from normal output.

   For any application type that is transactional in nature (e.g. one
   that processes specific events, such as an interactive web browser or non-interactive web
   server), use a logfile to produce a transactional log of events that can be reviewed later.
*/