#include "Fraction.h"

using namespace std;

int Fraction::Simplify = 1;

Fraction::Fraction( int counter, int denominator )
	: _counter ( counter )
	, _denominator ( denominator )
{
	std::cout << "Creating: " << _counter << "/" << _denominator << std::endl;
}
/******************************************************************/
Fraction::~Fraction()
{
	std::cout << "Destroying: " << _counter << "/" << _denominator << std::endl;
}
/******************************************************************/
void Fraction::Print()
{
	std::cout << _counter << "/" << _denominator << std::endl;
}
/******************************************************************/
ostream& operator<<( ostream& out, const Fraction& frac )
{
	out << frac._counter << "/" << frac._denominator;
	return out;
}