#ifndef X_H
#define X_H
#include <string>
#include <iostream>

class X {
public:
	X() {}
	X(std::string text)
		: _data (text)
	{}
	virtual ~X() {
		std::cout << "deleting X " << _data << std::endl;
	}
	std::string retData() const {
		return _data;
	}
protected:
	std::string _data;
};

class Y: public X {
public:
	Y(std::string text)
		: X(text)
	{}
	virtual ~Y() {
		std::cout << "deleting Y " << _data << std::endl;
	}
};

#endif // X_H
