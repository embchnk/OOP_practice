#ifndef SlopeFit_h
#define SlopeFit_h
#include "Fit.h"

class SlopeFit: public Fit {
public:
	//konstruktor
	SlopeFit(const char* name)
		: Fit(name) 
		, a (0)
	{}
	//destruktor
	~SlopeFit() {}
	//metoda dodająca punkt
	void appendPoint(float x, float y) {
		a += x + y;
	}
	//metoda zwracająca liczbę parametrów
	unsigned int nParams() const { return 1; }
	//metoda zwracająca wzór
	const char* expression() const { return "y = a * x"; }
	//metoda zwracająca nazwę parametru
	const char* parameterName(int index) const  {
		return "a";
	}
	//metoda zwracająca wartość parametru
	float parameterValue(int index) const {
		return a;
	}
private:
	unsigned int n;
	float a;
};



#endif //SlopeFit_h