// data types and thier size
// On modern machines, objects of the fundamental data types are fast, so
// performance while using or copying these types should generally not be a
// concern.
#include <cstdint> // for fast and least types
#include <iomanip> // for std::setw (which sets the width of the subsequent output)
#include <iostream>

int main () {
	// A byte is 8 bits.
	// Memory is byte addressable, so the smallest object is 1 byte.
	std::cout << std::left; // left justify output
	std::cout << std::setw (16) << "bool:" << sizeof (bool) << " bytes\n";
	std::cout << std::setw (16) << "char:" << sizeof (char) << " bytes\n";
	std::cout << std::setw (16) << "short:" << sizeof (short) << " bytes\n";
	std::cout << std::setw (16) << "int:" << sizeof (int) << " bytes\n";
	std::cout << std::setw (16) << "long:" << sizeof (long) << " bytes\n";
	std::cout << std::setw (16) << "long long:" << sizeof (long long) << " bytes\n";
	// Floating point support is IEEE-754 compliant.
	std::cout << std::setw (16) << "float:" << sizeof (float) << " bytes\n";
	std::cout << std::setw (16) << "double:" << sizeof (double) << " bytes\n";
	std::cout << std::setw (16) << "long double:" << sizeof (long double) << " bytes\n";
	// four type of integers , they are all signed . You can type signed long int
	// ; but prefix signed and suffix int are reduntant here . an n-bit signed
	// variable has a range of -(2^(n-1)) to 2^(n-1))-1.
	short s;
	int ss;
	long sss;
	long long ssss;

	// assume 4 byte integers
	int x{2'147'483'647}; // the maximum value of a 4-byte signed integer
	std::cout << x << '\n';

	x = x + 1; // integer overflow, undefined behavior
	std::cout << x << '\n';
	// Unsigned integer overflow
	// The number 280 is too big to fit in our 1-byte range of 0 to 255. 1 greater than the largest
	// number of the type is 256. Therefore, we divide 280 by 256, getting 1 remainder 24. The
	// remainder of 24 is what is stored.
	unsigned short xs{65535}; // largest 16-bit unsigned value possible
	std::cout << "xs was: " << xs << '\n';

	xs = 65536; // 65536 is out of our range, so we get modulo wrap-around
	std::cout << "xs is now: " << xs << '\n';

	xs = 65537; // 65537 is out of our range, so we get modulo wrap-around
	std::cout << "xs is now: " << xs << '\n';

	unsigned short xz{0}; // smallest 2-byte unsigned value possible
	std::cout << "xz was: " << xz << '\n';

	xz = -1; // -1 is out of our range, so we get modulo wrap-around
	std::cout << "xz is now: " << xz << '\n';

	xz = -2; // -2 is out of our range, so we get modulo wrap-around
	std::cout << "xz is now: " << xz << '\n';
	// fast and least types
	std::cout << "least 8:  " << sizeof (std::int_least8_t) * 8 << " bits\n";
	std::cout << "least 16: " << sizeof (std::int_least16_t) * 8 << " bits\n";
	std::cout << "least 32: " << sizeof (std::int_least32_t) * 8 << " bits\n";
	std::cout << '\n';
	std::cout << "fast 8:  " << sizeof (std::int_fast8_t) * 8 << " bits\n";
	std::cout << "fast 16: " << sizeof (std::int_fast16_t) * 8 << " bits\n";
	std::cout << "fast 32: " << sizeof (std::int_fast32_t) * 8 << " bits\n";
    

	return 0;
}

// Warning::The 8-bit fixed-width integer types are often treated like chars instead of integer
// values (and this may vary per system). Prefer the 16-bit fixed integral types for most cases.

// NOTE:CPUs are often optimized to process data of a certain size (e.g. 32
// bits), and types that match that size may be processed quicker. On such a
// machine, a 32-bit int could be faster than a 16-bit short or an 8-bit char.

// BestPractice:Favor signed numbers over unsigned numbers for holding quantities (even quantities
// that should be non-negative) and mathematical operations. Avoid mixing signed and unsigned
// numbers.

/*

Prefer int when the size of the integer doesn’t matter (e.g. the number will always fit within
the range of a 2-byte signed integer). For example, if you’re asking the user to enter their age, or
counting from 1 to 10, it doesn’t matter whether int is 16 or 32 bits (the numbers will fit either
way). This will cover the vast majority of the cases you’re likely to run across. Prefer std::int#_t
when storing a quantity that needs a guaranteed range. Prefer std::uint#_t when doing bit
manipulation or where well-defined wrap-around behavior is required.

Avoid the following when possible:

	-short and long integers -- use a fixed-width type instead.
	-Unsigned types for holding quantities.
	-The 8-bit fixed-width integer types.
	-The fast and least fixed-width types.
	-Any compiler-specific fixed-width integers -- for example, Visual Studio defines __int8,
		__int16, etc…
*/