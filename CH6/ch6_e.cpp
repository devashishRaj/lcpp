// logical operators
// to know whether multiple conditions are true simultaneously
// to know whether any one of multiple conditions is true.
// NOTE:left operand must evaluate first.
// logical NOT has a very high level of precedence.

// logical AND has higher precedence than logical OR

// Logical XOR is a logical operator provided in some languages that is used to test whether an odd
// number of conditions is true:

// operator^ is a bitwise XOR, not a logical XOR)

#include <iostream>

int main() {
	std::cout << "Enter a number: ";
	int value{};
	std::cin >> value;

	if (value > 10 && value < 20)
		std::cout << "Your value is between 10 and 20\n";
	else
		std::cout << "Your value is not between 10 and 20\n";

	// logical XOR can be implemented as follows:
	bool a{true};
	bool b{false};
	bool c{true};
	if (a != b) // a XOR b, assuming a and b are bool
		;
	// can be extended to multiple operands as follows
	if (a != b != c) // a XOR b XOR c, assuming a, b, and c are bool
		;
	// If you need a form of logical XOR that works with non-Boolean operands, you can static_cast
	// your operands to bool
	if (static_cast<bool>(a) != static_cast<bool>(b) !=
		static_cast<bool>(c)) // a XOR b XOR c, for any type that can be converted to bool
		;
	// NOTE:operator! implicitly converts its operand to bool) also works ,!! is necessary in cases
	// where we have an odd number of operands
	if (!!a != !!b != !!c) // a XOR b XOR c, for any type that can be converted to bool
		;
	// Alternative operator representations
	std::cout << !a && (b || c);
	std::cout << not a and (b or c);
	return 0;
}

// Warning:Short circuit evaluation may cause Logical OR and Logical AND to not evaluate the right
// operand. Avoid using expressions with side effects in conjunction with these operators.

/*
	Short circuit evaluation
	In order for logical AND to return true, both operands must evaluate to true. If the left
   operand evaluates to false, logical AND knows it must return false regardless of whether the
   right operand evaluates to true or false. In this case, the logical AND operator will go ahead
   and return false immediately without even evaluating the right operand! This is known as short
   circuit evaluation, and it is done primarily for optimization purposes.
*/

// BestPractice:
// If logical NOT is intended to operate on the result of other operators, the other
// operators and their operands need to be enclosed in parentheses.

// When mixing logical AND and logical OR in a single expression, explicitly parenthesize each
// operation to ensure they evaluate how you intend.

/*
De Morgan’s laws :

!(x && y) is equivalent to !x || !y
!(x || y) is equivalent to !x && !y

*/
