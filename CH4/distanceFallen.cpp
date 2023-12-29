#include "distanceFallen.h"
#include <iostream>

void distanceFallen(double towerHeight, int seconds) {
	double distanceFallen{(9.8 * (seconds * seconds)) / 2};
	if (distanceFallen >= towerHeight) {
		std::cout << "At " << seconds << " seconds, the ball is on the ground." << '\n';
		return;
	} else {
		std::cout << "At " << seconds
				  << " seconds, the ball is at height: " << towerHeight - distanceFallen << '\n';
	}
}