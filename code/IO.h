#ifndef __IO_H__
#define __IO_H__
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include <iostream>
#include <sstream>

struct IOImpl;

class IO {
	std::unique_ptr<IOImpl> list;
	public:
	void save(const std::string);
	void load(const std::string);
};

#endif
