#include "Fraction.h"

Fraction::Fraction()
	: _counter ( 0 )
	, _denominator ( 0 )
{}
/***************************************************************/
Fraction::Fraction( int counter, int denominator )
	: _counter ( counter )
	, _denominator ( denominator )
{
	std::cout << "Creating " << _counter << "/" << _denominator << std::endl;
}
/***************************************************************/
Fraction::~Fraction(){
	std::cout << "Destroying " << _counter << "/" << _denominator << std::endl;
}
/***************************************************************/
std::ostream& operator<<( std::ostream& out, Fraction& frac ){
	out << "address=" << &frac << " value=" << frac._counter << "/" << frac._denominator;
	return out;
}
/***************************************************************/
