#ifndef SlopeFit_h
#define SlopeFit_h
#include "Fit.h"

class SlopeFit: public Fit {
public:
	SlopeFit(const char* name)
		: Fit(name) 
	{}
	~SlopeFit() {}
	void appendPoint(float x, float y) {
		a = x + y;
	}
	unsigned int nParams() const { return 1; }
	const char* expression() const { return "y=a * x"; }
	
	const char* parameterName(int index) const  {
		return "a";
	}
	float parameterValue(int index) const {
		return a;
	}
	void print() const {
		std::cout << "This is slope fit" << std::endl;
	}
private:
	unsigned int n;
	float a;
};



#endif //SlopeFit_h