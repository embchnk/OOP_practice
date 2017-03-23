#ifndef LineFit_h
#define LineFit_h
#include "Fit.h"

class LineFit: public Fit {
public:
	LineFit(const char* name)
		: Fit(name) 
	{}
	~LineFit() {}
	void appendPoint(float x, float y) {
		a = x / y;
		b = x * y;
	}
	unsigned int nParams() const { return 2; }
	const char* expression() const { return "y=a * x + b"; }
	
	const char* parameterName(int index) const {
		if (index - 1) {
			return "b";
		}
		return "a";
	}
	float parameterValue(int index) const {
		if (index - 1) {
			return b;
		}
		return a;
	}
	void print() const {
		std::cout << "This is line fit" << std::endl;
	}
private:
	float a;
	float b;
};


#endif //LineFit_h