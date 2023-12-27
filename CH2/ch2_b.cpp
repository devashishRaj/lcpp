/*
 When the program is executed, the operating system makes a function call to main. Execution then
 jumps to the top of main. The statements in main are executed sequentially. Finally, main returns
 an integer value (usually 0), and your program terminates. The return value from main is sometimes
 called a status code (also sometimes called an exit code, or rarely a return code), as it is used
 to indicate whether the program ran successfully or not.
*/

#include <iostream>

int getValueFromUser() {
	std::cout << "Enter an integer" << '\n';
	int x;
	std::cin >> x;
	// document your function with a comment indicating what the return values mean
	// return integer entered via user
	return x;
}

int main() {
	int num{getValueFromUser()};
	std::cout << "Your num is " << num << " it's double is " << num * 2 << '\n';
	return 0;
}

// BESTPRACTICE:
//  essence of modular programming: the ability to write a function, test it, ensure that it works,
//  and then know that we can reuse it as many times as we want and it will continue to work (so
//  long as we don’t modify the function -- at which point we’ll have to retest it).