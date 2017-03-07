#ifndef Fraction_h
#define	Fraction_h
#include <iostream>

using namespace std;

class Fraction
{
	

public:
	int _counter;
	int _denominator;

	~Fraction();
	Fraction( int, int );
	void Print();

	typedef int* Action;
	static int Simplify;

	friend ostream& operator<<( ostream&, const Fraction& );
};


#endif //Fraction_h