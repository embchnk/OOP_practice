#ifndef Lab10_h
#define Lab10_h
#include <vector>
#include <iostream>

class VariableBase {
public:
	VariableBase() {}
	virtual ~VariableBase() {}
	virtual void Print() const =0;
};

template <typename T>
class Variable: public VariableBase {
public:
	Variable(const char* name, T value)
		: VariableBase()
		, _name (name)
		, _value (value)
	{}

	void Print() const {
		std::cout << _name << ": " << _value << std::endl;
	}

	void SetValue(T value) {
		_value = value;
	}

protected:
	const char* _name;
	T _value;
};

template <typename T>
class VariableWithUnits: public Variable<T> {
public:
	VariableWithUnits(const char* name, T value, const char* unit)
		: Variable<T> (name, value)
		, _unit (unit)
	{}

	void Print() const {
		std::cout << Variable<T>::_name << ": " << this -> _value << " [" << _unit <<"]" << std::endl; 
	}
private:
	const char* _unit;
};

class ArrayOfVariables {
public:
	ArrayOfVariables(unsigned int size)
		: _max (size) 
	{}

	~ArrayOfVariables() {
		for (unsigned int i = 0; i < _array.size(); ++i)
			delete _array[i];
	}

	template <typename T>
	Variable<T>* CreateAndAdd(const char* name, T value) {
		if (_array.size() <= _max )
			_array.push_back(new Variable<T>(name, value));
		return dynamic_cast<Variable<T>*>(_array[_array.size() - 1]);
	}

	void Print() const {
		for (unsigned int i = 0; i < _array.size(); ++i)
			_array[i] -> Print();
	}
private:
	unsigned int _max;
	std::vector <VariableBase*> _array;
};


typedef Variable<int> VariableInt;
typedef Variable<float> VariableFloat;
typedef Variable<bool> VariableBool;
typedef Variable<char> VariableChar;
typedef Variable<double> VariableDouble;

#endif // Lab10_h