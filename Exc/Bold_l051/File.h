#ifndef FILE_H
#define FILE_H
#include "Unit.h"

class File: public Unit {
public:
	File(const char* name)
		: Unit(name)
	{}
	~File();

	void print() const {
		std::cout << _name << std::endl;
	}
	
};


#endif // FILE_H
