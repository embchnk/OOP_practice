#include <iostream>
#include "Lista.h"

Lista::Lista()
	: _head ( 0 )
{}
/*******************************************************/
Lista::~Lista(){}

std::ostream& operator<<( std::ostream& out, Lista& lista ){
	node* temp = lista._head;
	while( temp -> retPtr() != 0 ){
		out << temp -> retVal() << " ";
		temp = temp -> retPtr();
	}
	out << temp -> retVal();
	return out;

}