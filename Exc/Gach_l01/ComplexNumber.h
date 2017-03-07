#ifndef ComplexNumber_h
#define ComplexNumber_h
#include <iostream>

class ComplexNumber
{
	int _re;
	int _im;
public:
	static const ComplexNumber i;
	static int IMAGINARY;
	static int REAL;
	int re() const { return _re; }
	int im() const { return _im; }

	ComplexNumber( int, int );
	ComplexNumber( int );
	ComplexNumber( const ComplexNumber& );
	~ComplexNumber();

	ComplexNumber& operator*=( const int );
	ComplexNumber& operator++();
	ComplexNumber& operator=( const ComplexNumber& );
	ComplexNumber operator++( int );
	int& operator[]( int );

	friend std::ostream& operator<<( std::ostream&, const ComplexNumber& );
	friend ComplexNumber operator+( const ComplexNumber&, const ComplexNumber& );
	friend ComplexNumber operator*( const ComplexNumber&, const ComplexNumber& );
	friend ComplexNumber operator-( int, const ComplexNumber& );
	friend ComplexNumber operator-( const ComplexNumber&, const ComplexNumber& );
	friend ComplexNumber operator+( int, const ComplexNumber& );
	friend ComplexNumber operator*( const ComplexNumber&, int );
	friend bool operator>( const ComplexNumber&, const ComplexNumber& );

};

#endif //ComplexNumber_h