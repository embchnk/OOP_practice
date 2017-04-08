#ifndef FUN_H
#define FUN_H
#include <math.h>

class Fun {
public:
	virtual ~Fun() {}
	virtual double wartosc(double value) =0;
	Fun* a(double value) {
		a_val = value;
		return this;
	}
	Fun* b(double value) {
		b_val = value;
		return this;
	}
	virtual Fun* c(double value) {
		return this;
	}
protected:
	double a_val;
	double b_val;
	Fun* _ptr;
};

#endif // FUN_H
