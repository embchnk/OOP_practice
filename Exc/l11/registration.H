#ifndef registration_H
#define registration_H
#include <string>
#define DECLARE_TYPE_IDENTIFIER(name, val) template<> struct int2type<val> { typedef name type; }; template<> struct type2int<name> { static int value; }; int type2int<name>::value = val;

template <int T>
class int2type {
public:
	static int2type type;
};

template <typename T>
class type2int {
public:
	static int value;
};


#endif // registration_H