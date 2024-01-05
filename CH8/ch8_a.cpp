// When a control flow statement causes point of execution to change to a non-sequential statement,
// this is called branching.

// A conditional statement is a statement that specifies whether some associated statement(s) should
// be executed or not.

// BestPractice:Consider putting single statements associated with an if or else in blocks
// (particularly while you are learning). More experienced C++ developers sometimes disregard this
// practice in favor of tighter vertical spacing.

// A middle-ground alternative is to put single-lines on the same line as the if or else:
// if (age >= minDrinkingAge) purchaseBeer();

// Implicit blocks : If the programmer does not declare a block in the statement portion of an if
// statement or else statement, the compiler will implicitly declare one.

/*
if (condition)
    true_statement;
else
    false_statement;

is actually the equivalent of:

if (condition)
{
    true_statement;
}
else
{
    false_statement;
}

*/

#include <iostream>

int main() {
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    std::cout << "Enter another integer: ";
    int y{};
    std::cin >> y;
    //// Nested if statements and the dangling else problem: use blocks so it's clear which else
    /// statement is attached to which if statment
    if (x >= 0) {
        if (x <= 20)
            std::cout << x << " is between 0 and 20\n";
        else // attached to inner if statement
            std::cout << x << " is greater than 20\n";
    } else // attached to outer if statement
        std::cout << x << " is negative\n";

    // Flattening nested if statements
    if (x < 0)
        std::cout << x << " is negative\n";
    else if (x <= 20) // only executes if x >= 0
        std::cout << x << " is between 0 and 20\n";
    else // only executes if x > 20
        std::cout << x << " is greater than 20\n";
    // uses logical operators to check multiple conditions within a single if statement:
    if (x > 0 && y > 0) // && is logical and -- checks if both conditions are true
        std::cout << "Both numbers are positive\n";
    else if (x > 0 || y > 0) // || is logical or -- checks if either condition is true
        std::cout << "One of the numbers is positive\n";
    else
        std::cout << "Neither number is positive\n";

    // C++17 introduces the constexpr if statement
    constexpr double gravity{9.8};
    if constexpr (gravity == 9.8) // now using constexpr if
        std::cout << "Gravity is normal.\n";
    else
        std::cout << "We are not on Earth.\n";
    // during compilaton the compiler will replace the whole section with just :
    // std::cout << "Gravity is normal.\n";
    return 0;
}
