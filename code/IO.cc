#include "IO.h"

void IO::save(const std::string filename)
{
	std::ofstream file {filename};
	std::vector<std::string> names { "Caleb", "Amy", "Susan"};
	for (auto &i : names) file << i << std::endl;
	file.close();
}

void IO::load(const std::string filename)
{
	std::ofstream file {filename};
	std::vector<std::string> names { "Caleb", "Amy", "Susan"};
	for (auto &i : names) file << i << std::endl;
	file.close();
}
