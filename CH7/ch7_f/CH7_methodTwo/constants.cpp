#include "constants.h"
// We use const instead of constexpr in this method because constexpr variables can’t be forward
// declared, even if they have external linkage. This is because the compiler needs to know the
// value of the variable at compile time, and a forward declaration does not provide this
// information.
namespace constants {
    // actual global variables
    extern const double pi{3.14159};
    extern const double avogadro{6.0221413e23};
    extern const double myGravity{9.2}; // m/s^2 -- gravity is light on this planet
} // namespace constants

// Any changes made to constants.cpp will require recompiling only constants.cpp.

// outside of constants.cpp, these variables can’t be used anywhere that requires a compile-time
// constant

// compile-time constants can typically be optimized more than runtime constants, the compiler may
// not be able to optimize these as much.