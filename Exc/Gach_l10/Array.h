#ifndef ARRAY_H
#define ARRAY_H
#include "Fibonacci.h"
#include <vector>

class Array {
public:
	void push_back(BaseClass* ptr) {
		_table.push_back(ptr);
	}

	BaseClass* operator[](const int index) {
		return _table[index];
	}

	void print() const {
		for (unsigned int i = 0; i < _table.size(); ++i)
			_table[i] -> print();
	}
private:
	std::vector<BaseClass*> _table;
};

#endif // ARRAY_H
