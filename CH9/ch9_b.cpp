//NOTE:If the macro NDEBUG is defined, the assert macro gets disabled.
// #define NDEBUG 
#include <cassert> // for assert()
#include <cmath>   // for std::sqrt
#include <iostream>

double calculateTimeUntilObjectHitsGround(double initialHeight, double gravity) {
    // A string literall always evaluate to true.Thus, logical AND-ing a string literal doesn’t
    // impact the evaluation of the assert.
    assert(gravity > 0.0 && "The object won't reach the ground unless there is positive gravity.");

    if (initialHeight <= 0.0) {
        // The object is already on the ground. Or buried.
        return 0.0;
    }

    return std::sqrt((2.0 * initialHeight) / gravity);
}

int main() {
    // An assertion is an expression that will be true unless there is a bug in the program.
    // The goal of an assertion is to catch programming errors by documenting something that should
    // never happen.
    std::cout << "Took " << calculateTimeUntilObjectHitsGround(100.0, -9.8) << " second(s)\n";

    return 0;
}