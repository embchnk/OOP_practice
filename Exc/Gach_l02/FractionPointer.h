#ifndef FractionPointer_h
#define FractionPointer_h
#include <iostream>
#include "Fraction.h"

class Fraction;

class FractionPointer{
public:

	FractionPointer();
	FractionPointer( Fraction* );
	FractionPointer( FractionPointer& );
	FractionPointer( const FractionPointer& );
	~FractionPointer();
	Fraction* retPtr(){ return _fracPtr; }

	FractionPointer& operator=( FractionPointer& );
	operator Fraction*(){ return _fracPtr; }

	friend std::ostream& operator<<( std::ostream&, FractionPointer& );

private:

	Fraction *_fracPtr;
};

#endif //FractionPointer_h