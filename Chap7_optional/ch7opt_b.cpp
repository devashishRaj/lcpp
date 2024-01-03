#include <bitset>
#include <iostream>

// Define the number of options
const int numOptions = 32;
void someFunction(std::bitset<numOptions> options);

int main() {
	// C++ provides 6 bit manipulation operators, often called bitwise operators:

	// Bitwise left shift (<<) and bitwise right shift (>>) operators
	// 0011 << 1 is 0110
	// 0011 << 2 is 1100
	// 0011 << 3 is 1000
	// NOTE:we shifted a bit off the end of the number! Bits that are shifted off the end of the
	// binary
	// number are lost forever.
	// 1100 >> 1 is 0110
	// 1100 >> 2 is 0011
	// 1100 >> 3 is 0001
	// NOTE: Left-shift is always towards the most significant bit, and right-shift towards the
	// least significant bit.
	std::bitset<4> x{0b1100};
	// NOTE:std::cout has overloaded (provided an alternate definition for) operator<< that does
	// console output rather than bit shifting.When the compiler sees that the left operand of
	// operator<< is std::cout, it knows that it should call the version of operator<< that
	// std::cout overloaded to do output. If the left operand is an integral type, then operator<<
	// knows it should do its usual bit-shifting behavior.
	std::cout << x << '\n';
	std::cout << (x >> 1) << '\n'; // shift right by 1, yielding 0110
	std::cout << (x << 1) << '\n'; // shift left by 1, yielding 1000

	// if you’re using operator << for both output and left shift, parenthesization is require
	std::cout << x << 1 << '\n';   // print value of x (0110), then 1
	std::cout << (x << 1) << '\n'; // print x left shifted by 1 (1100)

	// BITWISE NOT
	std::cout << ~std::bitset<4>{0b0100} << ' ' << ~std::bitset<8>{0b0100} << '\n';

	// bitwise OR :applies to each bit!
	/*
	0 1 1 1 OR
	0 0 1 1 OR
	0 0 0 1
	--------
	0 1 1 1
	*/
	std::cout << (std::bitset<4>{0b0111} | std::bitset<4>{0b0011} | std::bitset<4>{0b0001}) << '\n';

	// Bitwise AND (&) works similarly
	/*
	0 0 0 1 AND
	0 0 1 1 AND
	0 1 1 1
	--------
	0 0 0 1

	*/

	std::cout << (std::bitset<4>{0b0001} & std::bitset<4>{0b0011} & std::bitset<4>{0b0111}) << '\n';

	// bitwise XOR (^), also known as exclusive or:  XOR evaluates to true (1) if one and only one
	// of its operands is true (1).
	/*
	0 0 0 1 XOR
	0 0 1 1 XOR
	0 1 1 1
	--------
	0 1 0 1
	*/
	std::cout << (std::bitset<4>{0b0001} ^ std::bitset<4>{0b0011} ^ std::bitset<4>{0b0111}) << '\n';

	// Bitwise assignment operators
	/*
		Left shift assignment	<<=	x <<= y	Shift x left by y bits
		Right shift assignment	>>=	x >>= y	Shift x right by y bits
		Bitwise OR assignment	|=	x |= y	Assign x | y to x
		Bitwise AND assignment	&=	x &= y	Assign x & y to x
		Bitwise XOR assignment	^=	x ^= y	Assign x ^ y to x

		instead of writing x = x >> 1;, you can write x >>= 1;
	*/
	std::bitset<4> bits{0b0100};
	bits >>= 1;
	std::cout << bits << '\n';
	// There is no bitwise NOT assignment operator. This is because the other bitwise operators are
	// binary, but bitwise NOT is unary, se normal assignment here: x = ~x;

	// Bit masks : a predefined set of bits that is used to select which specific bits will be
	// modified by subsequent operations.the bit mask blocks the bitwise operators from touching
	// bits we don’t want modified, and allows access to the ones we do want modified.
	// explore Bit manipulation with bitwise operators and bit masks in use of functions that needs
	// multiple options: Imagine you had a function that could take any combination of 32 different
	// options. One way to write that function would be to use 32 individual Boolean parameters:
	/*
	void someFunction(bool option1, bool option2, bool option3, bool option4, bool option5, bool
	option6, bool option7, bool option8, bool option9, bool option10, bool option11, bool option12,
	bool option13, bool option14, bool option15, bool option16, bool option17, bool option18, bool
	option19, bool option20, bool option21, bool option22, bool option23, bool option24, bool
	option25, bool option26, bool option27, bool option28, bool option29, bool option30, bool
	option31, bool option32);
	*/
	// or you can define it ad  : void someFunction(std::bitset<32> options);
	// then use bit flags to pass in only the options you wanted: someFunction(option10 | option32)
	// to Enable option10 and option32

	std::bitset<numOptions> options;
	options.set(9);	 // Set option10
	options.set(31); // Set option32

	// Call the function with the specified options
	someFunction(options);

	return 0;
}

// Define a function using std::bitset
void someFunction(std::bitset<numOptions> options) {
	// Example: Check if option10 and option32 are enabled
	if (options.test(9) && options.test(31)) {
		std::cout << "Option 10 and Option 32 are enabled!" << std::endl;
	}
}

// BestPractice:Avoid using the bitwise operators with signed operands, as many operators will
// return implementation-defined results prior to C++20 or have other potential gotchas that are
// easily avoided by using unsigned operands (or std::bitset).