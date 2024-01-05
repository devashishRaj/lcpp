#include <iostream>
// BestPractice:
// Prefer switch statements over if-else chains when there is a choice.

// Each set of statements underneath a label should end in a break statement or a return statement.
// This includes the statements underneath the last label in the switch.
// Place the default case last in the switch block.

// NOTE:The one restriction is that the condition must evaluate to an integral type or be
// convertible to one.
void printDigitName(int x) {
    switch (x) // x evaluates to 3
    {
    case 1:
        std::cout << "One";
        break;
    case 2:
        std::cout << "Two";
        break;
    case 3:
        std::cout << "Three"; // execution starts here
        break;                // jump to the end of the switch block
    default:
        std::cout << "Unknown";
        break;
    }

    // execution continues here
    std::cout << " Ah-Ah-Ah!";
}

int main() {
    printDigitName(3);
    std::cout << '\n';
    // Fallthrough
    switch (2) {
    case 1:                     // Does not match
        std::cout << 1 << '\n'; // Skipped
    case 2:                     // Match!
        std::cout << 2 << '\n'; // Execution begins here
    case 3:
        std::cout << 3 << '\n'; // This is also executed
    case 4:
        std::cout << 4 << '\n'; // This is also executed
    default:
        std::cout << 5 << '\n'; // This is also executed
    }
    // C++17 adds attribute [[fallthrough]]. to tell other developers that fallthrough is intended
    switch (2) {
    case 1:
        std::cout << 1 << '\n';
        break;
    case 2:
        std::cout << 2 << '\n'; // Execution begins here
        [[fallthrough]]; // intentional fallthrough -- note:the semicolon to indicate the null
                         // statement
    case 3:
        std::cout << 3 << '\n'; // This is also executed
        break;
    }
    // In Switch statements, the statements after labels are all scoped to the switch block. No
    // implicit blocks are created.
    switch (1) {
    case 1: // does not create an implicit block
        // foo(); // this is part of the switch scope, not an implicit block to case 1
        break; // this is part of the switch scope, not an implicit block to case 1
    default:
        std::cout << "default case\n";
        break;
    }
    // NO implicit blocks
    switch (1) {
        int a; // okay: definition is allowed before the case labels
        // int b{5}; // illegal: initialization is not allowed before the case labels

    case 1:
        int y; // okay but bad practice: definition is allowed within a case
        y = 4; // okay: assignment is allowed
        break;

    case 2:
        // int z{4}; // illegal: initialization is not allowed if subsequent cases exist
        y = 5; // okay: y was declared above, so we can use it here too
        break;

    case 3:
        break;
    }

    // BestPractice:If defining variables used in a case statement, do so in a block inside the
    // case.
    switch (1) {
    case 1: {     // note addition of explicit block here
        int x{4}; // okay, variables can be initialized inside a block inside a case
        std::cout << x;
        break;
    }
    default:
        std::cout << "default case\n";
        break;
    }

    // Avoid using goto:Use of goto is shunned in C++
    /*
    The primary problem with goto is that it allows a programmer to jump around the code
    arbitrarily. This creates what is not-so-affectionately known as spaghetti code. Spaghetti code
    is code that has a path of execution that resembles a bowl of spaghetti (all tangled and
    twisted), making it extremely difficult to follow the logic of such code.
    */

    return 0;
}