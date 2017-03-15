#include <iostream>
#include "node.h"

node::node()
	: _next ( 0 )
	, _value ( 0 )
{}
/*******************************************************/
node::node( int toAdd )
	: _next ( 0 )
	, _value ( toAdd )
{
	std::cout << "Uruchomiono kostruktor dla wartości: " << toAdd << " " << _value << std::endl; 
}
/*******************************************************/
node::~node(){

}
/*******************************************************/
void node::addPointer( node* ptr ){
	std::cout << "Pobrano pointer: " << ptr << std::endl;
	_next = ptr;
}
/*******************************************************/