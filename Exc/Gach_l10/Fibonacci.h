#ifndef FIBONACCI_H
#define FIBONACCI_H
#include <iostream>

class BaseClass {
public:
	virtual void print() const =0;

	enum {
		value = 0
	};
};

template <int T>
class Fibonaci: public BaseClass {
public:
	enum {
		value = Fibonaci<T - 1>::value + Fibonaci<T - 2>::value
	};

	void print() const {
		std::cout << "Fibonaci(" << T << ") = " << value << std::endl;
	}
};

template <>
class Fibonaci <1>: public BaseClass {
public:
	enum {
		value = 1
	};

	void print() const {
		std::cout << "Fibonaci(" << 1 << ") = " << value << std::endl;
	}
};

template <>
class Fibonaci <2>: public BaseClass {
public:
	enum {
		value = 1
	};

	void print() const {
		std::cout << "Fibonaci(" << 2 << ") = " << value << std::endl;
	}
};


#endif // FIBONACCI_H
