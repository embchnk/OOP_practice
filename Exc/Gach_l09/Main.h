#ifndef MAIN_H
#define MAIN_H
#include <iostream>

class TestObject {
public:
	TestObject() 
		: _ID (0)
	{}
	TestObject(int ID) {
		_ID = ID; 
	}
	void Print() const {
		std::cout << "Object with ID=" << _ID << std::endl;
	}
	void Set(int new_ID) {
		_ID = new_ID;
	}
private:
	int _ID;
};

class Vector {
public: 
	template <typename T>
	static void Initialise(int size, T initializer = T(0)) {
		_table = new T[size];
		_size = size;
		for (int i = 0; i < size; ++i)
			((T*)_table)[i] = initializer;
	}
	template <typename T>
	static T& At(int index) {
		return ((T*)_table)[index];
	}
	template <typename T>
	static void Reset() {
		delete [] (T*)_table;
		_table = NULL;
		_size = 0;
	}
	static int Size() {
		return _size;
	}

	static void* _table;
	static int _size;
};

void* Vector::_table = NULL;
int Vector::_size = 0;

#endif // MAIN_H
