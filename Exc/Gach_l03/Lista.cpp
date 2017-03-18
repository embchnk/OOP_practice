#include <iostream>
#include "Lista.h"

Lista::Lista()
	: _head (0)
{}
/*******************************************************/
Lista::Lista(int* tableOfValues, int sizeOfTable) {
	node* temp = _head = new node(tableOfValues[0]);
	for (int i = 1; i < sizeOfTable; ++i) {
		temp -> addPointer(new node(tableOfValues[i]));
		temp = temp -> retPtr();
	}
}
/*******************************************************/
Lista::Lista(const Lista& element) {
	if (element._head == 0)
		_head = 0;
	else {
		_head = new node(element._head -> retVal());
		node* ptr_in_copy = _head;
		node* temp = element._head;
		while (temp -> retPtr()) {
			temp = temp -> retPtr();
			ptr_in_copy -> addPointer(new node(temp -> retVal()));
			ptr_in_copy = ptr_in_copy -> retPtr();
		}
	}
}
/*******************************************************/
Lista::~Lista(){}
/*******************************************************/
std::ostream& operator<<(std::ostream& out, Lista& lista) {
	node* temp = lista._head;
	while( temp -> retPtr() != 0 ){
		out << temp -> retVal() << " ";
		temp = temp -> retPtr();
	}
	out << temp -> retVal();
	return out;

}
/*******************************************************/
Lista operator+(Lista element, int toAdd) {
	if (element._head == 0) {
			element._head = new node(toAdd);
	}
	else {
		node* temp = element._head;
		while (temp -> retPtr()) {
			temp = temp -> retPtr();
		}
		node* ptr = new node(toAdd);
		temp -> addPointer(ptr);
	}
	return element;
}
/*******************************************************/
node& Lista::operator[](int index) {
	node* temp = _head;
	for (int i = 0; i < index; i++) 
		temp = temp -> retPtr();
	return *temp;
}
/*******************************************************/
node& Lista::operator+=(int toAssign) {
	node* temp = _head;
	while (temp -> retPtr())
		temp = temp -> retPtr();
	temp -> addPointer(new node(toAssign));
	return *temp;
}
/*******************************************************/
Lista operator+(Lista element1, Lista element2) {
	node* temp = element1.retHead();
	node* ptrOfElement = element2.retHead();
	do {
		temp = temp -> retPtr();
	} while (temp -> retPtr());
	do {
		temp -> addPointer(new node(ptrOfElement -> retVal()));
		temp = temp -> retPtr();
		ptrOfElement = ptrOfElement -> retPtr();
	} while (ptrOfElement);
	return element1;
}
/*******************************************************/
Lista::Iterator Lista::koniec() {
	int index = 0;
	node* temp = _head;
	do {
		temp = temp -> retPtr();
		index++;
	} while (temp -> retPtr());
	Lista::Iterator iterator(index, this);
	return iterator; 
}
/*******************************************************/
Lista::Iterator Lista::poczatek() {
	Lista::Iterator iterator(0, this);
	return iterator;
}
/*******************************************************/