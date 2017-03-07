#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

class Fraction{
public:

	Fraction();
	Fraction( int, int );
	~Fraction();
	int& Numerator(){ return *( &_counter ); }
	int& Denominator(){ return *( &_denominator ); }

	friend std::ostream& operator<<( std::ostream&, Fraction& );

private:

	int _counter;
	int _denominator;
};


#endif // FRACTION_H
