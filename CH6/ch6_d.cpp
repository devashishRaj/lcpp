#include <algorithm> // for std::max
#include <iostream>

//Ignore this now , this is second part of this file .
// Our own constexpr implementation of std::abs (for use prior to C++23)
// In C++23, use std::abs
// constAbs() can be called like a normal function, but can handle different types of values (e.g. int, double, etc...)
template <typename T>
constexpr T constAbs(T x)
{
    return (x < 0 ? -x : x);
}

// Return true if the difference between a and b is within epsilon percent of the larger of a and b
constexpr bool approximatelyEqualRel(double a, double b, double relEpsilon)
{
    return (constAbs(a - b) <= (std::max(constAbs(a), constAbs(b)) * relEpsilon));
}

// Return true if the difference between a and b is less than or equal to absEpsilon, or within relEpsilon percent of the larger of a and b
constexpr bool approximatelyEqualAbsRel(double a, double b, double absEpsilon, double relEpsilon)
{
    // Check if the numbers are really close -- needed when comparing numbers near zero.
    if (constAbs(a - b) <= absEpsilon)
        return true;

    // Otherwise fall back to Knuth's algorithm
    return approximatelyEqualRel(a, b, relEpsilon);
}

int main() {
	std::cout << "Enter an integer: ";
	int x{};
	std::cin >> x;

	std::cout << "Enter another integer: ";
	int y{};
	std::cin >> y;

	if (x == y)
		std::cout << x << " equals " << y << '\n';
	if (x != y)
		std::cout << x << " does not equal " << y << '\n';
	if (x > y)
		std::cout << x << " is greater than " << y << '\n';
	if (x < y)
		std::cout << x << " is less than " << y << '\n';
	if (x >= y)
		std::cout << x << " is greater than or equal to " << y << '\n';
	if (x <= y)
		std::cout << x << " is less than or equal to " << y << '\n';
	// if (b1 == true) ... instead prefer if (b1) ...
	// if (b1 == false) ...instead prefer if(!b1) ...

	// Warning:Comparison of calculated floating point values can be problematic
	//   inspect the value of d1 and d2 in a debugger, you’d likely see that d1 =
	//   0.010000000000005116 and d2 = 0.0099999999999997868.
	double d1{100.0 - 99.99}; // should equal 0.01 mathematically
	double d2{10.0 - 9.99};	  // should equal 0.01 mathematically

	if (d1 == d2)
		std::cout << "d1 == d2" << '\n';
	else if (d1 > d2)
		std::cout << "d1 > d2" << '\n';
	else if (d1 < d2)
		std::cout << "d1 < d2" << '\n';
	return 0;

	// The value used to represent “close enough” is traditionally called epsilon.
	// Donald Knuth: Seminumerical Algorithms (Addison-Wesley, 1969)”:
	// a is really close to 1.0, but has rounding errors
    constexpr double a{ 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 };

    constexpr double relEps { 1e-8 };
    constexpr double absEps { 1e-12 };

    constexpr bool same { approximatelyEqualAbsRel(a, 1.0, absEps, relEps) };
    std::cout << same << '\n';

}

// BestPractice:Don’t add unnecessary == or != to conditions. It makes them harder to read without
// offering any additional value.

// instead of epsilon being an absolute number, epsilon is now relative to the magnitude of a or b.
//  Return true if the difference between a and b is within epsilon percent of the larger of a and b
// NOTE:it is not perfect, especially as the numbers approach zero
// The value used to represent “close enough” is traditionally called epsilon.
// Donald Knuth: Seminumerical Algorithms (Addison-Wesley, 1969)”:

/*
On the right side of the <= operator, we need to calculate the largest value of “close enough”
we’re willing to accept. To do this, the algorithm chooses the larger of a and b (as a rough
indicator of the overall magnitude of the numbers), and then multiplies it by relEpsilon. In
this function, relEpsilon represents a percentage. For example, if we want to say “close enough”
means a and b are within 1% of the larger of a and b, we pass in an relEpsilon of 0.01 (1% =
1/100 = 0.01). The value for relEpsilon can be adjusted to whatever is most appropriate for the
circumstances (e.g. an epsilon of 0.002 means within 0.2%).
*/


