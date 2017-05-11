#ifndef OUT_OF_RANGE_H
#define OUT_OF_RANGE_H
#include <iostream>

class Number;

class OutOfRange {
public:
	OutOfRange(float argument, std::string name)
		: _wrong_val (argument)
		, _name_of_object (name)
	{}
	~OutOfRange() {
		for (unsigned int i = 0; i < Number::pointers.size(); ++i) {
			delete Number::pointers[i];
		}
		Number::pointers.clear();
	}
	friend std::ostream& operator<<(std::ostream& out, const OutOfRange& object);
private:
	float _wrong_val;
	std::string _name_of_object;
};

#endif // OUT_OF_RANGE_H
