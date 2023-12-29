// Conditional opeartor aka ternary operator:
// Conditional	?:	c ? x : y	If conditional c is true then evaluate x, otherwise evaluate y
// condition ? expression1 : expression2;

// The conditional operator evaluates as an expression

#include <iostream>

int main() {
	// in form of if-else it will require lot extra code .
	constexpr bool inBigClassroom{false};
	constexpr int classSize{inBigClassroom ? 30 : 20};
	std::cout << "The class size is: " << classSize << '\n';

	// Parenthesizing the conditional operator
	int x{2};
	int y{1};
	// You might expect this to evaluate as 10 - (x > y ? x : y) (which would evaluate to 8) but it
	// actually evaluates as (10 - x) > y ? x : y (which evaluates to 2).
	int z{10 - x > y ? x : y};
	std::cout << z;

	// The type of the expressions must match or be convertible
	std::cout << (true ? 1 : 2) << '\n'; // okay: both operands have matching type int

	std::cout << (false ? 1 : 2.2) << '\n'; // okay: int value 1 converted to double

	std::cout << (true ? -1 : 2u)
			  << '\n'; // surprising result: -1 converted to unsigned int, result out of range

	// std::cout << (x != 5 ? x : "x is 5"); // compile error: compiler can't find common type for
	// constexpr int and C-style string literal
	// We can explicitly convert the types to match or use if-else
	std::cout << (x != 5 ? std::to_string(x) : std::string{"x is 5"}) << '\n';


	// NOTE:If x is constexpr, then the condition x != 5 is a constant expression. In such cases,
	// using if constexpr should be preferred over if

	return 0;
}

// BestPractice:Prefer to avoid the conditional operator in complicated expressions.

// Parenthesize the entire conditional operator when used in a compound expression (an
// expression with other operators).

// For readability, parenthesize the condition if it contains any operators (other than the function
// call operator).