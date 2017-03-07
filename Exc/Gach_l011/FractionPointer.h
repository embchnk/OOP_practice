#ifndef FractionPointer_h 
#define	FractionPointer_h
#include "Fraction.h"

class Fraction;

class FractionPointer
{
	Fraction* _fracPtr;

public:

	FractionPointer( Fraction* );
	~FractionPointer();

	Fraction* operator->();
	FractionPointer& operator=( Fraction* );
	FractionPointer& operator=( const FractionPointer& );
	FractionPointer operator*( const FractionPointer& );
	Fraction* operator->*( int* );

	friend Fraction& operator*( const FractionPointer& );
	friend FractionPointer& operator*=( FractionPointer&, Fraction& );
	friend Fraction& operator*( FractionPointer&, FractionPointer& );
};


#endif //FractionPointer_h