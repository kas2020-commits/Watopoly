#ifndef __IO_H__
#define __IO_H__
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include <iostream>
#include <sstream>
#include <map>
#include "Game.h"
#include "View.h"

class IOException : public GameException {
	public:
		IOException(std::string message) : GameException{message} {}
		IOException() : GameException{""} {}
};

class IO {
	public:
	IO();
	void save(const std::string, Game *);
	void load(const std::string, Game *, View *);
};

#endif

