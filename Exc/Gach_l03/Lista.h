#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "node.h"

class node;

class Lista
{
public:
	Lista();
	~Lista();

	Lista& operator+( int toAdd ){
		if( _head == 0 ){
			_head = new node( toAdd );
		}
		else{
			node* temp = _head;
			while( temp -> retPtr() != 0 ){
				temp = temp -> retPtr();
			}
			node* ptr = new node( toAdd );
			temp -> addPointer( ptr );
		}
		return *this;
	}

	friend std::ostream& operator<<( std::ostream&, Lista& );

private:
	node* _head;
};



#endif // LISTA_H
