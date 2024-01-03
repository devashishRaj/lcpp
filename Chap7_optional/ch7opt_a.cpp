#include <bitset>
#include <iostream>

int main() {
	std::bitset<8> me{0b0000'0101}; // we need 8 bits, start with bit pattern 0000 0101
	me.set(3);						// set bit position 3 to 1 (now we have 0000 1101)
	me.flip(4);						// flip bit 4 (now we have 0001 1101)
	me.reset(4);					// set bit 4 back to 0 (now we have 0000 1101)

	std::cout << "All the bits: " << me << '\n';
	std::cout << "Bit 3 has value: " << me.test(3) << '\n';
	std::cout << "Bit 4 has value: " << me.test(4) << '\n';

	// Giving our bits names can help make our code more readable:
	[[maybe_unused]] constexpr int isHungry{0};
	[[maybe_unused]] constexpr int isSad{1};
	[[maybe_unused]] constexpr int isMad{2};
	[[maybe_unused]] constexpr int isHappy{3};
	[[maybe_unused]] constexpr int isLaughing{4};
	[[maybe_unused]] constexpr int isAsleep{5};
	[[maybe_unused]] constexpr int isDead{6};
	[[maybe_unused]] constexpr int isCrying{7};

	std::bitset<8> me2{0b0000'0101}; // we need 8 bits, start with bit pattern 0000 0101
	me2.set(isHappy);				 // set bit position 3 to 1 (now we have 0000 1101)
	me2.flip(isLaughing);			 // flip bit 4 (now we have 0001 1101)
	me2.reset(isLaughing);			 // set bit 4 back to 0 (now we have 0000 1101)

	std::cout << "All the bits: " << me2 << '\n';
	std::cout << "I am happy: " << me2.test(isHappy) << '\n';
	std::cout << "I am laughing: " << me2.test(isLaughing) << '\n';
	// NOTE:a std::bitset<8> will typically use either 4 or 8 bytes of memory, even though it
	// technically only needs 1 byte to store 8 bits. Thus, std::bitset is most useful when we
	// desire convenience, not memory savings.


	std::bitset<8> bits{0b0000'1101};
	std::cout << bits.size() << " bits are in the bitset\n";
	std::cout << bits.count() << " bits are set to true\n";
	std::cout << std::boolalpha;
	std::cout << "All bits are true: " << bits.all() << '\n';
	std::cout << "Some bits are true: " << bits.any() << '\n';
	std::cout << "No bits are true: " << bits.none() << '\n';

	return 0;
}