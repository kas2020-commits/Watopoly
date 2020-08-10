#ifndef __IO_H__
#define __IO_H__
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include <iostream>
#include <sstream>
#include "Game.h"
#include <map>

class IO {
	struct IOImpl;
	std::unique_ptr<IOImpl> list;
	public:
	void save(const std::string, std::unique_ptr<Game>);
	std::unique_ptr<Game> load(const std::string);
};

#endif
