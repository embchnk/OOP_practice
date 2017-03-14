#include <iostream>
#include "IntSequence.h"

IntSequence::IntSequence()
	: _current ( 0 )
	, _counter ( 0 )
{}
/******************************************************************/
IntSequence::~IntSequence()
{
	delete [] _sequence;
}
/******************************************************************/
IntSequence& IntSequence::operator<<( int toAdd )
{
	if( _counter == 0 )
	{
		_sequence = new int[1];
		_sequence[0] = toAdd;
		_counter++;
		return *this;
	}
	int i;
	int temp[ _counter + 1 ];
	for( i = 0; i < _counter; i++ )
	{
		temp[i] = _sequence[i];
	}
	temp[ _counter ] = toAdd;
	delete [] _sequence;
	_sequence = new int [ _counter + 1 ];
	for( i = 0; i < _counter + 1; i++ )
	{
		_sequence[i] = temp[i];
	}
	_counter++;
	return *this;
}
/******************************************************************/
int IntSequence::operator()()
{
	return _sequence[ _current ];
}
/******************************************************************/
int IntSequence::operator++( int )
{
	_current++;
	if( _current == _counter )
		_current = 0;
	return _sequence[ _current ];
}
/******************************************************************/
int IntSequence::operator--( int )
{
	if( _current > 0 )
		_current--;
	else
		_current = _counter - 1;
	return _sequence[ _current ];
}
/******************************************************************/
void IntSequence::operator=( int& integer ) const
{
	integer = _sequence[ _current ];
}
/******************************************************************/
IntSequence::operator int() const
{
	return _sequence[ _current ];
}
/******************************************************************/
void IntSequence::reset()
{
	_current = 0;
}
/******************************************************************/
void* IntSequence::operator new( std::size_t size ){
	return ::operator new( size );
}
/******************************************************************/