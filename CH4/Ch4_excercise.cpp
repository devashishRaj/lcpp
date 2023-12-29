// simulate a ball being dropped off of a tower
/*
Write a short program to simulate a ball being dropped off of a tower. To start, the user should be
asked for the height of the tower in meters. Assume normal gravity (9.8 m/s2), and that the ball has
no initial velocity (the ball is not moving to start). Have the program output the height of the
ball above the ground after 0, 1, 2, 3, 4, and 5 seconds. The ball should not go underneath the
ground (height 0).

Use a function to calculate the height of the ball after x seconds. The function can calculate how
far the ball has fallen after x seconds using the following formula: distance fallen =
gravity_constant * x_seconds2 / 2

Expected output:

Enter the height of the tower in meters: 100
At 0 seconds, the ball is at height: 100 meters
At 1 seconds, the ball is at height: 95.1 meters
At 2 seconds, the ball is at height: 80.4 meters
At 3 seconds, the ball is at height: 55.9 meters
At 4 seconds, the ball is at height: 21.6 meters
At 5 seconds, the ball is on the ground.

*/

// RUN following in terminal if using clang:
//clang++ -std=c++20 -Wall -g -glldb CH4/Ch4_excercise.cpp CH4/distanceFallen.cpp -o bin/test 
// then run ./bin/test , make sure a bin is already created.

#include "distanceFallen.h"
#include <iostream>

int main() {
	double towerHeight;
	//float gravity_constant{9.8};
	//bool reached_ground{false};
	std::cout << "Enter the height of the tower in meters: ";
	std::cin >> towerHeight;
	std::cout << '\n';
	std::cout << "At 0 seconds, the ball is at height: " << towerHeight << " meters" << '\n';
	// double distanceFall{0};
	// distanceFall = (gravity_constant * (1 * 1)) / 2;
	// std::cout << "At 1 seconds, the ball is at height: " << towerHeight - distanceFall << "
	// meters"
	// 		  << '\n';
	// distanceFall = (gravity_constant * (2 * 2)) / 2;
	// std::cout << "At 2 seconds, the ball is at height: " << towerHeight - distanceFall << "
	// meters"
	// 		  << '\n';
	distanceFallen(towerHeight, 1);
	distanceFallen(towerHeight, 2);
	distanceFallen(towerHeight, 3);
	distanceFallen(towerHeight, 4);
	distanceFallen(towerHeight, 5);
}
