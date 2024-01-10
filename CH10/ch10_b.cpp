// Typedefs and type aliases

// BestPractice:
// Use type aliases judiciously, when they provide a clear benefit to code readability
// or code maintenance.

// Name your type aliases starting with a capital letter and do not use a suffix (unless you have a
// specific reason to do otherwise).

// NOTE:
//  type alias identifiers follow the same scoping rules as variable identifiers

/*
If you need to use one or more type aliases across multiple files, they can be defined in a header
file

#ifndef MYTYPES_H
#define MYTYPES_H

    using Miles = long;
    using Speed = long;

#endif
//Type aliases #included this way will be imported into the global namespace and thus have global
scope.
*/
#include <iostream>
using VectPairSI =
    std::vector<std::pair<std::string, int>>; // make VectPairSI an alias for this crazy type

bool hasDuplicates(VectPairSI pairlist) // use VectPairSI in a function parameter
{
    // some code here
    return false;
}
int main() {
    using Distance = double; // define Distance as an alias for type double

    Distance milesToDestination{3.4}; // defines a variable of type double

    std::cout << milesToDestination << '\n'; // prints a double value

    // WARNING:
    // Be aware of doing things that are syntactically valid but semantically meaningless.
    using Miles = long; // define Miles as an alias for type long
    using Speed = long; // define Speed as an alias for type long
    Miles distance{5};  // distance is actually just a long
    Speed mhz{3200};    // mhz is actually just a long
    // The following is syntactically valid (but semantically meaningless)
    distance = mhz;

    // Typedefs are still in C++ for backwards compatibility reasons
    // The following aliases are identical
    typedef long Miles;
    using Miles = long;

    // When should we use type aliases?

    // Using type aliases for platform independent coding
    /*
    #ifdef INT_2_BYTES
    using int8_t = char;
    using int16_t = int;
    using int32_t = long;
    #else
    using int8_t = char;
    using int16_t = short;
    using int32_t = int;
    #endif
    */

    // Using type aliases to make complex types easier to read
    VectPairSI pairlist; // instantiate a VectPairSI variable

    // Using type aliases to document the meaning of a value
    using TestScore = int;
    // now yu can use functions gradeTest() like "TestScore gradeTest()"" instead of just
    // "int gradeTest()"

    // Using type aliases for easier code maintenance
    // Type aliases also allow you to change the underlying type of an object without having to
    // update lots of hardcoded types. like you short or int for some variable for now range
    // requirment has increased so you can easily just change staments of using alias instead of
    // changing hard coded short/ints everywhere
    // NOTE:caution is necessary whenever a type is changed, as the behavior of the program may also
    // change.
    return 0;
}