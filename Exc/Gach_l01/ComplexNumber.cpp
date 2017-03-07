#include <iostream>
#include <string.h>
#include "ComplexNumber.h"

const ComplexNumber ComplexNumber::i( 0, 1 );
int ComplexNumber::IMAGINARY = 0;
int ComplexNumber::REAL = 1;

ComplexNumber::ComplexNumber( int re, int im )
	: _re ( re )
	, _im ( im )
{}
/*****************************************************************/
ComplexNumber::ComplexNumber( const ComplexNumber& comp )
	: _re ( comp.re() )
	, _im ( comp.im() )
{}
/*****************************************************************/
ComplexNumber::ComplexNumber( int re )
	: _re ( re )
	, _im ( 0 )
{}
/*****************************************************************/
ComplexNumber::~ComplexNumber()
{

}
/*****************************************************************/
ComplexNumber& ComplexNumber::operator*=( const int mult )
{
	_re = _re * mult;
	_im = _im * mult;
	return *this;
}
/*****************************************************************/
ComplexNumber& ComplexNumber::operator++()
{	
	--_re;
	return *this;
}
/*****************************************************************/
ComplexNumber ComplexNumber::operator++( int )
{	
	ComplexNumber temp( *this );
	++( *this );
	//std::cout << *temp << " <- temp, this -> " << *this << std::endl;
	return temp;
}
/**************************************************************/
std::ostream& operator<<( std::ostream& out, const ComplexNumber& comp )
{
	out << comp.re() << " + " << comp.im() << "i ";
	return out;
}
/*****************************************************************/
ComplexNumber operator+( const ComplexNumber& comp1, const ComplexNumber& comp2 )
{
	ComplexNumber temp( comp1 );
	temp._re += comp2._re;
	temp._im += comp2._im;
	return temp;
}
/*****************************************************************/
ComplexNumber operator*( const ComplexNumber& comp1, const ComplexNumber& comp2 )
{
	ComplexNumber temp( comp1 );
	//std::cout << "Mnożymy: " << comp1 << " * " << comp2 << std::endl;
	temp._re = ( comp1._re * comp2._re ) - ( comp1._im * comp2._im );
	temp._im = ( comp1._re * comp2._im ) + ( comp1._im * comp2._re );
	return temp;
}
/*****************************************************************/
ComplexNumber operator*( const ComplexNumber& comp, int mult )
{
	ComplexNumber temp( comp );
	temp._re *= mult;
	temp._im *= mult;
	return temp;
}
/*****************************************************************/
ComplexNumber& ComplexNumber::operator=( const ComplexNumber& comp1 )
{
	_re = comp1._re;
	_im = comp1._im;
	return *this;
}
/*****************************************************************/
ComplexNumber operator-( int red, const ComplexNumber& comp )
{
	ComplexNumber temp( comp );
	//std::cout << "Odejmujemy od: " << red << " - " << comp << std::endl;
	temp._re = red - temp._re;
	return temp;
}
/*****************************************************************/
ComplexNumber operator-( const ComplexNumber& comp1, const ComplexNumber& comp2 )
{
	ComplexNumber temp( comp1 );
	//std::cout << "Odejmujemy od: " << comp1 << " - " << comp2 << std::endl;
	temp._re -= comp2.re();
	temp._im -= comp2.im();
	return temp;
}
/*****************************************************************/
ComplexNumber operator+( int sum, const ComplexNumber& comp )
{
	ComplexNumber temp( comp );
	temp._re += sum;
	return temp;
}
/*****************************************************************/
bool operator>( const ComplexNumber& comp1, const ComplexNumber& comp2 )
{
	return ( ( comp1.re() * comp1.re() ) + ( comp1.im() * comp1.im() ) > ( comp2.re() * comp2.re() ) + ( comp2.im() * comp2.im() ) );
}
/*****************************************************************/
int& ComplexNumber::operator[]( int checkIfReal )
{ 
	if( checkIfReal )
		return _re;
	return _im;
}
/*****************************************************************/