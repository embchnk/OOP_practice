#include <iostream>
#include "FractionPointer.h"

Fraction* FractionPointer::operator->()
{
	return _fracPtr; 
}
/****************************************************************/
FractionPointer::~FractionPointer()
{}
/****************************************************************/
FractionPointer::FractionPointer( Fraction* pointer )
	: _fracPtr ( pointer )
{}
/****************************************************************/
FractionPointer& FractionPointer::operator=( Fraction* frac )
{
	FractionPointer* temp = new FractionPointer( frac );
	return *temp;
}
/****************************************************************/
FractionPointer& FractionPointer::operator=( const FractionPointer& fracPtr )
{
	FractionPointer* temp = new FractionPointer( fracPtr._fracPtr );
	return *temp;
}
/****************************************************************/
FractionPointer& operator*=( FractionPointer& fracPtr, Fraction& frac )
{
	frac._counter *= fracPtr -> _counter;
	frac._denominator *= fracPtr -> _denominator;
	FractionPointer* tempPtr = new FractionPointer( &frac );
	return *tempPtr;
}
/****************************************************************/
FractionPointer FractionPointer::operator*( const FractionPointer& fracPtr )
{
	return fracPtr;
}
/****************************************************************/
Fraction& operator*( const FractionPointer& fracPtr )
{
	return *( fracPtr._fracPtr );
} 
/****************************************************************/
Fraction& operator*( FractionPointer& fracPtr1, FractionPointer& fracPtr2 )
{
	Fraction* temp = new Fraction( fracPtr1 -> _counter * fracPtr2 -> _counter, fracPtr1 -> _denominator * fracPtr2 -> _denominator );
	return *temp;
}
/****************************************************************/
Fraction* FractionPointer::operator->*( int* action )
{
	if( *action == 1 )
	{
		int i = 1;
		while( i <= _fracPtr -> _counter )
		{
			if( ( _fracPtr -> _counter / i ) * i == _fracPtr -> _counter && ( _fracPtr -> _denominator / i ) * i == _fracPtr -> _denominator )
			{	
			_fracPtr -> _counter = _fracPtr -> _counter / i;
			_fracPtr -> _denominator = _fracPtr -> _denominator / i;
			}
			i++;
		}
		return _fracPtr;
	}
}
/****************************************************************/