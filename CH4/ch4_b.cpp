// floating point numbers:
// The precision of a floating point type defines how many significant digits it can represent
// without information loss.
// a float has 6 to 9 digits of precision.
// Double values have between 15 and 18 digits of precision
//  Long double has a minimum precision of 15, 18, or 33 significant digits depending on how many
//  bytes it occupies.

#include <iomanip> // for std::setprecision()
#include <iostream>

int main() {
	// NOTE:std::cout has a default precision of 6
	std::cout << 9.87654321f << '\n';
	std::cout << 987.654321f << '\n';
	std::cout << 987654.321f << '\n';
	std::cout << 9876543.21f << '\n';
	std::cout << 0.0000987654321f << '\n';

	// NOTE:Output manipulators (and input manipulators) are sticky -- meaning if you set them, they
	// will remain set.

	std::cout << std::setprecision(17);								// show 17 digits of precision
	std::cout << 3.33333333333333333333333333333333333333f << '\n'; // f suffix means float
	std::cout << 3.33333333333333333333333333333333333333 << '\n';	// no suffix means double

	float f{123456789.0f};			   // f has 10 significant digits
	std::cout << std::setprecision(9); // to show 9 digits in f
	std::cout << f << '\n';

	// Rounding errors make floating point comparisons tricky
	// because the double had to truncate the approximation due to its limited memory. The result is
	// a number that is precise to 16 significant digits (which type double guarantees), but the
	// number is not exactly 0.1. Rounding errors may make a number either slightly smaller or
	// slightly larger, depending on where the truncation happens.
	double d{0.1};
	std::cout << d << '\n'; // use default cout precision of 6
	std::cout << std::setprecision(17);
	std::cout << d << '\n';

	std::cout << std::setprecision(17);
	double d1{1.0};
	std::cout << d1 << '\n';
	double d2{0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1}; // should equal 1.0
	std::cout << d2 << '\n';
	// note:on rounding errors: mathematical operations (such as addition and multiplication) tend
	// to make rounding errors grow.

	double zero{0.0};
	double posinf{5.0 / zero}; // positive infinity "inf"
	std::cout << posinf << '\n';
	double neginf{-5.0 / zero}; // negative infinity "-inf"
	std::cout << neginf << '\n';
	double nan{zero / zero}; // not a number (mathematically invalid) "NaN"
	std::cout << nan << '\n';
}
