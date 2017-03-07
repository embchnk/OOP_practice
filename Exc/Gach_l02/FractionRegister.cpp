#include "FractionRegister.h"

Fraction** FractionRegister::_fracRegPtr = new Fraction* [1];
int FractionRegister::_counter = 0;
FractionRegister* FractionRegister::_regPtr = 0;

FractionRegister::FractionRegister(){
	_regPtr = this;
}
/*******************************************************************/
std::ostream& operator<<( std::ostream& out, FractionRegister& fracReg ){
	for( int i = 0; i < fracReg._counter; i++ )
		out << fracReg._fracRegPtr[i] << " ";
	return out;
}
/*******************************************************************/
FractionRegister& FractionRegister::operator<<( Fraction& frac ){
	if( _counter == 0 ){
		_fracRegPtr = new Fraction* [1];
		_fracRegPtr[0] = &frac;
		_counter++;
		return *this;
	}
	Fraction* temp[ _counter ];
	for( int i = 0; i < _counter; i++ )
		temp[i] = _fracRegPtr[i];
	delete [] _fracRegPtr;
	_fracRegPtr = new Fraction* [ _counter + 1 ];
	for( int i = 0; i < _counter; i++ )
		_fracRegPtr[i] = temp[i];
	_fracRegPtr[ _counter ] = &frac;
	_counter++;
	return *this;
}
/*******************************************************************/
FractionRegister& FractionRegister::operator<<( FractionPointer& fracPtr ){
	if( _counter == 0 ){
		_fracRegPtr = new Fraction* [1];
		_fracRegPtr[0] = fracPtr.retPtr();
		_counter++;
		return *this;
	}
	Fraction* temp[ _counter ];
	for( int i = 0; i < _counter; i++ )
		temp[i] = _fracRegPtr[i];
	delete [] _fracRegPtr;
	_fracRegPtr = new Fraction* [ _counter + 1 ];
	for( int i = 0; i < _counter; i++ )
		_fracRegPtr[i] = temp[i];
	_fracRegPtr[ _counter ] = fracPtr.retPtr();
	_counter++;
	return *this;
}
/*******************************************************************/
