#ifndef ARRAY_H
#define ARRAY_H
#include <vector>
#include <iostream>
#include <stdexcept>
#include "X.h"

template <int T, typename U>
class Array {
public:
	Array()
		: _size (T) 
	{
		_array.resize(T);
	}
	U& operator[](int index) {
		if (index < _size)
			return _array[index];
		else 
			throw std::invalid_argument("Indeks poza zakresem");
	}
	int retSize() const {
		return _size;
	}
	template <int T2, typename U2>
	friend std::ostream& operator<<(std::ostream& out, Array<T2, U2>& object);
private:
	int _size;
	std::vector<U> _array;
};

template <int T, typename U>
std::ostream& operator<<(std::ostream& out, Array<T, U>& object) {
	for (int i = 0; i < object.retSize(); ++i) {
		out << object[i] << " "; 
	}  

	return out;
}

template <int T>
class Array<T, X*> {
public:
	Array()
		: _size (T) 
	{
		_array.resize(T);
	}
	~Array() {
		for (int i = 0; i < _size; ++i) {
			if (_array[i] != 0)
				delete _array[i];
	} 
	}
	X*& operator[](int index) {
		if (index < _size)
			return _array[index];
		else 
			throw std::invalid_argument("Indeks poza zakresem");
	}
	int retSize() const {
		return _size;
	}
	template <int T2>
	friend std::ostream& operator<<(std::ostream& out, Array<T2, X*>& object);
private:
	int _size;
	std::vector<X*> _array;
};

template <int T>
std::ostream& operator<<(std::ostream& out, Array<T, X*>& object) {
	for (int i = 0; i < object.retSize(); ++i) {
		if (object[i] != 0)
			out << object[i] -> retData() << " "; 
	}  

	return out;
}

template <int T>
class Array<T, X> {
public:
	Array()
		: _size (T) 
	{
		_array.resize(T);
	}
	X& operator[](int index) {
		if (index < _size)
			return _array[index];
		else 
			throw std::invalid_argument("Indeks poza zakresem");
	}
	int retSize() const {
		return _size;
	}
	template <int T2>
	friend std::ostream& operator<<(std::ostream& out, Array<T2, X>& object);
private:
	int _size;
	std::vector<X> _array;
};

template <int T>
std::ostream& operator<<(std::ostream& out, Array<T, X>& object) {
	for (int i = 0; i < object.retSize(); ++i) {
		out << object[i].retData() << " "; 
	}  

	return out;
}

#endif // ARRAY_H
