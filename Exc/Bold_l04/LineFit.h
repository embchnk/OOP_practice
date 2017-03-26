#ifndef LineFit_h
#define LineFit_h
#include "Fit.h"

class LineFit: public Fit {
public:
	LineFit(const char* name)
		: Fit(name) 
		, a (0)
		, b (0)
	{}
	~LineFit() {}
	void appendPoint(float x, float y) {
		a += x + y;
		b += x - y;
	}
	unsigned int nParams() const { return 2; }
	const char* expression() const { return "y=a * x + b"; }
	
	const char* parameterName(int index) const {
		if (index) {
			return "b";
		}
		return "a";
	}
	float parameterValue(int index) const {
		if (index) {
			return b;
		}
		return a;
	}
private:
	float a;
	float b;
};


#endif //LineFit_h