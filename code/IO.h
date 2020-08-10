#ifndef __IO_H__
#define __IO_H__
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include <iostream>
#include <sstream>
#include "Game.h"

struct IOImpl;

class IO {
	std::unique_ptr<IOImpl> list;
	Game * game;
	public:
	void save(const std::string);
	void load(const std::string);
	IO(Game *);
};

#endif
