// CHAR type

#include <iostream>

int main() {
	[[maybe_unused]] char ch{5};	// initialize with integer 5 (stored as integer 5)
	[[maybe_unused]] char chx{'5'}; // initialize with code point for '5' (stored as integer 53)

	char ch1{'a'};	  // (preferred)
	std::cout << ch1; // cout prints character 'a'
	char ch2{98};	  // code point for 'b' (not preferred)
	std::cout << ch2; // cout prints a character ('b')
	std::cout << 'c';

	std::cout << "Input a keyboard character: "; // assume the user enters "abcd" (without quotes)
	char chz{};
	std::cin >> chz; // ch = 'a', "bcd" is left queued.
	std::cout << "You entered: " << chz << '\n';
	// Note: The following cin doesn't ask the user for input, it grabs queued input!
	std::cin >> chz; // ch = 'b', "cd" is left queued.
	std::cout << "You entered: " << chz << '\n';

	// A signed char can hold a number between -128 and 127. An unsigned char can hold a number
	// between 0 and 255.

	// escpace sequences
	// \’ prints a single quote
	// \” prints a double quote
	// \\ prints a backslash
	// \x(number)	Translates into char represented by hex number
	std::cout << "\"This is quoted text\"\n";
	std::cout << "This string contains a single backslash \\\n";
	std::cout << "6F in hex is char '\x6F'\n";
	return 0;

	// Text between double quotes (e.g. “Hello, world!”) is treated as a string of multiple
	// characters.

	// BestPractice:Put stand-alone chars in single quotes (e.g. 't' or '\n', not "t" or "\n"). This
	// helps the compiler optimize more effectively.

    //Avoid multicharacter literals (e.g. '56').
}