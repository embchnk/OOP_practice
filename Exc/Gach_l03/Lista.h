#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "node.h"

class node;

class Lista
{
public:
	Lista();
	Lista(int*, int);
	Lista(const Lista&);
	~Lista();

	class Iterator
	{
	public:
		Iterator(int index, Lista* ptr)
			: _iterator (index)
			, _ptr (ptr)
		{}
		~Iterator() {}

		bool operator!=(Lista::Iterator iterator) {
			return _iterator != iterator._iterator;
		}
		Lista::Iterator operator++() {
			_iterator++;
			return *this;
		}
		int operator*() {
			node* temp = _ptr -> retHead();
			for (int i = 0; i < _iterator; ++i )
				temp = temp -> retPtr();
			return temp -> retVal();
		}

	private:
		int _iterator;
		Lista* _ptr;
	};

	Lista::Iterator koniec();
	Lista::Iterator poczatek();

	node* retHead() { return _head; }

	node& operator[](int);
	node& operator+=(int);

	friend Lista operator+(Lista, Lista);
	friend Lista operator+(Lista, int);
	friend std::ostream& operator<<(std::ostream&, Lista&);

private:
	node* _head;
};



#endif // LISTA_H
