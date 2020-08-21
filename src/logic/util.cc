#include "util.h"

//
int getRand(int min, int max) {
	std::random_device rd{};
	return (rd() % max) + min;
}

