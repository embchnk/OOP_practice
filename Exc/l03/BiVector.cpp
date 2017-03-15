#include "BiVector.h"

BiVector::BiVector()
	: _itrtr_f ( 0 )
	, _itrtr_b ( 0 )
{
	for( int i = 0; i < 20; ++i )
		_front[i] = _back[i] = 0;
}
/******************************************************************************/
BiVector& BiVector::push_back( int toAdd ){
	_back[ _itrtr_b ] = toAdd;
	_itrtr_b++;
	return *this;
}
/******************************************************************************/
BiVector& BiVector::push_front( int toAdd ){
	_front[ _itrtr_f ] = toAdd;
	_itrtr_f++;
	return *this;
}
/******************************************************************************/
BiVector::const_iterator BiVector::begin(){
	return const_iterator( this, 0 ) ;
}
/******************************************************************************/
BiVector::const_iterator BiVector::end(){
	return const_iterator( this, 1 );
}
/******************************************************************************/
int BiVector::operator[]( int index ){
	if( index < _itrtr_f ){
		return _front[ _itrtr_f - index - 1 ];
	}
	else if( _itrtr_f )
		return _back[ index - _itrtr_b ];
	return _back[ index ];
}
/******************************************************************************/
int BiVector::const_iterator::operator*(){
	if( i < _ptr -> _itrtr_f ){
		i++;
		return _ptr -> _front[ _ptr -> _itrtr_f - i  ];
	}
	else if( _ptr -> _itrtr_f ){
		i++;
		return _ptr -> _back[ i - _ptr -> _itrtr_b - 1 ];
	}
	i++;
	return _ptr -> _back[ i - 1 ];
}
/******************************************************************************/
BiVector::const_iterator& BiVector::const_iterator::operator=( const_iterator iter ){
	i = iter.i;
	_ptr = iter._ptr;
	return *this;
}
/******************************************************************************/
BiVector::const_iterator& BiVector::const_iterator::operator++(){
	i++;
	return *this;
}
/******************************************************************************/
BiVector::const_iterator::const_iterator( BiVector* ptr )
	: i ( 0 )
	, _ptr ( ptr )
{}
/******************************************************************************/
BiVector::const_iterator::const_iterator( BiVector* ptr, int integ )
	: i ( integ )
	, _ptr ( ptr )
{}
/******************************************************************************/
bool operator!=( BiVector::const_iterator temp, BiVector::const_iterator temp2 ){
	if( temp2.i == temp.i )
		return 1;
	return 0;
}
/******************************************************************************/


	
