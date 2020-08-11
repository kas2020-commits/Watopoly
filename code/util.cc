#include "util.h"

int rollDie()
{
	std::random_device randonum{};
	return (randonum() % 6) + 1;
}

int getRand(int min, int max)
{
	std::random_device rd{};
	return (rd() % max) + min;
}
