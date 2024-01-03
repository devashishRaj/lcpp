// Remainder and Exponentiation
// NOTE:The remainder operator only works with integer operands.
// The remainder operator can also work with negative operands
// x % y always returns results with the sign of x.
// The remainder operator (also commonly called the modulo operator or modulus operator) is an
// operator that returns the remainder after doing an integer division. For example, 7 / 4 = 1
// remainder 3. Therefore, 7 % 4 = 3. As another example, 25 / 7 = 3 remainder 4, thus 25 % 7 = 4.

// BestPractice:Prefer to compare the result of the remainder operator (operator%) against 0 if
// possible.

// NOTE:exponent operator  , C++ does not include an exponent operator.

#include <cmath>
// Due to rounding errors in floating point numbers, the results of pow() may not be precise (even
// if you pass it integers or whole numbers).
double x{std::pow(3.0, 4.0)}; // 3 to the 4th power

// integer exponentiation
// Warning:In the vast majority of cases, integer exponentiation will overflow the integral type.
// This is likely why such a function wasn’t included in the standard library in the first place.

#include <cassert> // for assert
#include <cstdint> // for std::int64_t
#include <iostream>
#include <limits> // for std::numeric_limits

// A safer (but slower) version of powint() that checks for overflow
// note: exp must be non-negative
// Returns std::numeric_limits<std::int64_t>::max() if overflow occurs

// safer version of the exponentiation function that checks for overflow
constexpr std::int64_t powInt__safe(std::int64_t base, std::int64_t exp) {
	assert(exp >= 0 && "powInt_safe : exp has negative value ");

	// Handle 0 case
	if (base == 0) {
		return (exp == 0) ? 1 : 0;
	}

	std::int64_t result{1};
	// to make range checks easier we will ensure base is postie and negate the result if
	// needed in case of ODD exponent .
	bool negativeResult{false};
	if (base < 0) {
		base = -base;
		negativeResult = exp & 1;
	}
	// applying Binary Exponentiation
	// https://en.wikipedia.org/wiki/Exponentiation_by_squaring
	while (exp > 0) {
		// if exp is odd
		if (exp & 1) {
			// check if result will overflow if mutliplied by base
			if (result > std::numeric_limits<std::int64_t>::max() / base) {
				std::cerr << "powerInt_safe: result overflowed\n";
				return std::numeric_limits<std::int64_t>::max();
			}
			result *= base;
		}
		exp /= 2;

		// if we are done get out of here
		if (exp <= 0)
			break;
		// The following only needs to execute if we're going to iterate again
		// Check if base will overflow when multiplied by base
		if (base > std::numeric_limits<std::int64_t>::max() / base) {
			std::cerr << "powint_safe(): base overflowed\n";
			return std::numeric_limits<std::int64_t>::max();
		}

		base *= base;
	}
	if (negativeResult)
		return -result;

	return result;
}

int main() {
	std::cout << powInt__safe(7, 12) << '\n'; // 7 to the 12th power
	std::cout << powInt__safe(70, 12)
			  << '\n'; // 70 to the 12th power (will return the max 64-bit int value)

	return 0;
}