// Numeral systems

// we count using decimal numbers, where each numerical digit can be 0, 1, 2, 3, 4, 5, 6, 7, 8,
// or 9. Decimal is also called “base 10”, because there are 10 possible digits (0 through 9).

// numbers in C++ programs are assumed to be decimal.

// Octal is base 8 -- that is, the only digits available are: 0, 1, 2, 3, 4, 5, 6, and 7. In Octal,
// we count like this: 0, 1, 2, 3, 4, 5, 6, 7, 10, 11, 12, … (note: no 8 and 9, so we skip from 7 to
// 10).
// NOTE:Octal is hardly ever used, and we recommend you avoid it.

// Hexadecimal is base 16. In hexadecimal, we count like this: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B,
// C, D, E, F, 10, 11, 12, …
// NOTE:hexadecimal values are often used to represent memory addresses or raw data in memory (whose
// type isn’t known).

#include <format> // C++20
#include <iostream>
#include <print> // C++23

int main() {
	int x{012}; // 0 before the number means this is octal
	std::cout << x << '\n';

	// Because there are 16 different values for a hexadecimal digit, we can say that a single
	// hexadecimal digit encompasses 4 bits.
	int hx{0xF}; // 0x before the number means this is hexadecimal
	std::cout << hx << '\n';

	// Binary literals
	// Prior to C++14
	int bin{};	  // assume 16-bit ints
	bin = 0x0001; // assign binary 0000 0000 0000 0001 to the variable
	bin = 0x0002; // assign binary 0000 0000 0000 0010 to the variable
	bin = 0x0004; // assign binary 0000 0000 0000 0100 to the variable
	bin = 0x0008; // assign binary 0000 0000 0000 1000 to the variable
	bin = 0x0010; // assign binary 0000 0000 0001 0000 to the variable
	bin = 0x0020; // assign binary 0000 0000 0010 0000 to the variable
	bin = 0x0040; // assign binary 0000 0000 0100 0000 to the variable
	bin = 0x0080; // assign binary 0000 0000 1000 0000 to the variable
	bin = 0x00FF; // assign binary 0000 0000 1111 1111 to the variable
	bin = 0x00B3; // assign binary 0000 0000 1011 0011 to the variable
	bin = 0xF770; // assign binary 1111 0111 0111 0000 to the variable
	// In C++14
	bin = 0b1;		  // assign binary 0000 0000 0000 0001 to the variable
	bin = 0b11;		  // assign binary 0000 0000 0000 0011 to the variable
	bin = 0b1010;	  // assign binary 0000 0000 0000 1010 to the variable
	bin = 0b11110000; // assign binary 0000 0000 1111 0000 to the variable

	// Digit separators
	int binn{0b1011'0010};	   // assign binary 1011 0010 to the variable
	long value{2'132'673'462}; // much easier to read than 2132673462

	// Outputting values in decimal, octal, or hexadecimal
	int foo{12};
	std::cout << foo << '\n';			  // decimal (by default)
	std::cout << std::hex << foo << '\n'; // hexadecimal
	std::cout << foo << '\n';			  // now hexadecimal
	std::cout << std::oct << foo << '\n'; // octal
	std::cout << std::dec << foo << '\n'; // return to decimal
	std::cout << foo << '\n';			  // decimal

	// Outputting values in binary
	// std::bitset<8> means we want to store 8 bits
	std::bitset<8> bin1{0b1100'0101}; // binary literal for binary 1100 0101
	std::bitset<8> bin2{0xC5};		  // hexadecimal literal for binary 1100 0101

	std::cout << bin1 << '\n' << bin2 << '\n';
	std::cout << std::bitset<4>{0b1010} << '\n'; // create a temporary std::bitset and print it
	// In C++20 and C++23:
	// might show no member found in vscode but it will compile fine with:
	// clang++ -std=c++23 -Wall -g -glldb CH5/ch5_c.cpp -o bin/test
	std::cout << std::format("{:b}\n", 0b1010);	 // C++20
	std::cout << std::format("{:#b}\n", 0b1010); // C++20

	std::print("{:b} {:#b}\n", 0b1010, 0b1010); // C++23
	return 0;
}
