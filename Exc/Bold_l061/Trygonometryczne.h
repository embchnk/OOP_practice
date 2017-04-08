#ifndef TRYGONOMETRYCZNE_H
#define TRYGONOMETRYCZNE_H
#include "Fun.h"

class Sinus: public Fun {
public:
	Sinus()
		: Fun()
	{}
	double wartosc(double value) {
		return sin(value);
	}
};

#endif // TRYGONOMETRYCZNE_H
