#ifndef F_ELEMENTARNE_H
#define F_ELEMENTARNE_H
#include "Fun.h"

class Liniowa: public Fun {
public:
	Liniowa()
		: Fun()
	{}
	static Liniowa* utworz() {
		return new Liniowa();
	}
	double wartosc(double value) {
		return a_val * value + b_val;
	}
};

class Kwadratowa: public Fun {
public:
	Kwadratowa()
		: Fun()
	{}
	static Kwadratowa* utworz() {
		return new Kwadratowa();
	}
	Kwadratowa* c(double value) {
		c_val = value;
		return this;
	}
	double wartosc(double value) {
		return a_val * pow(value, 2) + b_val * value + c_val;
	}
private:
	double c_val;
};

#endif // F_ELEMENTARNE_H
