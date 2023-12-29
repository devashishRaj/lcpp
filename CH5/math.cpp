#include "pi.h" // will include a copy of pi() here
// the linker will de-duplicate them
// f you remove the inline keyword from both definitions of pi(), you’ll get an ODR violation (as
// duplicate definitions for non-inline functions are disallowed).
double circumference(double radius) {
	return 2.0 * pi() * radius;
}

//NOTE:Static constexpr variables are implicitly inline