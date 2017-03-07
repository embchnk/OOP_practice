#include <iostream>
#include <string.h>
#include "MaszynaStanow.h"

Stan * MaszynaStanow::actStan = 0;

MaszynaStanow::MaszynaStanow()
	: _ptr ( 0 )
{}
/**************************************************************/
MaszynaStanow MaszynaStanow::operator+=( Stan * pointer )
{
	if( !_ptr )
		_ptr = pointer;
	else
	{
		Stan * temp = _ptr;
		while( temp -> next != 0 )
			temp = temp -> next;
		temp -> next = pointer;
	}
	return *this;
}
/***************************************************************/
Stan MaszynaStanow::operator()()
{
	std::cout << "Wykonanie w stanie: ";
	return *actStan;
}
/***************************************************************/
void MaszynaStanow::start() const 
{
	actStan = _ptr;
}
/***************************************************************/
MaszynaStanow MaszynaStanow::operator++()
{
	if( actStan -> next != 0 )
		actStan = actStan -> next;
	return *this;
}
/***************************************************************/
std::ostream & operator<<( std::ostream& out, MaszynaStanow& m )
{
	int i = 0;
	Stan * temp = m._ptr;
	out << "MaszynaStanow:\n";
	while( temp != 0 )
	{
		if( temp -> _data == MaszynaStanow::actStan -> _data )
		{
			out << i++ << " " << temp -> _data << " <" << std::endl;
		}
		else
			out << i++ << " " << temp -> _data << std::endl;
		temp = temp -> next;
	}
	return out;
}
/**************************************************************/
MaszynaStanow MaszynaStanow::operator--()
{
	Stan * temp = _ptr;
	while( temp -> next != actStan )
		temp = temp -> next;
	actStan = temp;
	return *this;
}
/**************************************************************/
std::ostream & operator<<( std::ostream& out, const MaszynaStanow& m )
{
	int i = 0;
	Stan * temp = m._ptr;
	out << "MaszynaStanow:\n";
	while( temp != 0 )
	{
		if( temp -> _data == MaszynaStanow::actStan -> _data )
		{
			out << i++ << " " << temp -> _data << " <" << std::endl;
		}
		else
			out << i++ << " " << temp -> _data << std::endl;
		temp = temp -> next;
	}
	return out;
}