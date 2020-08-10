#include "util.h"

int rollDie()
{
	std::random_device randonum{};
	return (randonum() % 6) + 1;
}
