#ifndef MAIN_H
#define MAIN_H
#include <string>
#include <iostream>

class Object {
public:
	Object(std::string str)
		: name (str)
	{}
	void Print() const {
		std::cout << "Printing object named \""  << name << "\"." << std::endl;
	}
private:
	std::string name;
};

template <typename T>
class UniquePointer {
public:
	UniquePointer(T *ptr) {
		_pointer = ptr;
	}
	~UniquePointer() {
		delete _pointer;
	}
	UniquePointer(const UniquePointer<T>& object) 
	{
		_pointer = object._pointer;
		object._pointer = 0;
	}
	UniquePointer& operator=(const UniquePointer<T>& object) {
		if (this != &object) {
			if (_pointer)
				delete _pointer;
			_pointer = object._pointer;
			object._pointer = 0;
		}

		return *this;
	}
	template <typename T2>
	friend std::ostream& operator<<(std::ostream& out, const UniquePointer<T2>& object);
	T operator*() {
		return *_pointer;
	}
	operator T*() {
		return _pointer;
	}
	T* operator->() {
		return _pointer;
	}

	mutable T *_pointer;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const UniquePointer<T>& object) {
	out << "pointing to: " << object._pointer;

	return out;
}

#endif // MAIN_H
