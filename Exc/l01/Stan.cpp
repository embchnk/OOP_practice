#include <iostream>
#include <string.h>
#include "Stan.h"

Stan::Stan( const char * buffer )
	: next ( 0 )
{
	_data = new char [ strlen( buffer ) + 1 ];
	strcpy( _data, buffer );
}
/**************************************************************/
Stan Stan::operator()()
{
	std::cout << _data << std::endl;
	return *this;
}