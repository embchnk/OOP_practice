#ifndef Main_h
#define Main_h
#include "ComplexNumber.h"
#include <iostream>

class Fraction;

typedef float english;
typedef Fraction polish;

//funkcja tworząca float z liczb podanych jako argumenty
float createFloat( float, float );

class Fraction{
public:
	Fraction( int );
	float retFrac(){ return createFloat( _whole, _fractional ); }

	float operator,( int );
private:
	int _whole;
	int _fractional;
};

Fraction::Fraction( int whole )
	: _whole ( whole )
{}
/************************************************************************/
float createFloat( float whole, float fractional ){
	int n = fractional;
	int counter = 1;

	do{
		n /= 10;
		counter *= 10;
	}while(n);

	fractional = fractional / counter;

	return (float)( whole + fractional );
}
/************************************************************************/
float Fraction::operator,( int fractional ){
	return createFloat( _whole, fractional );
}
/************************************************************************/

#endif // Main_h