#ifndef FractionRegister_h
#define FractionRegister_h
#include <iostream>
#include "Fraction.h"
#include "FractionPointer.h"

class Fraction;
class FractionPointer;

class FractionRegister{
public:

	FractionRegister();

	FractionRegister& operator<<( Fraction& );
	FractionRegister& operator<<( FractionPointer& );

	friend std::ostream& operator<<( std::ostream&, FractionRegister& );

	static int _counter;

private:

	static Fraction** _fracRegPtr;
	static FractionRegister* _regPtr;
};


#endif //FractionRegister_h