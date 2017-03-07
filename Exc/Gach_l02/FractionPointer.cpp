#include <iostream>
#include "FractionPointer.h"

FractionPointer::FractionPointer()
	: _fracPtr ( 0 )
{}
/****************************************************************/
FractionPointer::FractionPointer( Fraction* fracPtr )
	: _fracPtr ( fracPtr )
{}
/****************************************************************/
FractionPointer::FractionPointer( FractionPointer& fracPtr )
	: _fracPtr ( fracPtr._fracPtr )
{
	fracPtr._fracPtr = 0;
}
/****************************************************************/
FractionPointer::FractionPointer( const FractionPointer& fracPtr )
	: _fracPtr ( fracPtr._fracPtr )
{}
/****************************************************************/
FractionPointer::~FractionPointer(){
	if( _fracPtr )
		delete _fracPtr;
}
/****************************************************************/
std::ostream& operator<<( std::ostream& out, FractionPointer& fracPtr ){
	if( !fracPtr._fracPtr )
		out << "[pointing to 0]";
	else	
		out << "[pointing to address=" << fracPtr._fracPtr << " value=" << fracPtr._fracPtr -> Numerator() << "/" << fracPtr._fracPtr -> Denominator() << "]";
	return out;
}
/****************************************************************/
FractionPointer& FractionPointer::operator=( FractionPointer& fracPtr ){
	if( this == &fracPtr )
		return *this;
	delete _fracPtr;
	_fracPtr = fracPtr._fracPtr;
	fracPtr._fracPtr = 0;
	return *this;
}
/****************************************************************/