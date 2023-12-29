// std::string_view continued

// Ownership can be expensive. As an owner, it is your responsibility to acquire, manage, and
// properly dispose of the objects you own.

// Viewing is inexpensive. As a viewer, you have no responsibility for the objects you are viewing,
// A view is dependent on the object being viewed. If the object being viewed is modified or
// destroyed while the view is still being used, unexpected or undefined behavior will result.

// A std::string_view that is viewing a string that has been destroyed is sometimes called a
// dangling view.

// std::string_view is best used as a read-only function parameter
#include <iostream>
#include <string>
#include <string_view>

std::string_view firstAlphabetical(std::string_view s1, std::string_view s2) {
	return s1 < s2 ? s1 : s2; // uses operator?: (the conditional operator)
}

std::string_view getBoolNameViaCStyle(bool b) {
	if (b)
		return "true"; // return a std::string_view viewing "true"

	return "false"; // return a std::string_view viewing "false"
} // "true" and "false" are not destroyed at the end of the function

std::string_view getBoolName(bool b) {
	std::string t{"true"};	// local variable
	std::string f{"false"}; // local variable

	if (b)
		return t; // return a std::string_view viewing t

	return f; // return a std::string_view viewing f
} // t and f are destroyed at the end of the function

std::string getName() {
	std::string s{"Alex"};
	return s;
}

void printSV(std::string_view str) // now a std::string_view, creates a view of the argument
{
	std::cout << str << '\n';
}

int main() {
	printSV("Hello, world!"); // call with C-style string literal

	std::string s2{"Hello, world!"};
	printSV(s2); // call with std::string

	std::string_view s3{s2};
	printSV(s3); // call with std::string_view

	// Improperly using std::string_view
	std::string_view sv{};

	{									// create a nested block
		std::string s{"Hello, world!"}; // create a std::string local to this nested block
		sv = s;							// sv is now viewing s
	}						 // s is destroyed here, so sv is now viewing an invalid string`
	std::cout << sv << '\n'; // undefined behavior

	std::string_view name{getName()}; // name initialized with return value of function
	std::cout << name << '\n';		  // undefined behavior

	// We can also get undefined behavior when the underlying string is modified:
	std::string s{"Hello, world!"};
	std::string_view sv2{s};  // sv is now viewing s
	s = "Hello, universe!";	  // modifies s, which invalidates sv (s is still valid)
	std::cout << sv2 << '\n'; // undefined behavior
	sv2 = s;				  // revalidate sv: sv is now viewing s again
	std::cout << sv2 << '\n'; // prints "Hello, universe!"

	// returning a std::string_view, this is often dangerous.
	std::cout << getBoolName(true) << ' ' << getBoolName(false) << '\n'; // undefined behavior

	// NOTE:it’s fine to return C-style string literals from a function that has a return type of
	// std::string_view.
	std::cout << getBoolNameViaCStyle(true) << ' ' << getBoolNameViaCStyle(false) << '\n'; // ok

	// it is generally okay to return a function parameter of type std::string_view:
	// Warning:If an argument is a temporary that is destroyed at the end of the full expression
	// containing the function call, the returned std::string_view must be used immediately, as it
	// will be left dangling after the temporary is destroyed.
	std::string a{"World"};
	std::string b{"Hello"};

	std::cout << firstAlphabetical(a, b) << '\n'; // prints "Hello"

	// View modification functions
	std::string_view str{"Peach"};
	std::cout << str << '\n';
	// Remove 1 character from the left side of the view
	str.remove_prefix(1);
	std::cout << str << '\n';
	// Remove 2 characters from the right side of the view
	str.remove_suffix(2);
	std::cout << str << '\n';
	str = "Peach"; // reset the view
	std::cout << str << '\n';

	// std::string_view can view a substring
	// std::string_view may or may not be null-terminated
	// TIP:If you have a non-null-terminated std::string_view and you need a null-terminated string
	// for some reason, convert the std::string_view into a std::string.

	return 0;
}

// Warning
// Do not initialize a std::string_view with a std::string literal, as this will leave the
// std::string_view dangling.
// It is okay to initialize a std::string_view with a C-style string literal or a std::string_view
// literal. It’s also okay to initialize a std::string_view with a C-style string object, a
// std::string object, or a std::string_view object, as long as that string object outlives the
// view.