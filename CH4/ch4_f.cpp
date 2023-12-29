// type conversion and static_cast
// The process of converting a value from one type to another type is called type conversion.
// When the compiler does type conversion on our behalf without us explicitly asking, we call this
// implicit type conversion.

// Explicit type conversion allow us (the programmer) to explicitly tell the compiler to convert a
// value from one type to another type, and that we take full responsibility

#include <iostream>

void print(double x) // print takes a double parameter
{
	std::cout << x << '\n';
}
// we can use overloading here but for sake of clear explanation of static cast , choose not to.
void printInt(int x) {
	std::cout << x << '\n';
}

int charAsInt(char c)
{
	return c;
}


/*
the value to be converted is used as input, and the conversion results in a new value of the target
type (via direct initialization).

In the above example, the conversion does not change variable y from type int to double. Instead,
the conversion uses the value of y (5) as input to create a new double value (5.0). This double
value is then passed to function print.
*/
int main() {
	int y{5};
	print(y); // y is of type int

	// Unsafe implicit conversions will typically either generate a compiler warning, or (in the
	// case of brace initialization) an error.
	double d{5}; // okay: int to double is safe
				 // int x { 5.5 }; // error:double to int not safe

	printInt(static_cast<int>(5.5)); // explicitly convert double value 5.5 to an int

	char ch{97}; // 97 is ASCII code for 'a'
	std::cout << ch << " has value " << static_cast<int>(ch)
			  << '\n'; // print value of variable ch as an int

	// Converting unsigned numbers to signed numbers
	unsigned int u{5};
	int s{static_cast<int>(u)}; // return value of variable u as an int
	std::cout << s << '\n';
	// WARNING:The static_cast operator doesn’t do any range checking

	// std::int8_t and std::uint8_t likely behave like chars instead of integers
	std::int8_t myInt{65};						  // initialize myInt with value 65
	std::cout << myInt << '\n';					  // you're probably expecting this to print 65
	std::cout << static_cast<int>(myInt) << '\n'; // will always print 65

	// WARNING:In cases where std::int8_t is treated as a char, input from the console can also
	// cause problems:
	std::cout << "Enter a number between 0 and 127: ";
	std::cin >> myInt;
	std::cout << "You entered: " << static_cast<int>(myInt) << '\n';
	/*
	Here’s what’s happening. When std::int8_t is treated as a char, the input routines interpret our
	input as a sequence of characters, not as an integer. So when we enter 35, we’re actually
	entering two chars, '3' and '5'. Because a char object can only hold one character, the '3' is
	extracted (the '5' is left in the input stream for possible extraction later). Because the char
	'3' has ASCII code point 51, the value 51 is stored in myInt, which we then print later as an
	int.
    */
    // implicit conversion instead of static_cast<int>
    std::cout << "Enter a single character: ";
	char c{};
	std::cin >> c;
	std::cout << "You entered '" << c << "', which has ASCII code " << charAsInt(c) << ".\n";

	return 0;
}