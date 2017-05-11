#include "Number.h"
#include "OutOfRange.h"

int Number::bottom = 0;
int Number::top = 0;
std::vector <Number*> Number::pointers;

Number::Number(std::string name, float value)
	: _name (name)
	, _value (value)
{}
/***********************************************************/
Number* Number::Factory(std::string name, float value) {
	std::cout << "Manufacturing number " << value << std::endl;
	pointers.push_back(new Number(name, value));
	return pointers.back();
}
/***********************************************************/
void Number::SetRange(int val_bottom, int val_top) {
	bottom = val_bottom;
	top = val_top;
}
/***********************************************************/
void Number::Print() const {
	if (bottom < _value && _value < top)
		std::cout << _name << " = " << _value << std::endl;
	else
		throw OutOfRange(_value, _name);
}
/***********************************************************/
std::ostream& operator<<(std::ostream& out, const OutOfRange& object) {
	out << "Number named: " << object._name_of_object << " has value " << object._wrong_val << " which is outside of the allowed range: [" << Number::bottom << ", " << Number::top << "]";
	return out;
}
/***********************************************************/