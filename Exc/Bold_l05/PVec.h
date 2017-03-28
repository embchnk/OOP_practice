#ifndef PVec_h
#define PVec_h
#include <vector>
#include <string.h>




class StringWrapper {
public:
	StringWrapper(std::string value)
		: _value (value)
	{}
	std::ostream& print(std::ostream& out) {
		out << _value;
		return out;
	}
	std::string retVal() { return _value; }
protected:
	std::string _value;
};

class PVec {
public:
	PVec& push_back(StringWrapper* wrapper) {
		_table.push_back(wrapper);
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, PVec vec) {
		for (int i = 0; i < int(vec._table.size()); ++i) {
			out << vec._table[i] -> retVal() << " ";
		}
		return out;
	}

	PVec& operator<<(StringWrapper* wrapper) {
		_table.push_back(wrapper);
		return *this;
	}

	StringWrapper& operator[](int index) {
		return *(_table[index]);
	}
private:
	std::vector< StringWrapper* > _table;
};

class IntWrapper: public StringWrapper {
public:
	IntWrapper(int value)
		: StringWrapper(std::to_string(value))
	{}
};

class FloatWrapper: public StringWrapper {
public:
	FloatWrapper(float value)
		: StringWrapper(std::to_string(value))
	{}
};

#endif // PVec_h
