#include <iostream>

// loop and while staments

// Iterate through every number between 1 and 50
int breakOrReturn();
int main() {
    int count{1};
    while (count <= 50) {
        // print the number (pad numbers under 10 with a leading 0 for formatting purposes)
        if (count < 10) {
            std::cout << '0';
        }

        std::cout << count << ' ';

        // if the loop variable is divisible by 10, print a newline
        if (count % 10 == 0) {
            std::cout << '\n';
        }

        // increment the loop counter
        ++count;
    }
    // Nested loops
    //  outer loops between 1 and 5
    int outer{1};
    while (outer <= 5) {
        // For each iteration of the outer loop, the code in the body of the loop executes once

        // inner loops between 1 and outer
        int inner{1};
        while (inner <= outer) {
            std::cout << inner << ' ';
            ++inner;
        }

        // print a newline at the end of each row
        std::cout << '\n';
        ++outer;
    }

    // Do while statements:A do while statement is a looping construct that works just like a while
    // loop, except the statement always executes at least once.
    // BestPractice:Favor while loops over do-while when given an equal choice.
    // selection must be declared outside of the do-while-loop, so we can use it later
    int selection{};

    do {
        std::cout << "Please make a selection: \n";
        std::cout << "1) Addition\n";
        std::cout << "2) Subtraction\n";
        std::cout << "3) Multiplication\n";
        std::cout << "4) Division\n";
        std::cin >> selection;
    } while (selection != 1 && selection != 2 && selection != 3 && selection != 4);

    // do something with selection here
    // such as a switch statement

    std::cout << "You selected option #" << selection << '\n';

    // For loop

    for (int i{0}; i < 10; ++i) // uses <, still terminates
    {
        std::cout << i;
        if (i == 9)
            ++i; // jump over value 10
    }

    for (int i{0}; i != 10; ++i) // uses !=, infinite loop
    {
        std::cout << i;
        if (i == 9)
            ++i; // jump over value 10
    }

    // For-loops with multiple counters
    for (int x{0}, y{9}; x < 10; ++x, --y)
        std::cout << x << ' ' << y << '\n';

    // BestPractice:
    // Prefer for loops over while loops when there is an obvious loop variable.
    // Prefer while loops over for loops when there is no obvious loop variable.

    // A break statement terminates the switch or loop, and execution continues at the first
    // statement beyond the switch or loop. A return statement terminates the entire function that
    // the loop is within, and execution continues at point where the function was called.
    int returnValue{breakOrReturn()};
    std::cout << "Function breakOrReturn returned " << returnValue << '\n';

    // The continue statement provides a convenient way to end the current iteration of a loop
    // without terminating the entire loop.
    for (int count{0}; count < 10; ++count) {
        // if the number is divisible by 4, skip this iteration
        if ((count % 4) == 0)
            continue; // go to next iteration

        // If the number is not divisible by 4, keep going
        std::cout << count << '\n';

        // The continue statement jumps to here
    }
    // Use break and continue when they simplify your loop logic.
    // Use early returns when they simplify your function’s logic.
    return 0;
}

int breakOrReturn() {
    while (true) // infinite loop
    {
        std::cout << "Enter 'b' to break or 'r' to return: ";
        char ch{};
        std::cin >> ch;

        if (ch == 'b')
            break; // execution will continue at the first statement beyond the loop

        if (ch == 'r')
            return 1; // return will cause the function to immediately return to the caller (in this
                      // case, main())
    }

    // breaking the loop causes execution to resume here

    std::cout << "We broke out of the loop\n";

    return 0;
}