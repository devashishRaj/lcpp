// std::string and std::string_view
// In modern C++, C-style string variables are best avoided.
// In string form, numbers are treated as text, not as numbers, and thus they can not be manipulated
// as numbers

#include <iostream>
#include <string>

// str provides read-only access to whatever argument is passed in
void printSV(std::string_view str); // now a std::string_view

int main() {
	std::string name{"Alex"}; // initialize with string literal
	std::cout << name << '\n';
	name = "Jason"; // change to longer string
	std::cout << name << '\n';
	name = "Joy"; // change to shorter string
	std::cout << name << '\n';

	// Use std::getline() to input text
	std::cout << "Enter your full name" << '\n';
	std::getline(std::cin >> std::ws, name); // read a full line of text into name
	std::cout << "Whats your favourite color?" << '\n';
	std::string color;
	std::getline(std::cin >> std::ws, color);
	std::cout << "Your name is " << name << " and your favorite color is " << color << '\n';

	// What the heck is std::ws?
	// The std::ws input manipulator tells std::cin to ignore any leading whitespace before
	// extraction. Leading whitespace is any whitespace character (spaces, tabs, newlines) that
	// occur at the start of the string.

	std::cout << "Pick 1 or 2: ";
	int choice{};
	std::cin >> choice;
	std::cout << "Now enter your name: ";
	std::getline(std::cin >> std::ws, name);
	// std::getline(std::cin, name); // note:no std::ws here , try this to understand the bug
	/*
		When you enter a value using operator>>, std::cin not only captures the value, it also
	   captures the newline character ('\n') that occurs when you hit the enter key. So when we type
	   2 and then hit enter, std::cin captures the string "2\n" as input. It then extracts the value
	   2 to variable choice, leaving the newline character behind for later

		Using the extraction operator (>>) with std::cin ignores leading whitespace. It stops
		extracting when encountering non-leading whitespace.
		std::getline() does not ignore leadingwhitespace unless you use input manipulator std::ws.
		It stops extracting when encountering a newline.
	*/
	std::cout << "Hello, " << name << ", you picked " << choice << '\n';
	// the returned length of a std::string does not include the implicit null-terminator character.
	std::cout << name << " has " << name.length()
			  << " characters\n"; // returns an unsigned integral value (most likely of type size_t)

	// In C++20, you can also use the std::ssize() function to get the length of a std::string as a
	// signed integral value:

	// Initializing a std::string is expensive
	// Do not pass std::string by value, as it makes an expensive copy.

	/*
	as a rule of thumb, it is okay to return a std::string by value when the expression of the
	return statement resolves to any of the following:

	A local variable of type std::string.
	A std::string that has been returned by value from a function call or operator.
	A std::string that is created as part of the return statement.
	*/

	// Literals for std::string
	using namespace std::string_literals; // easy access to the s suffix
	std::cout << "foo\n";				  // no suffix is a C-style string literal
	std::cout << "goo\n"s;				  // s suffix is a std::string literal

	// Constexpr strings
	// constexpr std::string name2{ "Alex"s }; // compile error

	// std::string_view provides read-only access to an existing string (a C-style string, a
	// std::string, or another std::string_view) without making a copy.
	std::string_view sa{"Hello, world!"}; // now a std::string_view
	printSV(sa);

	// std::string_view can be initialized with many different types of strings
	std::string_view s1{"Hello, world!"}; // initialize with C-style string literal
	std::cout << s1 << '\n';
	std::string s{"Hello, world!"};
	std::string_view s2{s}; // initialize with std::string
	std::cout << s2 << '\n';
	std::string_view s3{s2}; // initialize with std::string_view
	std::cout << s3 << '\n';

	// std::string_view parameters will accept many different types of string arguments
	printSV("Hello, world!"); // call with C-style string literal
	printSV(s2);			  // call with std::string
	printSV(s3);			  // call with std::string_view

	// std::string_view will not implicitly convert to std::string
	std::string str{sa}; // okay: we can create std::string using std::string_view initializer
	// okay: we can explicitly cast a std::string_view to a std::string
	std::string str2{static_cast<std::string>(sa)};

	// Assignment changes what the std::string_view is viewing
	s3 = "Devashish Raj";
	std::cout << s3 << '\n';
	std::cout << s2 << '\n';

	// Literals for std::string_view
	using namespace std::string_view_literals; // access the sv suffix
	std::cout << "moo\n"sv;					   // sv suffix is a std::string_view literal

	// constexpr std::string_view
	constexpr std::string_view cns{"Hello, world!"}; // s is a string symbolic constant
	std::cout << cns << '\n'; // s will be replaced with "Hello, world!" at compile-time
}

void printSV(std::string_view str) // now a std::string_view
{
	std::cout << str << '\n';
}
