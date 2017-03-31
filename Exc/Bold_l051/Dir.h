#ifndef DIR_H
#define DIR_H
#include "Unit.h"

class Dir: public Unit {
public:
	Dir(const char* name)
		: Unit(name)
		, _counter (0)
	{}
	~Dir();

	void print() const {

		std::cout << _name << std::endl;
		Unit::how_deep++;

		for (int i = 0; i < _counter; ++i) {
			for (int j = 0; j < Unit::how_deep; ++j)
				std::cout << " ";
			_container[i] -> print();
		}

		Unit::how_deep--;
	}

	Unit* operator+=(Unit* pointer) {
		_container[_counter] = pointer;
		_counter++;

		return this;
	}

	Unit* get(const char* name) {
		int i = 0;

		while (_container[i] -> ret_name() != name)
			i++;

		return _container[i];
	}

	void link(Unit* unit) {
		*this += unit;
	}
private:
	int _counter;
	Unit* _container[10];
};


#endif // DIR_H
