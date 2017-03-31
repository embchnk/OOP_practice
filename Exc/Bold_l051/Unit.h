#ifndef UNIT_H
#define UNIT_H
#include <iostream>

class Unit
{
public:
	Unit(const char* name)
		: _name (name)
	{}
	~Unit();

	friend std::ostream& operator<<(std::ostream& out, const Unit& unit) {
		unit.print();

		return out;
	}

	virtual void print() const =0;

	const char* ret_name() { return _name; }

	static int how_deep;
protected:
	const char* _name;
};

int Unit::how_deep = 0;

#endif // UNIT_H
